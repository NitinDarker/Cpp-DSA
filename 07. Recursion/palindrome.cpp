#include <iostream>
using namespace std;

bool isPal(string &s, int i) {
    int n = s.length();
    if (i >= n / 2) {
        return true;
    }
    if (s[i] != s[n - i - 1]) {
        return false;
    }
    return isPal(s, i + 1);
}

int main() {
    string s = "nitin";
    cout << "isPal: " << isPal(s, 0) << endl;
    return 0;
}