// Rhombus Pattern
#include <iostream>
using namespace std;

int main(){
     int n =5;
     for(int i=n; i>0; i--){
          for(int j=1; j<i; j++){
               cout << " ";
          }
          for(int j=0; j<n; j++){
               cout << "*";
          }
          cout << endl;
     }
     return 0;
}