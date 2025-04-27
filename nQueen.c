#include <stdint.h>
#include <stdio.h>
#include <windows.h>

#define MAX_N 32
#define MAX_THREADS (MAX_N / 2 + 1)


typedef struct {
    int row, ld, rd, depth;
} StackFrame;

typedef struct {
    int n;
    int first_col;
    long long count;
} ThreadArgs;

DWORD WINAPI nQueensStackSolver(LPVOID param) {
    ThreadArgs *args = (ThreadArgs *)param;
    int n = args->n;
    uint32_t full = (1U << n) - 1;
    uint32_t p = 1U << args->first_col;

    StackFrame stack[64];
    int top = 0;
    stack[top++] = (StackFrame){p, p << 1, p >> 1, 1};

    long long local_count = 0;

    while (top > 0) {
        StackFrame f = stack[--top];

        if (f.depth == n) {
            local_count++;
            continue;
        }

        uint32_t possible = full & ~(f.row | f.ld | f.rd);
        while (possible) {
            uint32_t bit = possible & -possible;
            possible -= bit;
            stack[top++] = (StackFrame){
                f.row | bit,
                (f.ld | bit) << 1,
                (f.rd | bit) >> 1,
                f.depth + 1};
        }
    }

    args->count = local_count;
    return 0;
}

int main() {
    int n;
    printf("Enter the value of n (1-%d): ", MAX_N);
    scanf("%d", &n);

    if (n < 1 || n > MAX_N) {
        printf("Unsupported n value.\n");
        return 1;
    }

    ThreadArgs args[MAX_THREADS];
    HANDLE threads[MAX_THREADS];
    int thread_count = 0;

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    for (int i = 0; i < n / 2; ++i) {
        args[i].n = n;
        args[i].first_col = i;
        args[i].count = 0;

        threads[i] = CreateThread(NULL, 0, nQueensStackSolver, &args[i], 0, NULL);
        thread_count++;
    }

    long long center_count = 0;
    if (n % 2) {
        uint32_t p = 1U << (n / 2);
        StackFrame stack[64];
        int top = 0;
        stack[top++] = (StackFrame){p, p << 1, p >> 1, 1};

        while (top > 0) {
            StackFrame f = stack[--top];
            if (f.depth == n) {
                center_count++;
                continue;
            }

            uint32_t possible = ((1U << n) - 1) & ~(f.row | f.ld | f.rd);
            while (possible) {
                uint32_t bit = possible & -possible;
                possible -= bit;
                stack[top++] = (StackFrame){
                    f.row | bit,
                    (f.ld | bit) << 1,
                    (f.rd | bit) >> 1,
                    f.depth + 1};
            }
        }
    }

    WaitForMultipleObjects(thread_count, threads, TRUE, INFINITE);

    long long total = 0;
    for (int i = 0; i < thread_count; ++i) {
        total += args[i].count;
        CloseHandle(threads[i]);
    }

    total = total * 2 + center_count;

    QueryPerformanceCounter(&end);
    double ms = (end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;

    printf("Execution time: %.3f ms\n", ms);
    printf("Number of solutions: %lld\n", total);

    return 0;
}
