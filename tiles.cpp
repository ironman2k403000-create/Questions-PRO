#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<vector<int>> freq(401, vector<int>(401, 0));

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    freq[x][y]++;
  }

  for (int i = 0; i < 401; i++)
  {
    for (int j = 0; j < 401; j++)
    {
      if (i > 0)
        freq[i][j] += freq[i - 1][j];
      if (j > 0)
        freq[i][j] += freq[i][j - 1];
      if (i > 0 && j > 0)
        freq[i][j] -= freq[i - 1][j - 1];
    }
  }

  int low = 0, high = 400, ans = 400;

  auto isValid = [&](int mid)
  {
    for (int i = 0; i + mid < 401; i++)
    {
      for (int j = 0; j + mid < 401; j++)
      {
        int cnt = freq[i + mid][j + mid];
        if (i > 0)
          cnt -= freq[i - 1][j + mid];
        if (j > 0)
          cnt -= freq[i + mid][j - 1];
        if (i > 0 && j > 0)
          cnt += freq[i - 1][j - 1];
        if (cnt >= k)
          return true;
      }
    }
    return false;
  };

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isValid(mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  cout << ans << "\n";
}

int main()
{
  fastio;
  solve();
  return 0;
}
