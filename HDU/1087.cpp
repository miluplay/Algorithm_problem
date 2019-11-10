#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int imax = 1111;
int dp[imax], arr[imax];
int main() {
  int n;
  while (cin >> n && n != 0) {
    for (int i = 0; i < n; i++) cin >> arr[i];
    int maxn = 0;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = arr[i];
      int temp = 0;
      for (int j = i; j < n; j++)
        if (arr[j] > arr[i]) temp = max(dp[j], temp);
      dp[i] += temp;
      maxn = max(maxn, dp[i]);
    }
    cout << maxn << endl;
  }
}