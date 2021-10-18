#include <iostream>

using namespace std;

int loc[50][50];
bool visit[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N,M;
int r, c, d;
int ans = 1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	cin >> r >> c >> d;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> loc[i][j];
		}
	}
	
	bool isNext;
	while(true){
		visit[r][c] = true;
		
		// 2-a
		d=(d+3)%4;
		int ny=r+dy[d];
		int nx=c+dx[d];
		
		if(0<=ny && ny<N && 0<=nx && nx<M && loc[ny][nx]==0 && !visit[ny][nx]){
			r = ny;
			c = nx;
			ans++;
			continue;
		}
		
		// 2-b
		isNext=false;
		for(int i=0; i<3; i++){
			d=(d+3)%4;
			ny=r+dy[d];
			nx=c+dx[d];
			if(0<=ny && ny<N && 0<=nx && nx<M && loc[ny][nx]==0 && !visit[ny][nx]){
				isNext=true;
				break;
			}	
		}
		if(isNext){
			r = ny;
			c = nx;
			ans++;
			continue;
		}
		
		// 2-c
		ny=r-dy[d];
		nx=c-dx[d];
		if(0<=ny && ny<N && 0<=nx && nx<M && loc[ny][nx]==0){
			r=ny;
			c=nx;
			continue;
		}
		
		// 2-d
		break;
	}
	
	cout << ans << "\n";
}
