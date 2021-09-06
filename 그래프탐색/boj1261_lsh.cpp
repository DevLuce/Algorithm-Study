#include <iostream>
#include <queue>

#define INF 1000000

using namespace std;

char map[101][101];
int N, M, directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int Dist[101][101];

void Dijkstra()
{
  priority_queue<pair<int, pair<int, int>>> pq;

  pq.push({0, {0, 0}});
  Dist[0][0] = 0;

  while (!pq.empty())
  {
    int cnt = -pq.top().first;
    int cur_x = pq.top().second.first;
    int cur_y = pq.top().second.second;

    pq.pop();

    if (cur_x == N - 1 && cur_y == M - 1)
    {
      cout << cnt << '\n';
      return;
    }

    for (auto direction : directions)
    {
      int nx = direction[0] + cur_x;
      int ny = direction[1] + cur_y;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;

      if (Dist[nx][ny] > cnt + map[nx][ny] - 48)
      {
        Dist[nx][ny] = cnt + map[nx][ny] - 48;
        pq.push({-Dist[nx][ny], {nx, ny}});
      }
    }
  }
}

int main(void)
{
  cin >> M;
  cin >> N;

  for (int i = 0; N > i; i++)
    for (int j = 0; M > j; j++)
    {
      cin >> map[i][j];
      Dist[i][j] = INF;
    }

  Dijkstra();

  return 0;
}
