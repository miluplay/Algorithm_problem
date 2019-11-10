#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int imax = 10010;
const int INF = 0x3f3f3f3f;
int dp[imax], weight, value;
int main() {
  int T, e, f, n, v;
  for (cin >> T; T--;) {
    cin >> e >> f;
    v = f - e;
    memset(dp, INF, sizeof(dp));
    for (cin >> n; n--;) {
      cin >> value >> weight;
      dp[weight] = min(dp[weight], value);
      for (int j = weight; j <= v; j++)
        dp[j] = min(dp[j], dp[j - weight] + value);
    }
    if (dp[f - e] != INF)
      cout << "The minimum amount of money in the piggy-bank is " << dp[f - e]
           << "." << endl;
    else
      cout << "This is impossible." << endl;
  }
}