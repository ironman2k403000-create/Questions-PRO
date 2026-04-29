#include <bits/stdc++.h>
using namespace std;

struct Line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersect(Line l) { return (long double)(c - l.c) / (l.m - m); }
};

void solve() {
    int n;
    long long m_cost;
    cin >> n >> m_cost;
    vector<long long> v(n);
    int firstNonZero = -1;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] != 0 && firstNonZero == -1) {
            firstNonZero = i;
        }
    }

    if (firstNonZero == -1) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> S0(n, 0), S1(n, 0);
    S0[0] = v[0];
    S1[0] = 0;
    
    for (int i = 1; i < n; i++) {
        S0[i] = S0[i - 1] + v[i];
        S1[i] = S1[i - 1] + (long long)i * v[i];
    }

    vector<long long> dp(n, 0);
    dp[firstNonZero] = m_cost;

    deque<Line> dq;
    dq.push_back({-firstNonZero, dp[firstNonZero] - S1[firstNonZero] + firstNonZero * S0[firstNonZero]});

    for (int i = firstNonZero + 1; i < n; i++) {
        long long x = S0[i - 1];
        
        while (dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x)) {
            dq.pop_front();
        }
        
        dp[i] = m_cost + S1[i - 1] + dq[0].eval(x);

        Line newLine = {-i, dp[i] - S1[i] + i * S0[i]};
        
        while (dq.size() >= 2 && dq[dq.size() - 2].intersect(newLine) <= dq[dq.size() - 2].intersect(dq.back())) {
            dq.pop_back();
        }
        dq.push_back(newLine);
    }

    long long ans = 9e18;
    for (int j = firstNonZero; j < n; j++) {
        long long cost = dp[j] + S1[n - 1] - S1[j] - j * (S0[n - 1] - S0[j]);
        ans = min(ans, cost);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}