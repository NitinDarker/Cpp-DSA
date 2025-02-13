#include <iostream>
#include <cstdlib>
using namespace std;

class bankAccount {
  private:
    float balance;
    int accountNum;
    string password;

  public:
    string name;
    int customerID;

    bankAccount() {
        cout << "Account Successfully created! " << endl;
        customerID = rand() % 6;
    }
};

int main() {

    return 0;
}