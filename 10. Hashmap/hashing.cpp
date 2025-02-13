// Write a program in C++ to implement the Hash Table using array. Design the ADT for hash table and implement.
#include <iostream>
using namespace std;

// Implement Hashing for frequency of alphabets (only lowercase) in a string
class Hash {
  private:
    // Initialising all the elements in hashArray to 0
    int hashArray[26] = {0};
    // For hashing of only lowercase -> size of hashArray = 26
    // For hashing of all characters -> size of hashArray = 256

  public:
    void createHashTable(string str);
    int getFrequency(char ch);
};

void Hash::createHashTable(string str) {
    for (int i = 0; i < str.size(); i++) {
        // Assigning keys for a=0, b=1, c=2, and so on...
        int index = str[i] - 'a';

        hashArray[index]++;
    }
}

int Hash::getFrequency(char ch) {
    int index = ch - 'a';
    return hashArray[index];
}

int main() {

    cout << "Input a string (only lowercase): ";
    string str;
    cin >> str;

    Hash h;
    h.createHashTable(str);

    cout << "Frequency of which char is to be found: ";
    char ch;
    cin >> ch;
    cout << h.getFrequency(ch) << endl;

    return 0;
}