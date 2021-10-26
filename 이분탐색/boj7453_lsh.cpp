#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(void)
{
  int N, num, left, right;
  int A[4001];
  int B[4001];
  int C[4001];
  int D[4001];
  vector<ll> AB, CD;

  cin >> N;

  for (int n = 0; N > n; n++)
    scanf("%d %d %d %d", &A[n], &B[n], &C[n], &D[n]);

  for (int i = 0; N > i; i++)
    for (int j = 0; N > j; j++)
    {
      AB.push_back(A[i] + B[j]);
      CD.push_back(C[i] + D[j]);
    }

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  ll hi = AB.size(), length = AB.size(), cnt = 0;

  for (int i = 0; length > i; i++)
  {
    num = AB[i];
    left = lower_bound(CD.begin(), CD.begin() + hi, -num) - CD.begin();
    right = upper_bound(CD.begin(), CD.begin() + hi, -num) - CD.begin();

    if (left == hi || CD[left] != -num)
      continue;
    cnt += (right - left);
    hi = right;
  }

  cout << cnt << '\n';

  return 0;
}
