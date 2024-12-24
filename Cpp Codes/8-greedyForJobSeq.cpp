#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> x,vector<int> y) {
    return x[1] < y[1];
}
int main(){
    vector<vector<int>> arr = {
        {1, 2,  60},
        {2, 1, 100},
        {3, 3,  20},
        {4, 2,  40},
        {5, 1,  20},
    };
    sort(arr.begin(),arr.end(),comp);
    int n = arr.size();
    vector<int> result(n, -1);
   vector<bool> slot(n,false);
    int maxProfit = 0;
   for (int i = 0; i < n; i++) {
      for (int j = min(n, arr[i][1]) - 1; j >= 0; j--) {
         if (slot[j] == false) {
            result[j] = i;
            maxProfit += arr[i][2];
            slot[j] = true;
            break;
         }
      }
   }

   for (int i = 0; i < n; i++)
      if (slot[i]){
        cout<< arr[result[i]][0]<<" ";
    
    }
}