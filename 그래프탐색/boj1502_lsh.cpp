/* 
내리막 길(골4, 그래프 탐색): https://www.acmicpc.net/problem/1520

1. 문제 이해 : 1분
2. 추상화 : 2분 30초
3. 구현 : 15분
4. 에러 처리 : 1분
5. timeout 에러 발생 -> 솔루션 재 추상화 & 구현 : bfs 코드 => 캐싱된 dfs 코드로 변경 8분
6. 에러 처리 : 12분 20초
*/

#include <iostream>
#include <deque>
#include <vector>
#include <memory.h>

using namespace std;

vector<vector<int>> board;

int N, M, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cache[501][501];

int dfs(int x, int y)
{
  int &ret = cache[x][y];
  int cnt = 0;

  if (ret != -1)
    return ret;

  if (x == N - 1 && y == M - 1)
    return 1;

  for (int i = 0; 4 > i; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= M || board[nx][ny] >= board[x][y])
      continue;

    // 에러 난 지점. 고치기 전엔 ret = dfs(nx, ny)이었는데, ret 가 -1로 초기화된 상태기 때문에 결과값에서 1 적게 나온다.
    cnt += dfs(nx, ny);
  }
  return ret = cnt;
}

int main(void)
{
  cin >> N >> M;

  memset(cache, -1, sizeof(cache));

  for (int i = 0; N > i; i++)
  {
    vector<int> v;
    for (int j = 0; M > j; j++)
    {
      cin >> n;
      v.push_back(n);
    }
    board.push_back(v);
  }

  int cnt = dfs(0, 0);

  cout << cnt << '\n';

  return 0;
}
