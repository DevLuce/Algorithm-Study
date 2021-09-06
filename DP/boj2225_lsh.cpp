// 메모이제이션 코드

#include <iostream>
#include <memory.h>

using namespace std;

long long cache[201][201];

long long disassemble(long long n, long long k)
{
  if (k == 0)
    return 1;

  long long &ret = cache[n][k];

  if (ret != -1)
    return ret;

  long long cnt = 0;

  for (long long num = 0; n + 1 > num; num++)
  {
    if (n - num < 0)
      continue;

    if (k - 1 == 0 && n - num != 0)
      continue;

    cnt += (disassemble(n - num, k - 1));
  }
  return ret = cnt % 1000000000;
}

int main(void)
{
  long long N, K;

  cin >> N;
  cin >> K;

  memset(cache, -1, sizeof(cache));

  cout << disassemble(N, K) << '\n';

  return 0;
}

// 단순 완전 탐색 코드

// #include <iostream>
// #include <memory.h>

// using namespace std;

// int disassemble(int n, int k)
// {
//   if (k == 0)
//   {
//     if (n)
//       return 0;
//     return 1;
//   }

//   int cnt = 0;

//   for (int num = 0; n + 1 > num; num++)
//   {
//     if (n - num < 0)
//       continue;

//     cnt += disassemble(n - num, k - 1) % 1000000000;
//   }
//   return cnt;
// }

// int main(void)
// {
//   int N, K;

//   cin >> N;
//   cin >> K;

//   cout << disassemble(N, K) << '\n';

//   return 0;
// }
