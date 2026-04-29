#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

void bfs(int sx, int sy, vector<vector<ll>> &dist, const vector<vector<ll>> &mat)
{
  int h = mat.size(), w = mat[0].size();
  queue<pair<ll, ll>> q;
  dist[sx][sy] = 0;
  q.push({sx, sy});
  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < h && ny < w && mat[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1)
      {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

void solve()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll h, w, c, gx, gy, ax, ay;
    cin >> h >> w >> c;
    vector<vector<ll>> mat(h, vector<ll>(w));
    vector<pair<ll, ll>> warehouses;

    for (ll i = 0; i < h; i++)
      for (ll j = 0; j < w; j++)
      {
        cin >> mat[i][j];
        if (mat[i][j] == 2)
          gx = i, gy = j;
        if (mat[i][j] == 4)
          ax = i, ay = j;
        if (mat[i][j] == 3)
          warehouses.emplace_back(i, j);
      }

    vector<vector<ll>> ds(h, vector<ll>(w, INF)), dd(h, vector<ll>(w, INF));
    bfs(gx, gy, ds, mat);
    bfs(ax, ay, dd, mat);

    ll max_goods = 0;
    for (auto [wx, wy] : warehouses)
    {
      ll cost = c - ds[wx][wy];
      if (cost > 0)
      {
        cost = (cost / dd[wx][wy]) - 1;
        if (cost > 0)
          max_goods = max(max_goods, cost);
      }
    }
    cout << max_goods << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
