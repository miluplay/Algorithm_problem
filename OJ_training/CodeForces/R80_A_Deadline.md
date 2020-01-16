# Deadline
### Problem Description
Adilbek was assigned to a special project. For Adilbek it means that he has n days to run a special program and provide its results. But there is a problem: the program needs to run for d days to calculate the results.

Fortunately, Adilbek can optimize the program. If he spends x (x is a non-negative integer) days optimizing the program, he will make the program run in ⌈d/(x+1)⌉ days (⌈a⌉ is the ceiling function: ⌈2.4⌉=3, ⌈2⌉=2). The program cannot be run and optimized simultaneously, so the total number of days he will spend is equal to x+⌈d/(x+1)⌉.

Will Adilbek be able to provide the generated results in no more than n days?

### Input & Output(Expected):
The first line contains a single integer T (1≤T≤50) — the number of test cases.

The next T lines contain test cases – one per line. Each line contains two integers n and d (1≤n≤109, 1≤d≤109) — the number of days before the deadline and the number of days the program runs.

Print T answers — one per test case. For each test case print YES (case insensitive) if Adilbek can fit in n days or NO (case insensitive) otherwise.

### Commented-Out Code:

#### Sample Input:
```
3
1 1
4 5
5 11
```
#### Sample Output:
```
YES
YES
NO
```

### Code:
```c
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int imax = 2020;
const int mode = 11;

int T;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  double n, d, i;
  cin >> T;
  while (T--) {
    cin >> n >> d;
    if (d <= n) {
      cout << "YES" << endl;
      continue;
    }
    for (i = 0; i <= n; i++)
      if ((ceil((d / (i + 1))) + i) <= n) {
        cout << "YES" << endl;
        break;
      }
    if (i == n + 1) cout << "NO" << endl;
  }
  return 0;
}
```

###### Hint
>In the first test case, Adilbek decides not to optimize the program at all, since d≤n.
>In the second test case, Adilbek can spend 1 day optimizing the program and it will run ⌈5/2⌉=3 days. In total, he will spend 4 days and will fit in the limit.
>In the third test case, it's impossible to fit in the limit. For example, if Adilbek will optimize the program 2 days, it'll still work ⌈11/(2+1)⌉=4 days.

