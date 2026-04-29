#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

// Direction arrays: Right, Down, Left, Up
// Turn right: 0 -> 1 -> 2 -> 3 -> 0
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

struct State
{
  int r, c;
  int dir;
  int target;
  int turns;
};

int N, M;
int grid[65][65];

// dist[row][col][direction][target]
int dist[65][65][4][155];

void solve(int tc)
{
  cin >> N;
  M = 0;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cin >> grid[i][j];
      M = max(M, grid[i][j]);

      // Initialize dist array
      for (int k = 0; k < 4; k++)
      {
        for (int l = 0; l <= 150; l++)
        {
          dist[i][j][k][l] = -1;
        }
      }
    }
  }

  // If starting cell is blocked
  if (grid[0][0] == -1)
  {
    cout << "#" << tc << " " << -1 << "\n";
    return;
  }

  deque<State> dq;

  int start_target = 1;

  // If first apple is at start
  if (grid[0][0] == 1)
  {
    start_target = 2;
  }

  dq.push_front({0, 0, 0, start_target, 0});
  dist[0][0][0][start_target] = 0;

  int min_turns = -1;

  while (!dq.empty())
  {
    State cur = dq.front();
    dq.pop_front();

    int r = cur.r;
    int c = cur.c;
    int dir = cur.dir;
    int target = cur.target;
    int turns = cur.turns;

    // If all apples collected
    if (target > M)
    {
      min_turns = turns;
      break;
    }

    // Skip worse states
    if (dist[r][c][dir][target] != -1 &&
        dist[r][c][dir][target] < turns)
    {
      continue;
    }

    // --- MOVE STRAIGHT (cost 0) ---
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] != -1)
    {
      int next_target = target;

      if (grid[nr][nc] == target)
      {
        next_target++;
      }

      if (dist[nr][nc][dir][next_target] == -1 ||
          dist[nr][nc][dir][next_target] > turns)
      {

        dist[nr][nc][dir][next_target] = turns;
        dq.push_front({nr, nc, dir, next_target, turns});
      }
    }

    // --- TURN RIGHT (cost 1) ---
    int ndir = (dir + 1) % 4;
    int next_turns = turns + 1;

    if (dist[r][c][ndir][target] == -1 ||
        dist[r][c][ndir][target] > next_turns)
    {

      dist[r][c][ndir][target] = next_turns;
      dq.push_back({r, c, ndir, target, next_turns});
    }
  }

  cout << "#" << tc << " " << min_turns << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int i = 1; i <= T; ++i)
  {
    solve(i);
  }

  return 0;
}







//aproch 2
// #include <bits/stdc++.h>
// using namespace std;

// // Directions: 0=Right, 1=Down, 2=Left, 3=Up
// const int dr[] = {0, 1, 0, -1};
// const int dc[] = {1, 0, -1, 0};

// int N;
// int grid[60][60];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     for (int t = 1; t <= T; t++) {
//         cin >> N;

//         int M = 0;
//         vector<pair<int,int>> apples;
//         map<int, pair<int,int>> apple_pos;

//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 cin >> grid[i][j];
//                 if (grid[i][j] > 0) {
//                     M = max(M, grid[i][j]);
//                     apple_pos[grid[i][j]] = {i, j};
//                 }
//             }
//         }

//         // Collect apples in order 1..M
//         apples.resize(M);
//         for (int k = 1; k <= M; k++) {
//             apples[k-1] = apple_pos[k];
//         }

//         const int INF = 1e9;

//         // dp[d] = min turns to be at current position facing direction d
//         vector<int> dp(4, INF);
//         dp[0] = 0; // start at (0,0) facing Right

//         int cur_r = 0, cur_c = 0;
//         bool possible = true;

//         for (int k = 0; k < M; k++) {
//             int tr = apples[k].first;
//             int tc = apples[k].second;

//             vector<int> ndp(4, INF);

//             // dist[r][c][d] = min total turns to reach (r,c) facing d
//             vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));

//             // min-heap: each entry is {cost, row, col, direction}
//             priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

//             // Seed all 4 directions with their costs from previous leg
//             for (int d = 0; d < 4; d++) {
//                 if (dp[d] < INF) {
//                     if (dist[cur_r][cur_c][d] > dp[d]) {
//                         dist[cur_r][cur_c][d] = dp[d];
//                         pq.push({dp[d], cur_r, cur_c, d});
//                     }
//                 }
//             }

//             while (!pq.empty()) {
//                 vector<int> top = pq.top(); pq.pop();
//                 int cost = top[0];
//                 int r    = top[1];
//                 int c    = top[2];
//                 int d    = top[3];

//                 // Skip outdated entries
//                 if (cost > dist[r][c][d]) continue;

//                 // Option 1: Move forward (cost 0)
//                 {
//                     int nr = r + dr[d];
//                     int nc = c + dc[d];
//                     if ((nr >= 0 && nr < N) && (nc >= 0 && nc < N) && (grid[nr][nc] != -1)) {
//                         if (cost < dist[nr][nc][d]) {
//                             dist[nr][nc][d] = cost;
//                             pq.push({cost, nr, nc, d});
//                         }
//                     }
//                 }

//                 // Option 2: Turn right (cost +1), stay in place
//                 {
//                     int nd = (d + 1) % 4;
//                     if ((cost + 1) < dist[r][c][nd]) {
//                         dist[r][c][nd] = cost + 1;
//                         pq.push({(cost + 1), r, c, nd});
//                     }
//                 }
//             }

//             // Read results at apple's cell
//             bool reached = false;
//             for (int d = 0; d < 4; d++) {
//                 if (dist[tr][tc][d] < INF) {
//                     ndp[d] = dist[tr][tc][d];
//                     reached = true;
//                 }
//             }

//             // Apple is unreachable
//             if (!reached) {
//                 possible = false;
//                 break;
//             }

//             // Hand off to next leg
//             dp    = ndp;
//             cur_r = tr;
//             cur_c = tc;
//         }

//         if (!possible) {
//             cout << "#" << t << " -1\n";
//         } else {
//             int ans = *(min_element(dp.begin(), dp.end()));
//             cout << "#" << t << " " << ans << "\n";
//         }
//     }

//     return 0;
// }