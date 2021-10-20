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
    // cout << "x, y " << x << ' ' << y << '\n';
    return;
  }

  int next_depth = depth / 2;
  int next_length = length / 2;
  int next_height = height / 2;

  // cout << x << ' ' << y << ' ' << next_length << ' ' << next_height << '\n';
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
