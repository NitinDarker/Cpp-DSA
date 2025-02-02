#include <iostream>
#include <climits>
using namespace std;

// int BuySellStocks(int *arr, int size){
//      int CurrProfit, NetProfit = 0; 
//      for(int i=0; i<size; i++){
//           for(int j=i+1; j<size; j++){
//                CurrProfit = arr[j] - arr[i];
//                NetProfit = max(CurrProfit, NetProfit);
//           }
//      }
//      if(NetProfit < 0)
//           NetProfit = 0;
//      return NetProfit;
//      // It return the maximum profit that you can get 
// }// Time Complexity -> O(n^2)

int BuySellStocks(int *arr, int size){
     int buyArr[10];
     buyArr[0] = INT_MAX;
     int maxProfit = 0;

     for(int i=1; i<size; i++){
          buyArr[i] = min(buyArr[i-1], arr[i-1]);
          maxProfit = max(maxProfit, (arr[i] - buyArr[i]));
     }
     return maxProfit;
}// Time Complexity -> O(n)

int main(){
     int prices[] = {7,6,5,4,3,2,1};
     // Stock prices at each day
     int size = sizeof(prices) / sizeof(int);

     cout << "Max Profit: " << BuySellStocks(prices, size) << endl;
}