#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int S;
int cache[2002][2002]; // S 개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값.

void bfs(int screen, int board, int time)
{
  queue<pair<pair<int, int>, int>> q;

  q.push({{screen, board}, time});

  while (!q.empty())
  {
    int screen = q.front().first.first;
    int board = q.front().first.second;
    int time = q.front().second;
    q.pop();

    if (cache[screen][board] != -1)
      continue;

    cache[screen][board] = time;

    if (screen == S)
    {
      cout << time << '\n';
      break;
    }
    q.push({{screen, screen}, time + 1});
    if (board && screen + board <= 1000)
      q.push({{screen + board, board}, time + 1});
    if (screen > 1)
      q.push({{screen - 1, board}, time + 1});
  }
}

int main(void)
{
  cin >> S;

  memset(cache, -1, sizeof(cache));

  bfs(1, 0, 0);

  return 0;
}