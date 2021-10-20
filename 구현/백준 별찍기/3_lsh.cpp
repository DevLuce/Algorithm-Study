// 별 찍기-3 : https://www.acmicpc.net/problem/2440

#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cin >> N;

  while (N--)
  {
    for (int i = 0; N + 1 > i; i++)
      cout << '*';
    cout << '\n';
  }

  return 0;
}
