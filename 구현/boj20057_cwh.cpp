#include <iostream>

using namespace std;

int N;
int A[500][500];
int ans = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int ddy[4] = {-1, 1, 1, -1};
int ddx[4] = {-1, -1, 1, 1};

void moveSand(int r, int c, int d){
	int sand = A[r][c];
	A[r][c]=0;
	int tmp = 0;
	
	int ty = r+(dy[(d+3)%4]*2);
	int tx = c+(dx[(d+3)%4]*2);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.02);
	} else {
		ans+=(int)(sand*0.02);
	}
	tmp+=(int)(sand*0.02);
	
	ty = r+(ddy[d]);
	tx = c+(ddx[d]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.1);
	} else {
		ans+=(int)(sand*0.1);
	}
	tmp+=(int)(sand*0.1);
	
	ty = r+(dy[(d+3)%4]);
	tx = c+(dx[(d+3)%4]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.07);
	} else {
		ans+=(int)(sand*0.07);
	}
	tmp+=(int)(sand*0.07);
	
	ty = r+(ddy[(d+3)%4]);
	tx = c+(ddx[(d+3)%4]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.01);
	} else {
		ans+=(int)(sand*0.01);
	}
	tmp+=(int)(sand*0.01);
	
	ty = r+(dy[d]*2);
	tx = c+(dx[d]*2);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.05);
	} else {
		ans+=(int)(sand*0.05);
	}
	tmp+=(int)(sand*0.05);
	
	ty = r+(ddy[(d+1)%4]);
	tx = c+(ddx[(d+1)%4]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.1);
	} else {
		ans+=(int)(sand*0.1);
	}
	tmp+=(int)(sand*0.1);
	
	ty = r+(dy[(d+1)%4]);
	tx = c+(dx[(d+1)%4]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.07);
	} else {
		ans+=(int)(sand*0.07);
	}
	tmp+=(int)(sand*0.07);
	
	ty = r+(ddy[(d+2)%4]);
	tx = c+(ddx[(d+2)%4]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.01);
	} else {
		ans+=(int)(sand*0.01);
	}
	tmp+=(int)(sand*0.01);
	
	ty = r+(dy[(d+1)%4]*2);
	tx = c+(dx[(d+1)%4]*2);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(int)(sand*0.02);
	} else {
		ans+=(int)(sand*0.02);
	}
	tmp+=(int)(sand*0.02);
	
	ty = r+(dy[d]);
	tx = c+(dx[d]);
	if(0<=ty && ty<N && 0<=tx && tx<N){
		A[ty][tx]+=(sand-tmp);
	} else {
		ans+=(sand-tmp);
	}
}

void tornado(){
	int r=N/2, c=N/2;
	
	int ny=r, nx=c;
	int cnt=0;
	while(ny!=0||nx!=0){
		while(r-ny!=c-nx-1 && (ny!=0||nx!=0)){
			moveSand(ny, --nx, 0);
		}
		while(ny-r!=c-nx && (ny!=0||nx!=0)){
			moveSand(++ny, nx, 1);
		}
		while(ny-r!=nx-c && (ny!=0||nx!=0)){
			moveSand(ny, ++nx, 2);
		}
		while(r-ny!=nx-c && (ny!=0||nx!=0)){
			moveSand(--ny, nx, 3);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	
	// 토네이도 이동
	tornado();
	
	cout << ans << "\n";
}
