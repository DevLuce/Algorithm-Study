#include <iostream>
#include <queue>

using namespace std;

int N, M;
char board[10][10];
bool visit[10][10][10][10];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1}; 

struct Ball{
	int row, col;
	int brow, bcol;
	int cnt;
	
	Ball(int r, int c, int br, int bc, int cn): row(r), col(c), brow(br), bcol(bc), cnt(cn) {};
};

int main(){
	
	scanf("%d %d", &N, &M);
	queue<Ball> q;
	
	int r, c, br, bc;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1s", &board[i][j]);
			if(board[i][j]=='R'){
				r = i;
				c = j;
			}
			else if(board[i][j]=='B'){
				br = i;
				bc = j;
			}
		}
	}
	
	q.push(Ball(r, c, br, bc, 0));
	visit[r][c][br][bc]=true;
	
	
	while(!q.empty()){
		Ball cur = q.front();
		q.pop();
		
		if(cur.cnt>10) break;
		if(board[cur.row][cur.col]=='O' && board[cur.brow][cur.bcol]!='O'){
			printf("%d\n", cur.cnt);
			return 0;
		}
		
		for(int i=0; i<4; i++){
			int ny = cur.row;
			int nx = cur.col;
			int bny = cur.brow;
			int bnx = cur.bcol;
			
			while(true){
				if(board[ny][nx]!='#'&&board[ny][nx]!='O'){
					ny+=dy[i];
					nx+=dx[i];
				} else {
					if(board[ny][nx]=='#'){
						ny-=dy[i];
						nx-=dx[i];
					}
					break;
				}
			}
			
			while(true){
				if(board[bny][bnx]!='#'&&board[bny][bnx]!='O'){
					bny+=dy[i];
					bnx+=dx[i];
				} else {
					if(board[bny][bnx]=='#'){
						bny-=dy[i];
						bnx-=dx[i];
					} 
					break;
				}
			}
			
			if(ny==bny && nx==bnx){
				if(board[ny][nx]!='O'){
					int red = abs(ny-cur.row)+abs(nx-cur.col);
					int blu = abs(bny-cur.brow)+abs(bnx-cur.bcol);
					if(red>blu){
						ny-=dy[i];
						nx-=dx[i];
					} else {
						bny-=dy[i];
						bnx-=dx[i];
					}
				}
			}
			
			if(!visit[ny][nx][bny][bnx]){
				visit[ny][nx][bny][bnx]=true;
				q.push(Ball(ny,nx,bny,bnx,cur.cnt+1));
			}
		}
	}
	
	printf("-1\n");
}
