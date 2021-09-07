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
		// ť���� ������
		int cur = q.front();
		q.pop();
		
		// ����� �� ��ȸ
		for(int i=0; i<3; i++){
			if(i==2){
				int tx = cur * 2;
				
				// �� �� �ִ°�
				if(0<= tx && tx<=200000 && time[tx]>time[cur]){
					// üũ��
					time[tx] = time[cur];
					// ť�� �ִ´�
					q.push(tx); 
				} 
			} else {
				int tx = cur + d[i];
				
				// �� �� �ִ°�
				if(0<= tx && tx<=200000 && time[tx]>time[cur]+1){
					// üũ��
					time[tx] = time[cur]+1;
					// ť�� �ִ´�
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
