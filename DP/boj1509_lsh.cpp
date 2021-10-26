#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int cache[2501][2501];
int palin[2501][2501];
string s;

bool isPalindrome(int left, int right)
{
  int &ref = palin[left][right];

  if (ref != -1)
    return ref;

  while (left < right)
  {
    if (s[left] != s[right])
      return ref = 0;

    left++;
    right--;
  }

  return ref = 1;
}

int recur(int left, int right)
{
  int &ref = cache[left][right];

  if (ref != -1)
    return ref;

  if (left >= right)
    return 1;
  if (left + 1 == right)
  {
    if (isPalindrome(left, right))
      return 1;
    else
      return 2;
  }

  if (isPalindrome(left, right))
    return ref = 1;

  int ret = 500000;

  for (int middle = left; right >= middle; middle++)
  {
    if (isPalindrome(left, middle))
      ret = min(ret, recur(middle + 1, right) + 1);
  }
  return ref = ret;
}

int main(void)
{
  cin >> s;
  memset(cache, -1, sizeof(cache));
  memset(palin, -1, sizeof(palin));

  cout << recur(0, s.size() - 1) << '\n';
}