/*
별 찍기 11 - https://www.acmicpc.net/problem/2448


1. 문제 이해 : 30초
2. 규칙 파악 : 3분 30초
3. 솔루션 추상화 : 9분 30초
4. 구현 : 8분 30초
5. 에러 찾기 : 20분 이상
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> board;

void drow(int x, int y, int depth, int length, int height)
{
  if (depth == 1)
  {
    board[x - 1][y] = '*';
    board[x][y - 1] = '*';
    board[x][y + 1] = '*';
    for (int i = 0; 5 > i; i++)
      board[x + 1][y - 2 + i] = '*';
    return;
  }

  int next_depth = depth / 2;
  int next_length = length / 2;
  int next_height = height / 2;

  if (next_height != 1)
    drow(x - next_height, y, next_depth, next_length, next_height);
  else
    drow(x - next_height - 1, y, next_depth, next_length, next_height);

  drow(x + next_height, y - next_length, next_depth, next_length, next_height);
  drow(x + next_height, y + next_length, next_depth, next_length, next_height);
}

int main(void)
{
  cin >> N;

  for (int i = 0; N > i; i++)
  {
    vector<char> input;
    for (int j = 0; 2 * N > j; j++)
    {
      input.push_back(' ');
    }
    board.push_back(input);
  }

  drow(N / 2, N - 1, N / 3, N, N / 2);

  for (int i = 0; N > i; i++)
  {
    for (int j = 0; 2 * N > j; j++)
      cout << board[i][j];
    cout << '\n';
  }

  return 0;
}
