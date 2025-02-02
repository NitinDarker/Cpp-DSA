#include <iostream>
using namespace std;

int pow(int num, int pow)
{ // Function to calculate power of a number
     int ans = 1;
     for (int i = 1; i <= pow; i++)
     {
          ans *= num;
     }
     return ans;
} // Equivalent to pow() function <cmath> header file

int bin_deci(int bin)
{ // Binary to decimal convertor function
     int dig, deci = 0;
     for (int i = 0; bin > 0; i++)
     {
          dig = bin % 10; // Extracting the unit digit
          deci += dig * pow(2, i);
          bin /= 10; // Moving to next digit
     }
     return deci;
}

int deci_bin(int deci)
{ // Decimal to Binary convertor function
     int rem, bin = 0;
     for (int i = 0; deci > 0; i++)
     {
          rem = deci % 2; // Extracting the remainder after div by 2
          deci /= 2;      // Dividing by 2
          bin += rem * pow(10, i);
     }
     return bin;
}

int main()
{
     cout << bin_deci(1011) << endl;
     cout << deci_bin(4) << endl;
     return 0;
}