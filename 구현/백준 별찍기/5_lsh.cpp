#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cin >> N;

  int middle = (N * 2 - 1) / 2;

  for (int idx = 0; N > idx; idx++)
  {
    for (int j = idx; middle > j; j++)
      cout << ' ';
    for (int j = 0; (idx + 1) * 2 - 1 > j; j++)
      cout << '*';
    cout << '\n';
  }

  return 0;
}
