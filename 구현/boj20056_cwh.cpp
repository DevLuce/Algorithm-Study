#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N, M, K;
queue<tuple<int, int, int>> board[50][50];
queue<tuple<int, int, int>> copyBoard[50][50];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void moveFireball(){
	// 복사 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			while(!board[i][j].empty()){
				int m, s, d;
				tie(m, s, d) = board[i][j].front();
				board[i][j].pop();
				int ny = (i+N+(dy[d]*s)%N)%N;
				int nx = (j+N+(dx[d]*s)%N)%N;
				copyBoard[ny][nx].push({m, s, d});
			}
		}
	}
	// 재배치
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			while(!copyBoard[i][j].empty()){
				int m, s, d;
				tie(m, s, d) = copyBoard[i][j].front();
				copyBoard[i][j].pop();
				board[i][j].push({m, s, d});	
			}
		}
	}
} 

void combineFireball(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j].size()>1){
				// 합치기
				int sumM, sumS, pd;
				int num=1;
				tie(sumM, sumS, pd)=board[i][j].front();
				board[i][j].pop();
				int dirStart = 0;
				
				while(!board[i][j].empty()){
					int m, s, d;
					tie(m, s, d)=board[i][j].front();
					board[i][j].pop();
					sumM+=m;
					sumS+=s;
					num++;
					if(dirStart==0){
						if(pd%2!=d%2){
							dirStart=1;
						}
					}
					pd=d;
				}
				
				// 나누기
				int divM = sumM/5;
				int divS = sumS/num;
				if(divM!=0){
					for(int k=0; k<4; k++){
						board[i][j].push({divM, divS, dirStart});
						dirStart+=2;
					} 	
				}
			} 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;
	for(int i=0; i<M; i++){
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r-1][c-1].push({m, s, d});
	}
	
	// 이동 명령 
	for(int i=0; i<K; i++){
		// 이동
		moveFireball();
		
		// 합체 
		combineFireball();
	}
	
	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			while(!board[i][j].empty()){
				ans+=get<0>(board[i][j].front());
				board[i][j].pop();
			}
		}
	}
	
	cout << ans << "\n";
}
