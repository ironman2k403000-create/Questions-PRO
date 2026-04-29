
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> points(n);
    pair<ll, ll> destination;
    cin >> destination.first >> destination.second;

    for (auto &point : points)
    {
      cin >> point.first >> point.second;
    }

    set<ll> parities;
    for (const auto &point : points)
    {
      parities.insert((abs(destination.first - point.first) + abs(destination.second - point.second)) % 2);
    }

    if (parities.size() > 1)
    {
      cout << "-1\n";
      continue;
    }

    ll parity = *parities.begin();
    ll max_distance = 0;

    for (const auto &point : points)
    {
      ll distance = abs(destination.first - point.first) + abs(destination.second - point.second);
      max_distance = max(max_distance, distance);
    }

    ll lo = 0, hi = (ll)(sqrtl(max_distance * 2) + 1), ans = hi;

    while (lo <= hi)
    {
      ll mid = lo + (hi - lo) / 2;
      ll sum = (mid * (mid + 1)) / 2;

      if (sum >= max_distance)
      {
        ans = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }

    ll total_sum = (ans * (ans + 1)) / 2;

    if ((total_sum % 2) == parity)
    {
      cout << ans << "\n";
    }
    else
    {
      ll next_sum1 = ((ans + 1) * (ans + 2)) / 2;
      ll next_sum2 = ((ans + 2) * (ans + 3)) / 2;

      if ((next_sum1 % 2) == parity)
      {
        cout << ans + 1 << "\n";
      }
      else
      {
        cout << ans + 2 << "\n";
      }
    }
  }
  return 0;
}
