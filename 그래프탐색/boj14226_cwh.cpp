#include <iostream>
#include <queue>

using namespace std;

bool visit[2001][2001];
int S;

void bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));
	
	while(!q.empty()){
		// 큐에서 꺼낸다.
		pair<int, int> v = q.front().first;
		int cur = v.first;
		int clip = v.second;
		int cnt = q.front().second;
		q.pop();
		
		visit[cur][clip] = true;
		
		// 목적지인가
		if(cur == S){
			cout << cnt << "\n";
			return;
		} 
		
		// 연결된 곳 순회
		int tx = cur;
		// 갈 수 있는가(현재 화면 복사) 
		if(tx <= 2000 && !visit[tx][cur]){
			// 체크인
			visit[tx][cur] = true;
			// 큐에 넣는다
			q.push(make_pair(make_pair(tx, cur), cnt+1)); 
		}
		// 갈 수 있는가(클립보드 붙여넣기)
		tx = cur + clip;
		if(tx <= 2000 && !visit[tx][clip]){
			// 체크인
			visit[tx][clip] = true;
			// 큐에 넣는다
			q.push(make_pair(make_pair(tx, clip), cnt+1)); 
		} 
		// 갈 수 있는가 (하나 빼기)
		tx = cur - 1;
		if(0<= tx && !visit[tx][clip]){
			// 체크인
			visit[tx][clip] = true;
			// 큐에 넣는다
			q.push(make_pair(make_pair(tx, clip), cnt+1)); 
		} 
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> S;
	
	bfs();
}
