#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cin >> N;

  for (int i = N; i > 0; i--)
  {
    int blank = 0;
    while (N - i > blank++)
      cout << ' ';
    while (N >= blank++)
      cout << '*';
    cout << '\n';
  }

  return 0;
}
