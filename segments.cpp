/*
Problem: Points on an Axis-Aligned Path

You are given a path on an infinite 2D grid defined by M points:
(Xp[0], Yp[0]), (Xp[1], Yp[1]), ..., (Xp[M-1], Yp[M-1]).

Between every consecutive pair of points, there is a line segment.
Each segment is either horizontal (same y-coordinate) or vertical (same x-coordinate).

It is guaranteed that no two segments overlap or intersect except possibly at their endpoints.

You are also given N query points:
(Xq[i], Yq[i]) for i = 0 to N-1.

For each query point, determine whether it lies on any segment of the path.
A point is considered to lie on a segment if it lies on the segment or at its endpoints.

Your task is to count how many query points lie on the path.

Input:
- T test cases
- For each test case:
  - N and M
  - Xq array of size N
  - Yq array of size N
  - Xp array of size M
  - Yp array of size M

Output:
- For each test case, output the number of query points that lie on the path.

Constraints:
- 1 <= T <= 10
- 2 <= N, M <= 100000
- Coordinates range from -10^9 to 10^9
- Each segment is either horizontal or vertical
- No overlapping or intersecting segments except at endpoints

Example:

Example:

Input:
10

5 4
2 3 4 5 6
1 3 3 2 2
1 1 4 4
1 4 4 2

3 3
1 2 3
1 2 3
1 1 3
1 3 3

4 3
0 1 2 3
0 1 2 3
0 0 3
0 3 3

2 2
5 6
5 6
5 5
6 5

3 4
1 2 3
3 3 3
1 1 2 3
3 3 3 3

5 5
0 1 2 3 4
0 0 0 0 0
0 0 4 4 4
0 4 4 0 0

4 4
2 2 2 2
1 2 3 4
2 2 2 2
1 2 3 4

3 3
10 20 30
5 5 5
10 10 30
5 5 5

2 3
1 2
3 4
1 1 2
3 4 4

3 2
7 8 9
1 1 1
7 9
1 1

Output:
1
2
2
1
3
2
4
3
2
3
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Binary search on merged segments
bool contains(const vector<pair<ll,ll>> &seg, ll val) {
    int l = 0, r = seg.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (val < seg[mid].first) r = mid - 1;
        else if (val > seg[mid].second) l = mid + 1;
        else return true;
    }
    return false;
}

// Merge intervals
vector<pair<ll,ll>> mergeSeg(vector<pair<ll,ll>> &v) {
    if (v.empty()) return {};

    sort(v.begin(), v.end());

    vector<pair<ll,ll>> res;
    res.push_back(v[0]);

    for (int i = 1; i < v.size(); i++) {
        ll l = v[i].first;
        ll r = v[i].second;

        if (l <= res.back().second) {
            res.back().second = max(res.back().second, r);
        } else {
            res.push_back(make_pair(l, r));
        }
    }
    return res;
}

int solve(vector<ll> &Xq, vector<ll> &Yq,
          vector<ll> &Xp, vector<ll> &Yp) {

    int N = Xq.size();
    int M = Xp.size();

    unordered_map<ll, vector<pair<ll,ll>>> vRaw, hRaw;

    // Build segments
    for (int i = 1; i < M; i++) {
        ll x1 = Xp[i-1], y1 = Yp[i-1];
        ll x2 = Xp[i],   y2 = Yp[i];

        if (x1 == x2) {
            vRaw[x1].push_back(make_pair(min(y1,y2), max(y1,y2)));
        } else {
            hRaw[y1].push_back(make_pair(min(x1,x2), max(x1,x2)));
        }
    }

    // Merge
    unordered_map<ll, vector<pair<ll,ll>>> v, h;

    for (auto &it : vRaw)
        v[it.first] = mergeSeg(it.second);

    for (auto &it : hRaw)
        h[it.first] = mergeSeg(it.second);

    // Query
    int ans = 0;

    for (int i = 0; i < N; i++) {
        bool ok = false;

        if (v.count(Xq[i]))
            ok |= contains(v[Xq[i]], Yq[i]);

        if (h.count(Yq[i]))
            ok |= contains(h[Yq[i]], Xq[i]);

        if (ok) ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<ll> Xq(N), Yq(N), Xp(M), Yp(M);

        for (int i = 0; i < N; i++) cin >> Xq[i];
        for (int i = 0; i < N; i++) cin >> Yq[i];
        for (int i = 0; i < M; i++) cin >> Xp[i];
        for (int i = 0; i < M; i++) cin >> Yp[i];

        cout << solve(Xq, Yq, Xp, Yp) << "\n";
    }
}