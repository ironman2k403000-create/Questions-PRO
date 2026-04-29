#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[1001][1001];

int helper(int idx, int lastRobot, vector<int> &v)
{
  if (idx == v.size())
  {
    return 0;
  }

  if (dp[idx][lastRobot] != -1)
  {
    return dp[idx][lastRobot];
  }

  int usePrevRobot = (idx - lastRobot) * v[idx] + helper(idx + 1, lastRobot, v);
  int newRobot = m + helper(idx + 1, idx, v);

  return dp[idx][lastRobot] = min(usePrevRobot, newRobot);
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    int firstNonZero = -1;
    for (int i = 0; i < n; i++)
    {
      if (v[i] != 0)
      {
        firstNonZero = i;
        break;
      }
    }

    int ans = 0;
    if (firstNonZero != -1)
    {
      ans = m + helper(firstNonZero + 1, firstNonZero, v);
    }

    cout << ans << endl;
  }

  return 0;
}
