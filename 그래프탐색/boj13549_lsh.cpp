#include <iostream>
#include <queue>

using namespace std;

int N, K, dist[100001];
bool visited[100001] = {false};

bool isOutofBound(int next)
{
  if (next < 0 || next >= 100001)
    return true;
  return false;
}

int bfs(int start, int end)
{
  int time;
  priority_queue<pair<int, int>> pq;

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while (!pq.empty())
  {
    time = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (visited[cur])
      continue;

    dist[cur] = time;
    visited[cur] = true;

    if (end == cur)
      return time;

    int walkFront = cur + 1, walkBack = cur - 1, teleport = 2 * cur;

    if (!isOutofBound(teleport) && !visited[teleport])
      pq.push(make_pair(-time, teleport));

    if (!isOutofBound(walkFront) && !visited[walkFront])
      pq.push(make_pair(-(time + 1), walkFront));

    if (!isOutofBound(walkBack) && !visited[walkBack])
      pq.push(make_pair(-(time + 1), walkBack));
  }

  return dist[end];
}

int main(void)
{
  for (int i = 0; i < 100001; i++)
    dist[i] = 1000000;

  cin >> N;
  cin >> K;
  cout << bfs(N, K) << '\n';

  return 0;
}
