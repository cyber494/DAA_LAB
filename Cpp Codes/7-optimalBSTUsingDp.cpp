#include <bits/stdc++.h>
using namespace std;

int optCost(const vector<int>& freq, int i, int j) {
    if (j < i) {
        return 0;
    }
    if (j == i) {
        return freq[i];
    }
    int fsum = accumulate(freq.begin() + i, freq.begin() + j + 1, 0);
    int min = INT_MAX;
    for (int r = i; r <= j; r++) {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min) {
            min = cost;
        }
    }
    return fsum + min;
}

int main() {
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    int n = keys.size();
    cout << "Cost of Optimal BST is " << optCost(freq, 0, n - 1) << endl;
    return 0;
}
