#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<int> visited;
int n, cost = 0;

void get() {
    cout << "Enter the number of cities: ";
    cin >> n;

    a.resize(n, vector<int>(n));
    visited.resize(n, 0);

    cout << "\nEnter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter elements of row " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nThe cost matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

int least(int currentCity) {
    int minCost = 999, nextCity = 999;

    for (int i = 0; i < n; i++) {
        if (a[currentCity][i] != 0 && !visited[i]) {
            if (a[currentCity][i] < minCost) {
                minCost = a[currentCity][i];
                nextCity = i;
            }
        }
    }

    if (minCost != 999) {
        cost += minCost;
    }
    return nextCity;
}

void mincost(int city) {
    visited[city] = 1;
    cout << city + 1 << " -> ";

    int nextCity = least(city);
    if (nextCity == 999) {
        nextCity = 0;
        cout << nextCity + 1;
        cost += a[city][nextCity];
        return;
    }
    mincost(nextCity);
}

int main() {
    get();
    cout << "\nThe path is: \n\n";
    mincost(0);
    cout << "\n\nMinimum cost: " << cost << "\n";
    return 0;
}


// output:
// Enter the number of cities: 6

// Enter the cost matrix:
// Enter elements of row 1:
// 99 10 15 20 99  8 
// Enter elements of row 2:
// 5 99 9 10 8 99
// Enter elements of row 3:
// 6 13 99 12 99 5
// Enter elements of row 4:
// 8 8 9 99 6 99
// Enter elements of row 5:
// 99 10 99 6 99 99
// Enter elements of row 6:
// 10 99 5 99 99 99

// The cost matrix is:
// 99      10      15      20      99      8
// 5       99      9       10      8       99
// 6       13      99      12      99      5
// 8       8       9       99      6       99
// 99      10      99      6       99      99
// 10      99      5       99      99      99

// The path is:

// 1 -> 6 -> 3 -> 4 -> 5 -> 2 -> 1

// Minimum cost: 46