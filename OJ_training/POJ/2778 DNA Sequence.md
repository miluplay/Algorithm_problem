# DNA Sequence
### Description
It's well known that DNA Sequence is a sequence only contains A, C, T and G, and it's very useful to analyze a segment of DNA Sequence，For example, if a animal's DNA sequence contains segment ATC then it may mean that the animal may have a genetic disease. Until now scientists have found several those segments, the problem is how many kinds of DNA sequences of a species don't contain those segments.

Suppose that DNA sequences of a species is a sequence that consist of A, C, T and G，and the length of sequences is a given integer n.
### Input & Output(Expected):
First line contains two integer m (0 <= m <= 10), n (1 <= n <=2000000000). Here, m is the number of genetic disease segment, and n is the length of sequences.

Next m lines each line contain a DNA genetic disease segment, and length of these segments is not larger than 10.
Output

An integer, the number of DNA sequences, mod 100000.
#### Sample Input:
```
4 3
AT
AC
AG
AA
```
#### Sample Output:
```
36
```

```c
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 15;
const int mod = 1e5;
int m, n;
string str;
struct Array {
  LL a[111][111];
} X;
int GetId(char c) { switch (c) {
    case 'A':   return 0; case 'C':   return 1;
    case 'G':   return 2; case 'T':   return 3; }
}
struct node {
  int next[111][4], fail[111], end[111], root, L;
  int NewNode() {
    for (int i = 0; i < 4; i++) next[L][i] = -1;
    end[L++] = 0;
    return L - 1;
  }
  void Init() { L = 0, root = NewNode(); }
  void Insert(string buf) {
    int length = buf.length(), now = root;
    for (int i = 0; i < length; i++) {
      if (next[now][GetId(buf[i])] == -1) next[now][GetId(buf[i])] = NewNode();
      now = next[now][GetId(buf[i])];
    }
    end[now] = 1;
  }
  void Build() {
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < 4; i++)
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      if (end[fail[now]]) end[now] = 1;
      for (int i = 0; i < 4; i++)
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }
} ac;

Array multi(Array A, Array B) {  //矩阵乘法
  Array C;
  int n = ac.L;
  memset(C.a, 0, sizeof(C.a));
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) C.a[i][j] += A.a[i][k] * B.a[k][j];
      C.a[i][j] %= mod;
    }
  return C;
}
Array quickly(Array A, int k) {  //矩阵快速幂
  Array ans;
  memset(ans.a, 0, sizeof(ans.a));
  for (int i = 0; i < ac.L; i++) ans.a[i][i] = 1;
  while (k) {
    if (k & 1) ans = multi(A, ans);
    A = multi(A, A);
    k >>= 1;
  }
  return ans;
}
Array ToMatrix(Array A) {  //构建矩阵
  memset(A.a, 0, sizeof(A));
  for (int i = 0; i < ac.L; i++)
    for (int j = 0; j < 4; j++)
      if (!ac.end[ac.next[i][j]]) A.a[i][ac.next[i][j]]++;
  return A;
}
int main() {
  scanf("%d%d", &m, &n);
  ac.Init();
  while (m--) {
    cin >> str;
    ac.Insert(str);
  }
  ac.Build();
  X = ToMatrix(X);
  X = quickly(X, n);
  LL ans = 0;
  for (int i = 0; i < ac.L; i++) ans = (ans + X.a[0][i]) % mod;
  printf("%lld\n", ans);
  return 0;
}
```