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