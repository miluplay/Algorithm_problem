#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int imax = 1000010;
int arr[imax];
int main() {
  int n, t;
  while (scanf("%d", &n) != EOF) {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      arr[t]++;
      if (arr[t] >= (n + 1) / 2) {
        printf("%d\n", t);
        arr[t] = -INF;
      }
    }
  }
  return 0;
}
