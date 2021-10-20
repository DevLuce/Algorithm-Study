#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;

int get_str_length(string str);

int main(void)
{
  cin >> str;

  cout << get_str_length(str) << '\n';
  return 0;
}

int get_str_length(string str)
{
  vector<char> stack;
  vector<char> innerStack;

  int depth = 0;
  int total = 0;

  for (int i = 0; str.size() > i; i++)
  {
    if (str[i] != ')')
    {
      if (str[i] == '(')
      {
        depth += 1;
        if (depth == 1)
          continue;
      }

      if (!depth)
      {
        stack.push_back(str[i]);
        total += 1;
      }
      else
        innerStack.push_back(str[i]);
      continue;
    }

    depth--;

    if (depth)
    {
      innerStack.push_back(str[i]);
      continue;
    }

    string subStr = "";
    while (!innerStack.empty())
    {
      subStr = innerStack.back() + subStr;
      innerStack.pop_back();
    }
    int subStrLength = get_str_length(subStr);
    int innerLength = subStrLength * (stack.back() - 48);
    stack.pop_back();
    total += (innerLength - 1);
  }

  return total;
}
