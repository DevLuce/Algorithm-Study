/*
적록색약 (골5, 그래프 탐색) : https://www.acmicpc.net/problem/10026

1. 문제 이해 : 2분 40초
2. 추상화 : 대략 1 ~ 2분? 기록 못함
3. 구현 : 20 ~ 21분
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
char n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> weakVisit;
vector<vector<int>> notWeakVisit;
vector<vector<char>> board;

void dfs(int x, int y, bool isWeak)
{
  for (int i = 0; 4 > i; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      continue;
    if (isWeak)
    {
      if (weakVisit[nx][ny])
        continue;
      if (board[nx][ny] != board[x][y])
        if (abs(board[nx][ny] - board[x][y]) != abs('R' - 'G'))
          continue;

      weakVisit[nx][ny] = 1;
      dfs(nx, ny, true);
      continue;
    }
    else if (!isWeak)
    {
      if (notWeakVisit[nx][ny])
        continue;
      if (board[nx][ny] != board[x][y])
        continue;

      notWeakVisit[nx][ny] = 1;
      dfs(nx, ny, false);
    }
  }
}

template <typename T>
void initBoard(vector<vector<T>> &v)
{
  for (int i = 0; N > i; i++)
  {
    vector<T> row;
    for (int j = 0; N > j; j++)
      row.push_back(0);
    v.push_back(row);
  }
}

int main(void)
{
  scanf("%d", &N);

  initBoard(board);
  initBoard(weakVisit);
  initBoard(notWeakVisit);

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
      cin >> board[i][j];

  int weakCnt = 0, notWeakCnt = 0;

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
    {
      if (weakVisit[i][j])
        continue;
      weakVisit[i][j] = 1;
      dfs(i, j, true);
      weakCnt++;
    }

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
    {
      if (notWeakVisit[i][j])
        continue;
      notWeakVisit[i][j] = 1;
      dfs(i, j, false);
      notWeakCnt++;
    }

  cout << notWeakCnt << ' ' << weakCnt << '\n';

  return 0;
}
