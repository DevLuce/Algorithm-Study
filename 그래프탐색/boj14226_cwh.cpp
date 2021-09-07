#include <iostream>
#include <queue>

using namespace std;

bool visit[2001][2001];
int S;

void bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));
	
	while(!q.empty()){
		// ť���� ������.
		pair<int, int> v = q.front().first;
		int cur = v.first;
		int clip = v.second;
		int cnt = q.front().second;
		q.pop();
		
		visit[cur][clip] = true;
		
		// �������ΰ�
		if(cur == S){
			cout << cnt << "\n";
			return;
		} 
		
		// ����� �� ��ȸ
		int tx = cur;
		// �� �� �ִ°�(���� ȭ�� ����) 
		if(tx <= 2000 && !visit[tx][cur]){
			// üũ��
			visit[tx][cur] = true;
			// ť�� �ִ´�
			q.push(make_pair(make_pair(tx, cur), cnt+1)); 
		}
		// �� �� �ִ°�(Ŭ������ �ٿ��ֱ�)
		tx = cur + clip;
		if(tx <= 2000 && !visit[tx][clip]){
			// üũ��
			visit[tx][clip] = true;
			// ť�� �ִ´�
			q.push(make_pair(make_pair(tx, clip), cnt+1)); 
		} 
		// �� �� �ִ°� (�ϳ� ����)
		tx = cur - 1;
		if(0<= tx && !visit[tx][clip]){
			// üũ��
			visit[tx][clip] = true;
			// ť�� �ִ´�
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
