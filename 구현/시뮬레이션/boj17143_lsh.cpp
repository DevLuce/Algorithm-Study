#include <iostream>
#include <deque>

using namespace std;

class Shark
{
public:
  int speed;
  int direction;
  int size;
  bool isMoved;

  Shark(int s, int d, int z) : speed(s), direction(d), size(z), isMoved(false) {}
};

int R, C, M, totalCapture = 0;
deque<Shark> board[101][101];

void captureShark(int col)
{
  for (int row = 0; R > row; row++)
  {
    if (!board[row][col].empty())
    {
      totalCapture += board[row][col].front().size;
      board[row][col].pop_front();
      return;
    }
  }
}

void moveShark()
{
  for (int x = 0; R > x; x++)
    for (int y = 0; C > y; y++)
    {
      int boardSize = board[x][y].size();
      for (int i = 0; boardSize > i; i++)
      {
        Shark shark = board[x][y].front();
        int nextPos;

        board[x][y].pop_front();

        if (shark.isMoved)
        {
          board[x][y].push_back(shark);
          continue;
        }

        shark.isMoved = true;

        if (shark.direction == 1)
        {
          int interval = R - 1;
          int moveRound = (shark.speed + R - 1 - x) / interval;
          int restMove = (shark.speed + R - 1 - x) % interval;

          if (moveRound == 0 || moveRound % 2 == 0)
            nextPos = interval - restMove;
          else
          {
            nextPos = restMove;
            shark.direction = 2;
          }
          board[nextPos][y].push_back(shark);
        }
        else if (shark.direction == 2)
        {
          int interval = R - 1;
          int moveRound = (shark.speed + x) / interval;
          int restMove = (shark.speed + x) % interval;

          if (moveRound == 0 || moveRound % 2 == 0)
            nextPos = restMove;
          else
          {
            nextPos = R - 1 - restMove;
            shark.direction = 1;
          }
          board[nextPos][y].push_back(shark);
        }
        else if (shark.direction == 3)
        {
          int interval = C - 1;
          int moveRound = (shark.speed + y) / interval;
          int restMove = (shark.speed + y) % interval;

          if (moveRound == 0 || moveRound % 2 == 0)
            nextPos = restMove;
          else
          {
            nextPos = C - 1 - restMove;
            shark.direction = 4;
          }
          board[x][nextPos].push_back(shark);
        }
        else if (shark.direction == 4)
        {
          int interval = C - 1;
          int moveRound = (shark.speed + C - 1 - y) / interval;
          int restMove = (shark.speed + C - 1 - y) % interval;

          if (moveRound == 0 || moveRound % 2 == 0)
            nextPos = interval - restMove;
          else
          {
            nextPos = restMove;
            shark.direction = 3;
          }
          board[x][nextPos].push_back(shark);
        }
      }
    }
}

// 보드 확인용
void printBoard()
{
  for (int x = 0; R > x; x++)
  {
    for (int y = 0; C > y; y++)
    {
      cout << board[x][y].size() << ' ';
    }
    cout << '\n';
  }
}

void removeSmallShark()
{
  for (int x = 0; R > x; x++)
    for (int y = 0; C > y; y++)
    {
      int size = board[x][y].size();
      int maxSize = -1;
      for (int i = 0; size > i; i++)
      {
        board[x][y][i].isMoved = false;
        if (board[x][y][i].size > maxSize)
          maxSize = board[x][y][i].size;
      }

      for (int i = 0; size > i; i++)
      {
        Shark shark = board[x][y].front();
        board[x][y].pop_front();
        if (shark.size == maxSize)
          board[x][y].push_back(shark);
      }
    }
}

int main(void)
{
  cin >> R >> C >> M;

  int r, c, s, d, z;
  for (int i = 0; M > i; i++)
  {
    cin >> r >> c >> s >> d >> z;

    Shark shark(s, d, z);
    board[r - 1][c - 1].push_back(shark);
  }

  int startLoc = -1;

  while (startLoc < C - 1)
  {

    startLoc++;
    captureShark(startLoc);
    moveShark();
    removeSmallShark();
  }

  cout << totalCapture << '\n';

  return 0;
}
