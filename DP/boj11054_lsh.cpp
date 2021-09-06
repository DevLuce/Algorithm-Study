#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int N, A[1001], cache[1001][2];

// flag로 피크 유무 판단.
// flag가 1일 시 계속 증가, flag가 0일시 계속 감소.
int lis(int start, int flag)
{
  int &ret = cache[start + 1][flag];

  if (ret != -1)
    return ret;

  ret = 1;

  for (int i = start + 1; N > i; i++)
  {
    if (flag) // flag가 1일시, max(계속 증가, 감소 시작)
    {
      if (start == -1 || A[start] < A[i])
      {
        ret = max(ret, lis(i, 1) + 1);
        ret = max(ret, lis(i, 0) + 1);
      }
    }
    else if (A[start] > A[i]) // flag가 0일시는 계속 감소.
      ret = max(ret, lis(i, 0) + 1);
  }

  return ret;
}

int main(void)
{
  int k;

  cin >> N;

  for (int i = 0; N > i; i++)
  {
    scanf("%d", &k);
    A[i] = k;
  }

  memset(cache, -1, sizeof(cache));

  int maxLen = 0;

  maxLen = lis(-1, 1);

  cout << maxLen - 1 << '\n';

  return 0;
}
