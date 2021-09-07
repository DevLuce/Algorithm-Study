#include <iostream>
#include <queue>

using namespace std;

int d[2] = {-1, 1};
int time[200001];

int N, K;

void bfs(int a){
	queue<int> q;
	q.push(a);
	time[a] = 0;
	
	while(!q.empty()){
		// 큐에서 꺼내다
		int cur = q.front();
		q.pop();
		
		// 연결된 곳 순회
		for(int i=0; i<3; i++){
			if(i==2){
				int tx = cur * 2;
				
				// 갈 수 있는가
				if(0<= tx && tx<=200000 && time[tx]>time[cur]){
					// 체크인
					time[tx] = time[cur];
					// 큐에 넣는다
					q.push(tx); 
				} 
			} else {
				int tx = cur + d[i];
				
				// 갈 수 있는가
				if(0<= tx && tx<=200000 && time[tx]>time[cur]+1){
					// 체크인
					time[tx] = time[cur]+1;
					// 큐에 넣는다
					q.push(tx); 
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	for(int i=0; i<=200000; i++){
		time[i] = 100001;
	}
	
	bfs(N);
	
	cout << time[K] << "\n";
}
