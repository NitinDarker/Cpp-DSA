#include <iostream>
using namespace std;

int fact(int n)
{ // Function to calculate factorial of number n
     if (n < 2)
     {              // (1!) = 1
          return 1; // End condition of recursion
     }
     return n * fact(n - 1); // Recursive call of fact function
}

int binomialCoeff(int n, int r)
{ // Function to calculate binomial coefficient -> nCr
     return (fact(n)) / (fact(r) * fact(n - r));
}

int main()
{
     int n, r;
     cout << "Input the values of n: ";
     cin >> n;
     cout << "Input the values of r: ";
     cin >> r;
     cout << "C(n,r) = " << binomialCoeff(n, r) << endl;
     return 0;
}