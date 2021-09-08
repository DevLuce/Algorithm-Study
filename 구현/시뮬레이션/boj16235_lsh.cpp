#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, K;
int ground[11][11];
int addedNutrients[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
deque<int> trees[11][11];
deque<int> deadTrees[11][11];

void spring()
{
  int treeAge, flag;

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
    {
      int treeSize = trees[i][j].size();
      for (int loop = 0; treeSize > loop; loop++)
      {
        treeAge = trees[i][j].front();
        trees[i][j].pop_front();

        if (treeAge > ground[i][j])
        {
          deadTrees[i][j].push_back(treeAge);
          continue;
        }

        ground[i][j] -= treeAge;

        trees[i][j].push_back(treeAge + 1);
      }
    }
}

void summer()
{
  int deadTree;

  for (int x = 0; N > x; x++)
    for (int y = 0; N > y; y++)
    {
      int size = deadTrees[x][y].size();
      for (int loop = 0; size > loop; loop++)
      {
        deadTree = deadTrees[x][y].front();
        deadTrees[x][y].pop_front();

        ground[x][y] += (deadTree / 2);
      }
    }
}

void autumn()
{
  int tree;

  for (int x = 0; N > x; x++)
    for (int y = 0; N > y; y++)
      for (int loop = 0; trees[x][y].size() > loop; loop++)
      {
        tree = trees[x][y][loop];

        if (tree % 5 != 0)
          continue;

        for (int i = 0; 8 > i; i++)
        {
          int nx = dx[i] + x, ny = y + dy[i];

          if (nx >= N || ny >= N || nx < 0 || ny < 0)
            continue;
          trees[nx][ny].push_front(1);
        }
      }
}

void winter()
{
  for (int x = 0; N > x; x++)
    for (int y = 0; N > y; y++)
      ground[x][y] += addedNutrients[x][y];
}

int getAliveTrees()
{
  int ret = 0;
  for (int x = 0; N > x; x++)
    for (int y = 0; N > y; y++)
      ret += trees[x][y].size();
  return ret;
}

void printTree()
{
  for (int x = 0; N > x; x++)
  {
    for (int y = 0; N > y; y++)
    {
      cout << trees[x][y].size() << ' ';
    }
    cout << '\n';
  }
}

int main(void)
{
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      cin >> addedNutrients[i][j];
      ground[i][j] = 5;
    }

  int a, b, c;
  for (int i = 0; M > i; i++)
  {
    cin >> a >> b >> c;
    trees[a - 1][b - 1].push_back(c);
  }

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
      sort(trees[i][j].begin(), trees[i][j].begin() + trees[i][j].size());

  while (K-- > 0)
  {
    spring();
    summer();
    autumn();
    winter();
  }

  cout << getAliveTrees() << '\n';

  return 0;
}
