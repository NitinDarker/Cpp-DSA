#include <iostream>
using namespace std;

class complex {
  public:
    int real;
    int imag;

    complex(int real, int imag) {
        this->real = real;
        this->imag = imag;
    }

    // Operator overloading
    complex operator-(complex c2) {
        int r = this->real - c2.real;
        int i = this->imag - c2.imag;
        complex ans(r, i);
        return ans;
    }

    void getComplex() {
        cout << real << " + " << imag << "i " << endl;
    }
};

int main() {
    complex c1(8, 6);
    complex c2(1, 3);
    complex c3 = c1 - c2;
    c1.getComplex();
    c2.getComplex();
    c3.getComplex();
    return 0;
}