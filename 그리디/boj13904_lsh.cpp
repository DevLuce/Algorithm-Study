#include <iostream>
#include <queue>

using namespace std;

int N, d, w;
priority_queue<pair<int, int>> pq;

// selected 배열은 과제를 배분할 날짜가 비었는지 확인하기 위한 배열.
bool selected[1001];

int main(void)
{
  cin >> N;

  for (int loop = 0; N > loop; loop++)
  {
    cin >> d >> w;
    pq.push({w, d});
  }

  int totalScore = 0;

  while (!pq.empty())
  {
    int score = pq.top().first;
    int due = pq.top().second;
    pq.pop();

    // for 문을 돌며 과제를 날짜에 배분할 수 있는지 체크.
    // 만약 빈 날짜가 존재할 시 해당 날짜에 과제를 배분 후 totalScore을 증가.
    // 제일 마지막 날짜인, 기한에서부터 앞의 날짜 순으로 확인하는 것이 최적의 선택.
    for (int day = due; 0 < day; day--)
      if (selected[day] == false)
      {
        selected[day] = true;
        totalScore += score;
        break;
      }
  }

  cout << totalScore << '\n';

  return 0;
}
