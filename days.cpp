#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int fn(int i, int day, vector<pair<int, int>> &v, int n, int m, int lim, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (day > lim)
        return 0;
    if (dp[i][day] != -1)
        return dp[i][day];

    int take = v[i].second + (v[i].first) * day + fn(i + 1, day + 1, v, n, m, lim, dp);
    int nottake = fn(i + 1, day, v, n, m, lim, dp);

    return dp[i][day] = max(take, nottake);
}

void solve(int t)
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> a(n), b(n);
    vector<pair<int, int>> v(n);
    int sa = 0, sb = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sa += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sb += b[i];
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = {b[i], a[i]};
    }

    sort(v.begin(), v.end());
    int res = -1;

    for (int day = 0; day <= n; day++)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int term = fn(0, 1, v, n, m, day, dp);
        int rem = sa + day * sb - term;

        if (rem <= m)
        {
            res = day;
            break;
        }
    }
    cout << res << "\n";
}

int main()
{
    auto start = high_resolution_clock::now(); // Start time measurement

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solve(i);

    auto end = high_resolution_clock::now(); // End time measurement
    duration<double> elapsed = end - start;

    // cout << "Total execution time: " << elapsed.count() << " seconds\n";
    return 0;
}
