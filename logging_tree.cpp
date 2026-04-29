#include <bits/stdc++.h>
using namespace std;
// Structure to store the range of positions for a specific tree length
struct Group
{
  int left, right;
};
// Global variables for the memoization table and configurations
long long memo[1005][2];
vector<Group> groups;
int totalNumGroups;
int roadLength;
// Traditional function to update the tree range for a specific length
void updateTreeRange(map<int, pair<int, int>> &treeGroups,int &totalCount, int length, int pos)
{
  if (length <= 0)
    return;

  totalCount++;
  if (treeGroups.find(length) == treeGroups.end())
  {
    treeGroups[length] = make_pair(pos, pos);
    if (pos < treeGroups[length].first)
      treeGroups[length].first = pos;
    if (pos > treeGroups[length].second)
      treeGroups[length].second = pos;
  }
}
// Recursive function with memoization
long long getMinDist(int idx, int side)
{
  // Base Case: All groups processed, return distance tothe end point N
  if (idx == totalNumGroups)
  {
    int lastPos;
    if (side == 0)
      lastPos = groups[idx - 1].left;
    else
      lastPos = groups[idx - 1].right;

    return abs(roadLength - lastPos);
  }
  // Check if result is already calculated
  if (memo[idx][side] != -1)
    return memo[idx][side];
  int currentPos;
  if (idx == 0)
  {
    currentPos = 0; // Starting at the beginning of theroad
  }
  else
  {
    if (side == 0)
      currentPos = groups[idx - 1].left;
    else
      currentPos = groups[idx - 1].right;
  }
  int L = groups[idx].left;
  int R = groups[idx].right;
  // Choice A: Finish this group at the Leftmost tree
  // Move from currentPos -> Rightmost -> Leftmost
  long long toLeft = abs(currentPos - R) + (R - L) + getMinDist(idx + 1, 0);
  // Choice B: Finish this group at the Rightmost tree
  // Move from currentPos -> Leftmost -> Rightmost
  long long toRight = abs(currentPos - L) + (R - L) + getMinDist(idx + 1, 1);
  long long result = toLeft;
  if (toRight < toLeft)
    result = toRight;
  memo[idx][side] = result;
  return result;
}
int main()
{
  int N;
  if (!(cin >> N))
    return 0;
  roadLength = N;
  map<int, pair<int, int>> treeMap;
  int totalTrees = 0;

  vector<int> leftarr(N + 1), rightarr(N + 1);
  for (int i = 0; i <= N; i++)
    cin >> leftarr[i];
  for (int i = 0; i <= N; i++)
    cin >> rightarr[i];

  // Read input for trees along the road (Point 1 to N-1)
  for (int i = 0; i <= N; ++i)
  {
    int leftTree, rightTree;
    leftTree = leftarr[i];
    rightTree = rightarr[i];

    updateTreeRange(treeMap, totalTrees, leftTree, i);
    updateTreeRange(treeMap, totalTrees, rightTree, i);
  }
  // Move data from map to a vector sorted by length descending
  // Using reverse iterator for descending order (Tallesttrees first)
  for (auto it = treeMap.rbegin(); it != treeMap.rend();++it)
  {
    Group g;
    g.left = it->second.first;
    g.right = it->second.second;
    groups.push_back(g);
  }
  totalNumGroups = groups.size();
  // Initialize memoization table with -1
  for (int i = 0; i <= totalNumGroups; ++i)
  {
    memo[i][0] = -1;
    memo[i][1] = -1;
  }
  // Solve for minimum travel distance
  long long minTravelDistance = getMinDist(0, 0);
  // Total time = Travel Distance + Time taken to chop each tree
  cout << minTravelDistance + totalTrees << endl;
  return 0;
}