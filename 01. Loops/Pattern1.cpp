// Character Half Pyramid Pattern
#include <iostream>
using namespace std;

int main() {
    char ch = 'A';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ch++;
        }
        cout << endl;
    }
    return 0;
}