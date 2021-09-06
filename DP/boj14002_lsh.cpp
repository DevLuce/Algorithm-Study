#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int N, A[1001], cache[1001];
int choices[1001];  // 어느 숫자를 다음 숫자로 선택해야, LIS의 길이를 최대화 할 수 있을지를 기록하는 배열.
vector<int> result; // lis 실제 결과를 담는 벡터.

int lis(int start)
{
  int &ret = cache[start + 1];

  if (ret != -1)
    return ret;

  ret = 1;

  int bestNext = -1; // LIS 길이를 최대화할 선택의 idx.

  for (int i = start + 1; N > i; i++)
    if (A[start] < A[i])
    {
      int cand = lis(i) + 1;
      if (cand > ret)
      {
        bestNext = i;
        ret = cand;
      }
    }

  choices[start + 1] = bestNext; //최적 선택을 choices에다 저장.

  return ret;
}

// choice값을 이용하여, LIS를 재구성하는 재귀 함수.
void reconstruct(int start, vector<int> &seq)
{
  if (start != -1)
    seq.push_back(A[start]); // 선택 값을 벡터에다 저장.

  int next = choices[start + 1];

  if (next != -1)
    reconstruct(next, seq);
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
  memset(choices, -1, sizeof(choices));

  int maxLen = 0;

  maxLen = lis(-1) - 1;

  cout << maxLen << '\n';

  for (int i = 0; 10 > i; i++)
  {
    cout << choices[i] << ' ';
  }

  cout << '\n';

  reconstruct(-1, result);

  for (auto e : result)
  {
    cout << e << ' ';
  }
  return 0;
}
