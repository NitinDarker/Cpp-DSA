#include <iostream>
using namespace std;

void strupr(char *word) {

    for (int i = 0; word[i] != '\0'; i++) {
        if ((int)word[i] > 96) {
            word[i] = word[i] - 32;
        }
    }
}

void strlwr(char *word) {

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
}

int main() {
    char word[50];
    cout << "Input a word: " << endl;
    cin.getline(word, 50);

    // strupr(word);
    strlwr(word);
    cout << word << endl;
    return 0;
}