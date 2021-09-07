#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
int maze[100][100];
int crash[100][100];

int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};

void bfs(){
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	crash[0][0]=0;
	
	while(!q.empty()){
		// ť���� ������
		pair<int, int> cur = q.front();
		q.pop();

		// ����� �� ��ȸ
		for(int i=0; i<4; i++){
			int ty = cur.first + dy[i];
			int tx = cur.second + dx[i];
			
			// �� �� �ִ°�
			if(0<=ty && ty<N && 0<=tx && tx<M){
				if(maze[ty][tx]==1){
					if(crash[ty][tx] > crash[cur.first][cur.second]+1){
						// üũ��
						crash[ty][tx] = crash[cur.first][cur.second]+1;
						// ť�� �ִ´�
						q.push(make_pair(ty, tx));	
					}
				} else {
					if(crash[ty][tx] > crash[cur.first][cur.second]){
						crash[ty][tx] = crash[cur.first][cur.second];
						q.push(make_pair(ty, tx));	
					}
				}
			} 
		}
	}
}

int main(){
	scanf("%d %d", &M, &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &maze[i][j]);
			crash[i][j] = 10001;
		}
	}
	
	bfs();
	
	cout << crash[N-1][M-1] << "\n";
}
