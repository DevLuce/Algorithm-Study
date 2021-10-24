/*
유기농 배추 (실2, 그래프 탐색) : https://www.acmicpc.net/problem/1012

총 걸린 시간 : 24분 40초

1. 문제 이해) 2분 10
2. 추상화 : 1분
3. 구현 : 13분 20
4. 에러 찾기 : 8분
*/

#include <iostream>
#include <vector>

using namespace std;

int T, N, M, K, X, Y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> board;

void dfs(int x, int y)
{
  for (int i = 0; 4 > i; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= M || !board[nx][ny]) // ny >= Y로 해서 에러 남
      continue;

    board[nx][ny] = 0; // 0이 아닌 1로 해서 에러
    dfs(nx, ny);
  }
}

int main(void)
{
  cin >> T;

  while (T--)
  {
    cin >> M >> N >> K;
    for (int i = 0; N > i; i++)
    {
      vector<int> row;
      for (int j = 0; M > j; j++)
        row.push_back(0);
      board.push_back(row);
    }

    while (K--)
    {
      cin >> Y >> X;
      board[X][Y] = 1;
    }

    int ret = 0;
    for (int i = 0; N > i; i++)
      for (int j = 0; M > j; j++)
      {
        if (!board[i][j])
          continue;
        ret++;
        board[i][j] = 0;
        dfs(i, j);
      }
    cout << ret << '\n';
    board.clear(); // board를 비워 주지 않아서 에러
  }

  return 0;
}
