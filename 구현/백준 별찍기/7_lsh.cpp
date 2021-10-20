#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cin >> N;

  for (int i = 1; N > i; i++)
  {
    for (int j = 0; N - i > j; j++)
      cout << ' ';
    for (int j = 0; 2 * i - 1 > j; j++)
      cout << '*';

    cout << '\n';
  }

  for (int i = 0; 2 * N - 1 > i; i++)
    cout << '*';
  cout << '\n';

  for (int i = 1; N > i; i++)
  {
    for (int j = 0; i > j; j++)
      cout << ' ';
    for (int j = 2 * (N - i) - 1; j > 0; j--)
      cout << '*';

    cout << '\n';
  }

  return 0;
}
