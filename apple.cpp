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