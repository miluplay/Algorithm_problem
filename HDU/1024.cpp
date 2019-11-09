#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int imax = 1000010;
int arr[imax], dp[imax], pre[imax];
int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    int sum;
    for (int i = 1; i <= m; i++) {
      sum = -INF;
      for (int j = i; j <= n; j++) {
        dp[j] = max(dp[j - 1], pre[j - 1]) + arr[j];
        pre[j - 1] = sum;
        sum = max(sum, dp[j]);
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
