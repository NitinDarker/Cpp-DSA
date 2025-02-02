#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    int alpha[26] = {0};

    for (char ch : s1) {
        alpha[ch - 'a']++;
    }
    for (char ch : s2) {
        alpha[ch - 'a']--;
    }
    for (int ch : alpha) {
        if (ch != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "nitin";
    string s2 = "ntint";
    cout << isAnagram(s1, s2) << endl;
    return 0;
}