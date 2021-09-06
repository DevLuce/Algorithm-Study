// 2067과 똑같은 문제.

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int solution[100001];
int selected[2];

int main(void)
{
  scanf("%d", &N);

  for (int loop = 0; N > loop; loop++)
    scanf("%d", &solution[loop]);

  sort(solution, solution + N);

  int startIdx = 0, endIdx = N - 1;
  int minPvalue = INT_MAX;

  while (startIdx < endIdx)
  {
    int Pvalue = abs(solution[startIdx] + solution[endIdx]);

    if (minPvalue > Pvalue)
    {
      minPvalue = Pvalue;
      selected[0] = solution[startIdx];
      selected[1] = solution[endIdx];
    }

    if (abs(solution[startIdx]) > abs(solution[endIdx]))
      startIdx++;
    else if (abs(solution[startIdx]) < abs(solution[endIdx]))
      endIdx--;
    else
      break;
  }

  printf("%d %d\n", selected[0], selected[1]);

  return 0;
}
