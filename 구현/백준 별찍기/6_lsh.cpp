#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cin >> N;

  for (int i = 2 * N - 1; i > 0; i -= 2)
  {
    for (int j = N - (i + 1) / 2; j > 0; j--)
      cout << ' ';
    for (int j = 0; i > j; j++)
      cout << '*';
    cout << '\n';
  }

  return 0;
}
