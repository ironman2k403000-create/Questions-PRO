#include <iostream>
#include <vector>
using namespace std;

const int MAX_SUM = 500 * 100;
const int MAX_NODES = 500;

struct Node
{
  int value;
  int childCount;
  vector<int> children;
  bool sum[MAX_SUM + 1];

  Node()
  {
    value = -1;
    childCount = 0;

    for (int i = 1; i <= MAX_SUM; i++)
    {
      sum[i] = false;
    }
    sum[0] = true;
  }
};

Node nodes[MAX_NODES + 1];

// calls to process tree : N * (500*100) * 100
int processTree(int nodeNumber)
{
  Node &currentNode = nodes[nodeNumber];

  int minChildSum = MAX_SUM;

  // Process children
  for (int k = 0; k < currentNode.childCount; k++)
  {
    int childNumber = currentNode.children[k];
    minChildSum = min(minChildSum, processTree(childNumber));
  }

  // Leaf node
  if (!currentNode.childCount)
  {
    for (int i = 0; i <= currentNode.value; i++)
    {
      currentNode.sum[i] = true;
    }
    return currentNode.value;
  }

  int maxSum = 0;

  for (int j = 1; j <= minChildSum; j++)
  {
    bool sumPossible = true;

    for (int k = 0; k < currentNode.childCount; k++)
    {
      Node &childNode = nodes[currentNode.children[k]];
      if (!childNode.sum[j])
      {
        sumPossible = false;
        break;
      }
    }

    if (sumPossible)
    {
      for (int i = 0; i <= currentNode.value; i++)
      {
        int s = i + currentNode.childCount * j;
        currentNode.sum[s] = true;
        maxSum = max(maxSum, s);
      }
    }
  }

  return maxSum;
}

int resultt()
{
  int ans = 0;
  Node &root = nodes[1];

  for (int i = 0; i <= MAX_SUM; i++)
  {
    if (root.sum[i])
    {
      ans = max(ans, i);
    }
  }
  return ans;
}

int main()
{
  FILE *pF = 0;
  freopen("in.txt", "r", stdin);

  int TC = 0;
  cin >> TC;

  while (TC--)
  {
    int nodeCount = 0;
    cin >> nodeCount;

    int nodeNumber, value, childCount;

    // RESET NODES
    for (int i = 1; i <= MAX_NODES; i++)
    {
      nodes[i] = Node();
    }

    while (nodeCount--)
    {
      cin >> nodeNumber >> value >> childCount;

      nodes[nodeNumber].value = value;
      nodes[nodeNumber].childCount = childCount;

      while (childCount--)
      {
        int childNumber;
        cin >> childNumber;
        nodes[nodeNumber].children.push_back(childNumber);
      }
    }

    processTree(1);
    cout << resultt() << endl;
  }

  return 0;
}