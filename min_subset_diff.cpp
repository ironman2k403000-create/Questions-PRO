#include <iostream>
#include <bitset>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
  int N = 5;
  vector<int> L = {3, 3, 7, 3, 1};

  int total = accumulate(L.begin(), L.end(), 0);
  bitset<10001> dp;
  dp[0] = 1;

  for (int x : L)
  {
    dp |= (dp << x);
  }

  int best = 0;
  for (int i = total / 2; i >= 0; --i)
  {
    if (dp[i])
    {
      best = i;
      break;
    }
  }

  cout << "Minimum difference: " << abs(total - 2 * best) << endl;
  return 0;
}