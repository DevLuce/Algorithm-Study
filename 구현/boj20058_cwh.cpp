#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N,Q,p;
int A[64][64];
int tmp[64][64];
int tmp2[64][64];
bool visit[64][64];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void rotate(int r, int c, int n){
	int ti=r;
	int tj=c;
	
	for(int j=c; j<c+n; j++){
		tj=c;
		for(int i=r+n-1; i>=r; i--){
			tmp[ti][tj]=A[i][j];
			tj++;
		}
		ti++;
	}
	
	for(int i=r; i<r+n; i++){
		for(int j=c; j<c+n; j++){
			A[i][j]=tmp[i][j];
		}
	}
}

void firestorm(int L){
	int n = pow(2, L);
	
	for(int i=0; i<p; i+=n){
		for(int j=0; j<p; j+=n){
			rotate(i, j, n);
		}
	}
	
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			if(A[i][j]>0){
				int cnt=0;
				for(int k=0; k<4; k++){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(0<=ny && ny<p && 0<=nx && nx<p && A[ny][nx]>0){
						cnt++;
					}
				}
				if(cnt<3){
					tmp2[i][j]=A[i][j]-1;
				} else {
					tmp2[i][j]=A[i][j];
				}
			} else {
				tmp2[i][j]=0;
			}
		}
	}
	
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			A[i][j]=tmp2[i][j];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> Q;
	p = pow(2,N);
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			cin >> A[i][j];
		}
	}
	
	for(int i=0; i<Q; i++){
		int L;
		cin >> L;
		firestorm(L);
	}
	
	int ans = 0;
	int maxSize = 0;
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			ans += A[i][j];
			if(A[i][j]>0 && !visit[i][j]){
				visit[i][j]=true;
				int tmpSize=0;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				
				while(!q.empty()){
					int r=q.front().first;
					int c=q.front().second;
					q.pop();
					tmpSize++;
					
					for(int k=0; k<4; k++){
						int ny=r+dy[k];
						int nx=c+dx[k];
						if(0<=ny && ny<p && 0<=nx && nx<p && A[ny][nx]>0 && !visit[ny][nx]){
							visit[ny][nx]=true;
							q.push(make_pair(ny, nx));
						}	
					}
				}
				maxSize = max(maxSize, tmpSize);
			}
		}
	}
	cout << ans << "\n" << maxSize << "\n";
}
