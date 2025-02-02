#include <iostream>
using namespace std;

bool isPrime(int num)
{ // Function to check if a num is prime or not
     for (int i = 2; i * i <= num; i++)
     { // Every number is divisible by 1 hence starting from 2
          if (num % i == 0)
          { // If num is divisible by any i other than 1 and itself then return false
               return false;
          }
     }
     return true;
     // If num is only divisible by 1 and itself then return true
}

void allPrime(int n)
{ // Function to print all prime numbers till n
     for (int i = 2; i <= n; i++)
     {
          if (isPrime(i))
               cout << i << " ";
     }
}

int main()
{
     allPrime(100);
     return 0;
}