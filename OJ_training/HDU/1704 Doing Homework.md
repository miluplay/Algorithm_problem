# Doing Homework
### Problem Description
Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test, 1 day for 1 point. And as you know, doing homework always takes a long time. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.

### Input & Output(Expected):
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case start with a positive integer N(1<=N<=15) which indicate the number of homework. Then N lines follow. Each line contains a string S(the subject's name, each string will at most has 100 characters) and two integers D(the deadline of the subject), C(how many days will it take Ignatius to finish this subject's homework).

Note: All the subject names are given in the alphabet increasing order. So you may process the problem much easier.

For each test case, you should output the smallest total reduced score, then give out the order of the subjects, one subject in a line. If there are more than one orders, you should output the alphabet smallest one.

### Commented-Out Code:

#### Sample Input:
```
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
```

#### Sample Output:
```
2
Computer
Math
English
3
Computer
English
Math
```

### Code:
```c
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int imax = (1 << 15) + 10;
struct vj
{
  string name;
  int value;
  int end;
} subject[21];
int dp[imax], road[imax], time[imax];
void out(int a)
{
  if (!a)
    return;
  out(a - (1 << road[a]));
  cout << subject[road[a]].name << endl;
}
int main()
{
  int t, n;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for (cin >> t; t--;)
  {
    memset(time, 0, sizeof(time));
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> subject[i].name >> subject[i].end >> subject[i].value;
    for (int i = 1; i < (1 << n); i++)
    {
      dp[i] = INF;
      for (int j = n - 1; j >= 0; j--)
      {
        int temp = 1 << j;
        if (!(i & temp))
          continue;
        int spend = time[i - temp] + subject[j].value - subject[j].end;
        if (spend < 0)
          spend ^= spend; //负数变为零
        if (dp[i] > dp[i - temp] + spend)
        {
          dp[i] = dp[i - temp] + spend;
          time[i] = time[i - temp] + subject[j].value;
          road[i] = j;
        }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
    out((1 << n) - 1);
  }
  return 0;
}
```

##### Hint
>In the second test case, both Computer->English->Math and Computer->Math->English leads to reduce 3 points, but the word "English" appears earlier than the word "Math", so we choose the first order. That is so-called alphabet order.