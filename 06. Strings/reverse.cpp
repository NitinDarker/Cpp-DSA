#include <iostream>
#include <string>
using namespace std;

string reverse(string str) {  // It takes string type as an argument (Pass by by value)
    int s = 0;                // Start pointer
    int e = str.length() - 1; // End pointer

    while (s < e) {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str; // Return the reversed string
} // Using Two pointer approach -> O(n)

int main() {
    string s = "apple";
    cout << reverse(s) << endl;
    return 0;
}