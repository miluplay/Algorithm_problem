#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int imax = 1000010;
struct vj {
  int x;
  int y;
  int z;
} dp[imax];
void MyPush(int t, int a, int b, int c) {
  dp[t].x = min(a, b);
  dp[t].y = max(a, b);
  dp[t].z = c;
}
bool cmp(vj a, vj b) { return a.x * a.y < b.x * b.y; }
int main() {
  int n, a, b, c, intt = 1;
  while (cin >> n && n) {
    int top = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a >> b >> c;
      MyPush(top++, a, b, c);
      MyPush(top++, a, c, b);
      MyPush(top++, c, b, a);
    }
    sort(dp + 1, dp + top, cmp);
    int maxn = dp[top - 1].z;
    for (int i = top - 1; i > 0; i--) {
      int tmp = 0;
      for (int j = i + 1; j < top; j++)
        if (dp[i].x < dp[j].x && dp[i].y < dp[j].y) tmp = max(tmp, dp[j].z);
      dp[i].z += tmp;
      maxn = max(maxn, dp[i].z);
    }
    cout << "Case " << intt++ << ": maximum height = " << maxn << endl;
  }
  return 0;
}
