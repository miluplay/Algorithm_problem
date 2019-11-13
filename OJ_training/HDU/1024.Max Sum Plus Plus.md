# Max Sum Plus Plus
### Problem Description:
Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.

Given a consecutive number sequence S<sub>1</sub>, S<sub>2</sub>, S<sub>3</sub>, S<sub>4</sub> ... S<sub>x</sub>, ... S<sub>n</sub> (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ S<sub>x</sub> ≤ 32767). We define a function sum(i, j) = S<sub>i</sub> + ... + S<sub>j</sub> (1 ≤ i ≤ j ≤ n).

Now given an integer m (m > 0), your task is to find m pairs of i and j which make sum(i<sub>1</sub>, j<sub>1</sub>) + sum(i<sub>2</sub>, j<sub>2</sub>) + sum(i<sub>3</sub>, j<sub>3</sub>) + ... + sum(i<sub>m</sub>, j<sub>m</sub>) maximal (i<sub>x</sub> ≤ i<sub>y</sub> ≤ j<sub>x</sub> or i<sub>x</sub> ≤ j<sub>y</sub> ≤ j<sub>x</sub> is not allowed).

But I`m lazy, I don't want to write a special-judge module, so you don't have to output m pairs of i and j, just output the maximal summation of sum(i<sub>x</sub>, j<sub>x</sub>)(1 ≤ x ≤ m) instead. ^_^

### Input & Output(Expected):
Each test case will begin with two integers m and n, followed by n integers S<sub>1</sub>, S<sub>2</sub>, S<sub>3</sub> ... S<sub>n</sub>.
Process to the end of file.

Output the maximal summation described above in one line.

### Commented-Out Code:
如果要找出当前数字段中能够累加起的一个最大和的话，直接进行下列代码中以j为变量的循环是毫无疑问的。dp[j]将表示取得第j个数字的最大值sum(1,j)，而sum记录了此过程中出现的最大值，即获得了此数字段最大和。  
同时，pre[j]记录了到第j个位置能够得到的最大值，如果此时进行第二次循环，每到第j个位置时，pre[j-1]将反映出之前一个子段sum(1,j-1)的最大和。

#### Sample Input:
```
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
```
#### Sample Output:
```
6
8
```

### Code:
```c
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
```

###### Hint
>Huge input, scanf and dynamic programming is recommended.