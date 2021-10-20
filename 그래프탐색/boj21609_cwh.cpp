#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[20][20];
int tmpBoard[20][20];
bool visit[20][20];
bool check[20][20];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M;
int tsize=0;
int rainbowSize=0;

void initVisit(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			visit[i][j]=false;
		}
	}
}

void dfs(int r, int c, int num){
	visit[r][c] = true;
	
	tsize++;
	if(board[r][c]==0){
		rainbowSize++;
	} else {
		check[r][c]=true;
	}
	
	for(int i=0; i<4; i++){
		int ny=r+dy[i];
		int nx=c+dx[i];
		if(0<=ny && ny<N && 0<=nx && nx<N && !visit[ny][nx] && (board[ny][nx]==num || board[ny][nx]==0)){
			dfs(ny, nx, num);
		}
	}
}

void dfs2(int r, int c, int num){
	board[r][c]=-2;
	
	for(int i=0; i<4; i++){
		int ny=r+dy[i];
		int nx=c+dx[i];
		if(0<=ny && ny<N && 0<=nx && nx<N && (board[ny][nx]==num || board[ny][nx]==0)){
			dfs2(ny, nx, num);
		}
	}
}

void gravity(){
	for(int j=0; j<N; j++){
		for(int i=N-2; i>=0; i--){
			if(board[i][j]>=0){
				int idx=i+1;
				while(idx<N && board[idx][j]==-2){
					idx++;
				}
				board[idx-1][j]=board[i][j];
				if(idx-1!=i) board[i][j]=-2;
			}
		}
	}
}

void rotate(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			tmpBoard[i][j]=board[j][N-i-1];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			board[i][j]=tmpBoard[i][j];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
		}
	}
	 
	int score=0;
	
	while(true){
		priority_queue<tuple<int, int, int, int>> pq;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				check[i][j]=false;
			}
		}
		
		// 크기가 가장 큰 블록 찾기, 무지개 수, 행, 열
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(board[i][j]>0 && !check[i][j]){
					tsize=0;
					rainbowSize=0;
					initVisit();
					dfs(i, j, board[i][j]);
					pq.push({tsize, rainbowSize, i, j});
				}
			}
		}
		
		// 블록 제거, 점수 획득 (없으면 break)
		int b, r, y, x;
		if(pq.empty()) break;
		tie(b, r, y, x) = pq.top();
		if(b<2) break;
		score+=(b*b);
		dfs2(y, x, board[y][x]);
		
		// 중력
		gravity();
		
		// 회전
		rotate();
		
		// 중력
		gravity();
	}
	
	cout << score << "\n";
}
