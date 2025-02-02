#include <iostream>
using namespace std;

int reverse(int num) {
     int originalNum = num;
     int reversedNum = 0;

     while (num != 0) {
          int digit = num % 10;
          reversedNum = (reversedNum * 10) + digit; // THIS LINE IS SUPER IMPORTANT
          num /= 10;
     }
     return reversedNum;
}

int main() {
     int num;
     cout << "Input a number to reverse: " << endl;
     cin >> num;

     cout << "Reversed number:\n"
          << reverse(num) << endl;

     return 0;
}