#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Nitin Sharma is a genius";
    int vowels[5] = {0};

    for (char ch : str) {
        switch (ch) {
        case 'a':
            vowels[0]++;
            break;
        case 'e':
            vowels[1]++;
            break;
        case 'i':
            vowels[2]++;
            break;
        case 'o':
            vowels[3]++;
            break;
        case 'u':
            vowels[4]++;
            break;
        }
    }
    cout << "a e i o u " << endl;
    for (int i : vowels) {
        cout << i << " ";
    }
    return 0;
}