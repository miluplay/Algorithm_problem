# Colored Sticks
### Description:
You are given a bunch of wooden sticks. Each endpoint of each stick is colored with some color. Is it possible to align the sticks in a straight line such that the colors of the endpoints that touch are of the same color?

### Input & Output(Expected):
Input is a sequence of lines, each line contains two words, separated by spaces, giving the colors of the endpoints of one stick. A word is a sequence of lowercase letters no longer than 10 characters. There is no more than 250000 sticks.

If the sticks can be aligned in the desired way, output a single line saying Possible, otherwise output Impossible.
Sample Input
### Commented-Out Code:

#### Sample Input:
```
blue red
red violet
cyan blue
blue magenta
magenta cyan
Sample Output
```
#### Sample Output:
```
Possible
```

```c
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int imax = 500005;
int trie[imax][26], degree[imax], f[imax], num, myrank;
int insert(char s[20])
{
  int t = 0, L = strlen(s);
  for (int i = 0; i < L; i++)
    if (trie[t][s[i] - 'a'])
      t = trie[t][s[i] - 'a'];
    else
      t = trie[t][s[i] - 'a'] = ++myrank;
  if (trie[t][s[L - 1] - 'a'] == 0)
    trie[t][s[L - 1] - 'a'] = ++num;
  return trie[t][s[L - 1] - 'a']; //返回颜色的序号
}
int Find(int x) { return x == f[x] ? f[x] : Find(f[x]); }
int main()
{
  int t1, t2;
  char s1[20], s2[20];
  memset(trie, 0, sizeof(trie));
  memset(degree, 0, sizeof(degree));
  num = 0;
  myrank = 0;
  for (int i = 1; i <= 500000; i++)
    f[i] = i;
  while (scanf("%s %s", &s1, &s2) != EOF)
  {
    t1 = insert(s1);
    degree[t1]++;
    t2 = insert(s2);
    degree[t2]++;
    t1 = Find(t1);
    t2 = Find(t2);
    if (t1 != t2)
      f[t2] = t1;
  }
  int count = 0;
  for (int i = 1; i <= num; i++)
  {
    if (i == Find(i))
      count++;
    if (count > 1)
      break;
  }
  if (count > 1)
    printf("Impossible\n");
  else
  {
    int j = 0;
    for (int i = 1; i <= num; i++)
      if (degree[i] % 2)
        j++;
    if (j == 0 || j == 2)
      printf("Possible\n");
    else
      printf("Impossible\n");
  }
}
```

##### Hint
>Huge input,scanf is recommended.