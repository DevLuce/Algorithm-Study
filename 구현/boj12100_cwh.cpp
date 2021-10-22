#include <iostream>

using namespace std;

int N;
int board[20][20];
int ans = 0;

void moveBoard(int n){
	switch(n){
		case 0:
			// 옮기고
			for(int j=0; j<N; j++){
				for(int i=0; i<N; i++){
					if(board[i][j]!=0){
						int ny = i-1;
						while(0<=ny && board[ny][j]==0){
							ny--;
						}
						if(ny+1!=i){
							board[ny+1][j]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			} 
			// 합치고
			for(int j=0; j<N; j++){
				for(int i=0; i<N-1; i++){
					if(board[i][j]==board[i+1][j]){
						board[i][j]+=board[i+1][j];
						board[i+1][j]=0;
					}
				}
			}
			// 옮기고
			for(int j=0; j<N; j++){
				for(int i=0; i<N; i++){
					if(board[i][j]!=0){
						int ny = i-1;
						while(0<=ny && board[ny][j]==0){
							ny--;
						}
						if(ny+1!=i){
							board[ny+1][j]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			}
			break;
		case 1:
			// 옮기고
			for(int i=0; i<N; i++){
				for(int j=N-1; j>=0; j--){
					if(board[i][j]!=0){
						int nx = j+1;
						while(nx<N && board[i][nx]==0){
							nx++;
						}
						if(nx-1!=j){
							board[i][nx-1]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			} 
			// 합치고
			for(int i=0; i<N; i++){
				for(int j=N-1; j>0; j--){
					if(board[i][j]==board[i][j-1]){
						board[i][j]+=board[i][j-1];
						board[i][j-1]=0;
					}
				}
			}
			// 옮기고
			for(int i=0; i<N; i++){
				for(int j=N-1; j>=0; j--){
					if(board[i][j]!=0){
						int nx = j+1;
						while(nx<N && board[i][nx]==0){
							nx++;
						}
						if(nx-1!=j){
							board[i][nx-1]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			}
			break;
		case 2:
			// 옮기고
			for(int j=0; j<N; j++){
				for(int i=N-1; i>=0; i--){
					if(board[i][j]!=0){
						int ny = i+1;
						while(ny<N && board[ny][j]==0){
							ny++;
						}
						if(ny-1!=i){
							board[ny-1][j]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			}
			// 합치고
			for(int j=0; j<N; j++){
				for(int i=N-1; i>0; i--){
					if(board[i][j]==board[i-1][j]){
						board[i][j]+=board[i-1][j];
						board[i-1][j]=0;
					}
				}
			}
			// 옮기고
			for(int j=0; j<N; j++){
				for(int i=N-1; i>=0; i--){
					if(board[i][j]!=0){
						int ny = i+1;
						while(ny<N && board[ny][j]==0){
							ny++;
						}
						if(ny-1!=i){
							board[ny-1][j]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			}
			break;
		case 3:
			// 옮기고
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if(board[i][j]!=0){
						int nx = j-1;
						while(0<=nx && board[i][nx]==0){
							nx--;
						}
						if(nx+1!=j){
							board[i][nx+1]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			} 
			// 합치고
			for(int i=0; i<N; i++){
				for(int j=0; j<N-1; j++){
					if(board[i][j]==board[i][j+1]){
						board[i][j]+=board[i][j+1];
						board[i][j+1]=0;
					}
				}
			}
			// 옮기고
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if(board[i][j]!=0){
						int nx = j-1;
						while(0<=nx && board[i][nx]==0){
							nx--;
						}
						if(nx+1!=j){
							board[i][nx+1]=board[i][j];
							board[i][j]=0;	
						}
					}
				}
			} 
			break;
	}
}

void findAns(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ans = max(ans, board[i][j]);
		}
	}
}

void dfs(int cnt){
	findAns();
	
	if(cnt==5){
		return;
	}
	
	for(int i=0; i<4; i++){
		int tmpBoard[20][20];
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				tmpBoard[j][k]=board[j][k];
			}
		}
		moveBoard(i);
		dfs(cnt+1);
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				board[j][k]=tmpBoard[j][k];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
		}
	}
	dfs(0);
	cout << ans << "\n";
}
