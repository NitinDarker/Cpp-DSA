// 0-1 Triangle Pattern
#include <iostream>
using namespace std;

int main(){
     int n = 5;
     bool val = 1;
     for(int i=0; i<n; i++){
          for(int j=0; j<=i; j++){
               if(i%2==0){
                    cout << val;
                    val = !val;
               }
               else{
                    val = !val;
                    cout << val;
               }
          }
          cout << "\n";
          val = 1;
     }
     return 0;
}
               // if(i%2==0){
               //      if(j%2==0){
               //           cout << '1';
               //      }
               //      else{
               //           cout << '0';
               //      }
               // }
               // else{
               //      if(j%2==0){
               //           cout << '0';
               //      }
               //      else{
               //           cout << '1';
               //      }
               // }