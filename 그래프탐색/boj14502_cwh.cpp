#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int loc[8][8];
int N, M;
int ans=0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void findSize(){
	int tmpLoc[8][8];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			tmpLoc[i][j]=loc[i][j];		
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmpLoc[i][j]==2){
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				
				while(!q.empty()){
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					
					for(int k=0; k<4; k++){
						int ny = r + dy[k];
						int nx = c + dx[k];
						if(0<=ny && ny<N && 0<=nx && nx<M && tmpLoc[ny][nx]==0){
							tmpLoc[ny][nx]=2;
							q.push(make_pair(ny, nx));
						}
					}
				} 
			}
		}
	}
	
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(tmpLoc[i][j]==0){
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}

void dfs(int cnt){
	if(cnt==3){
		// 영역 크기 구하기 
		findSize();
		return;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(loc[i][j]==0){
				loc[i][j]=1;
				dfs(cnt+1);
				loc[i][j]=0;
			}
		}
	}
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> loc[i][j];
		}
	}
	
	// 조합 찾기 
	dfs(0);
	cout << ans << "\n";
}
