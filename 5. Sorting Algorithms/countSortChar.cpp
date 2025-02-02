// Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string countSort(string str) {
    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }
    for (char ch : str) {
        int num = ch - 'a';
        arr[num]++;
    }
    string ans = "";
    int i = 0;
    while (i < 26) {
        if (arr[i] == 0) {
            i++;
        } else {
            char ch = i + 'a';
            ans += ch;
            arr[i]--;
        }
    }
    return ans;
}

int main() {
    string str = "nitin";
    cout << countSort(str) << endl;
    return 0;
}