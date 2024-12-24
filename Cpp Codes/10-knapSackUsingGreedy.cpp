#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  float capacity, Totalvalue = 0;

  cout << "Enter the number of items: ";
  cin >> n;

  vector<float> weight(n), profit(n), ratio(n);

  for (int i = 0; i < n; i++) {
    cout << "Enter Weight and Profit for item[" << i << "]: ";
    cin >> weight[i] >> profit[i];
    ratio[i] = profit[i] / weight[i];
  }

  cout << "Enter the capacity of knapsack: ";
  cin >> capacity;

  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 0);
  sort(ratio.begin(), ratio.end(), [&](int i, int j) { return ratio[i] > ratio[j]; });
  sort(weight.begin(), weight.end(), [&](int i, int j) { return ratio[i] > ratio[j]; });
  sort(profit.begin(), profit.end(), [&](int i, int j) { return ratio[i] > ratio[j]; });

  for (int i : indices) {
    if (weight[i] > capacity)
      break;
    Totalvalue += profit[i];
    capacity -= weight[i];
  }

  if (capacity > 0 && !indices.empty())
    Totalvalue += ratio[indices.back()] * capacity;

  cout << "\nThe maximum value is: " << Totalvalue << endl;

  return 0;
}
