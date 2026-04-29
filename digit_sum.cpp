#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[101][1001][2];

int solve(int idx, int sum, bool tight, const string &A)
{
  if (sum < 0)
    return 0;

  if (idx == A.size())
    return sum == 0;

  if (dp[idx][sum][tight] != -1)
    return dp[idx][sum][tight];

  int limit = tight ? (A[idx] - '0') : 9;
  int ans = 0;

  for (int digit = 0; digit <= limit; digit++)
  {
    ans = (ans + solve(idx + 1, sum - digit, tight && (digit == limit), A)) % MOD;
  }

  return dp[idx][sum][tight] = ans;
}

int main()
{
  string A;
  int S;
  cin >> A >> S;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, S, 1, A) << endl;
  return 0;
}
