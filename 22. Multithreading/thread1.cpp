#include <iostream>
#include <thread>
using namespace std;

void say_hello() {
    for (int i = 0; i < 10; i++) {
        cout << "1-thread " << endl;
    }
}

void say_bye() {
    for (int i = 0; i < 10; i++) {
        cout << "2-thread " << endl;
    }
}

int main() {
    thread t(say_hello);
    thread a(say_bye);
    for (int i = 0; i < 10; i++) {
        cout << "0-main " << endl;
    }
    t.join();
    a.join();
    return 0;
}
