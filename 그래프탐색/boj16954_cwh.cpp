#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char board[8][8];
bool visit[8][8][9];
int dy[9]={-1, -1, 0, 1, 1, 1, 0, -1, 0};
int dx[9]={0, 1, 1, 1, 0, -1, -1, -1, 0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin >> board[i][j];
		}
	}
	
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(7,0), 0));
	visit[7][0][0]=true;
	
	while(!q.empty()){
		int r = q.front().first.first;
		int c = q.front().first.second;
		int sec = q.front().second;
		q.pop();
		
		if(r==0 && c==7){
			cout << 1 << "\n";
			return 0;
		}
		
		for(int i=0; i<9; i++){
			int ny=r+dy[i];
			int nx=c+dx[i];
			int ns=min(sec+1,8);
			if(0<=ny && ny<8 && 0<=nx && nx<8 && !visit[ny][nx][ns]){
				
				if(ny-sec>=0 && board[ny-sec][nx]=='#') continue;
				if(ny-sec-1>=0 && board[ny-sec-1][nx]=='#') continue;
				
				visit[ny][nx][ns]=true;
				q.push(make_pair(make_pair(ny, nx),ns));	
			}
		}
	}
	
	cout << 0 << "\n";
}
