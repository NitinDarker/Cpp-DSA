#include <iostream>
using namespace std;

int main() {

    cout << "Input a string (only lowercase): ";
    string str;
    cin >> str;

    int hash[26] = {0};

    for (int i=0; i<str.size(); i++) {
        hash[str[i] - 'a']++;
    }
    cout << "Input the number of queries" << endl;
    int q;
    cin >> q;

    for (int i=0; i<q; i++) {
        cout << "Frequency of which char is to be found: ";
        char ch;
        cin >> ch;
        int ind = ch - 'a';
        cout << "Frequency: " << hash[ind] << endl;
    }
    return 0;
}