/*
안전 영역(실버 1, 그래프 탐색) : https://www.acmicpc.net/problem/2468

총 걸린 시간 : 43분

1. 문제 이해 : 3분 40초
2. 추상화 : 1분 20초
3. 구현 : 17분
4. 에러 : 20분
*/

#include <iostream>
#include <vector>

using namespace std;

int N, n, max_number = -1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> board;

vector<vector<int>> copyBoard()
{
  vector<vector<int>> newBoard;

  for (int i = 0; N > i; i++)
  {
    vector<int> newRow;
    for (int j = 0; N > j; j++)
      newRow.push_back(board[i][j]);
    newBoard.push_back(newRow);
  }
  return newBoard;
}

void dfs(int x, int y, int rain, vector<vector<int>> &newBoard) // vector가 인자에 들어갈 때, vector의 reference가 들어가는 줄 알았으나 사실은 생성자가 호출되면서 새로운 vector가 생성, 값을 복사함.
{
  for (int i = 0; 4 > i; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (0 > nx || 0 > ny || N <= nx || N <= ny || newBoard[nx][ny] == 101 || newBoard[nx][ny] <= rain)
      continue;
    newBoard[nx][ny] = 101;
    dfs(nx, ny, rain, newBoard);
  }
}

int main(void)
{
  cin >> N;

  for (int i = 0; N > i; i++)
  {
    vector<int> row;
    for (int j = 0; N > j; j++)
      row.push_back(0);
    board.push_back(row);
  }

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
    {
      cin >> n;
      board[i][j] = n;
      max_number = max(max_number, n);
    }

  int ret = 0;
  for (int rain = 0; max_number + 1 > rain; rain++)
  {
    vector<vector<int>> newBoard = copyBoard();
    int cnt = 0;

    for (int x = 0; N > x; x++)
    {
      for (int y = 0; N > y; y++)
      {
        if (rain < newBoard[x][y])
        {
          if (newBoard[x][y] == 101)
            continue;
          newBoard[x][y] = 101;
          cnt++;
          dfs(x, y, rain, newBoard);
        }
      }
    }

    ret = max(ret, cnt);
  }
  cout << ret << '\n';
  return 0;
}
