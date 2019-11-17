#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int imax = 500005;
int trie[imax][26], degree[imax], f[imax], num, mynode;
int GetId(char s[20])
{
  int t = 0, L = strlen(s);
  for (int i = 0; i < L; i++) //构建字典树
    if (trie[t][s[i] - 'a'])
      t = trie[t][s[i] - 'a'];
    else
      t = trie[t][s[i] - 'a'] = ++mynode;
  //num全局变量，统计分配的颜色数，rank记录了节点个数（每个颜色的每个字母一个节点）
  if (trie[t][s[L - 1] - 'a'] == 0)
    trie[t][s[L - 1] - 'a'] = ++num;
  return trie[t][s[L - 1] - 'a']; //返回颜色的序号
}
int Find(int x) { return x == f[x] ? f[x] : Find(f[x]); } //并查集，将能够连接的导向同一个父节点
int main()
{
  int t1, t2;
  char s1[20], s2[20];
  memset(trie, 0, sizeof(trie));
  memset(degree, 0, sizeof(degree));
  for (int i = 1; i <= 500000; i++)
    f[i] = i;
  while (scanf("%s %s", &s1, &s2) != EOF)
  {
    t1 = GetId(s1);
    degree[t1]++;
    t2 = GetId(s2);
    degree[t2]++;
    t1 = Find(t1);
    t2 = Find(t2);
    //s1与s2一定是相连的
    if (t1 != t2)
      f[t2] = t1;
  }
  int count = 0;
  //不能并为一个集的话就无法连通了。
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
  {//这里需要判断奇度节点的个数才能判断是否是通路
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