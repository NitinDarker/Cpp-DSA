// Diamond pattern
#include <iostream>
using namespace std;

int main(){
     int n = 5;
     for(int i=0; i<n; i++){
          for(int j=0; j<n-i-1; j++){
               cout << ' ';
          }
          for(int j=0; j<(2*i+1); j++){
               cout << '*';
          }
          cout << endl;
     }
     for(int i=n; i>0; i--){
          for(int j=n-i; j>0; j--){
               cout << ' ';
          }
          for(int j=(2*i-1); j>0; j--){
               cout << '*';
          }
          cout << endl;
     }
     return 0;
}