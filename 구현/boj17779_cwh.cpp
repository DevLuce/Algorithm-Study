#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[20][20];
int ans = 40000;

void divideCity(int r, int c, int d1, int d2){
	int city[20][20]={{0,}};
	int cnt[5]={0,};
		
	// 1. 경계선 칠하기 
	for(int i=0; i<=d1; i++){
		city[r+i][c-i] = 5;
		city[r+d2+i][c+d2-i] = 5;
	}
	for(int i=0; i<=d2; i++){
		city[r+i][c+i] = 5;
		city[r+d1+i][c-d1+i] = 5;
	}

	// 2. 선거구 나누기
	// 1
	for(int i=0; i<r+d1; i++){
		for(int j=0; j<=c; j++){
			if(city[i][j]==5) break;
			city[i][j]=1;
		}
	}
	// 2
	for(int i=0; i<=r+d2; i++){
		for(int j=N-1; j>c; j--){
			if(city[i][j]==5) break;
			city[i][j]=2;
		}
	}
	// 3
	for(int i=r+d1; i<N; i++){
		for(int j=0; j<c-d1+d2; j++){
			if(city[i][j]==5) break;
			city[i][j]=3;
		}
	}
	// 4
	for(int i=r+d2+1; i<N; i++){
		for(int j=N-1; j>=c-d1+d2; j--){
			if(city[i][j]==5) break;
			city[i][j]=4;
		}
	}
	// 5
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(city[i][j]==0){
				city[i][j]=5;
				cnt[4]+=A[i][j];
			} else if(city[i][j]==1){
				cnt[0]+=A[i][j];
			} else if(city[i][j]==2){
				cnt[1]+=A[i][j];
			} else if(city[i][j]==3){
				cnt[2]+=A[i][j];
			} else if(city[i][j]==4){
				cnt[3]+=A[i][j];
			} else {
				cnt[4]+=A[i][j];
			}
		}
	}
	
	// 3. 최솟값 찾 기 
	sort(cnt, cnt+5);
	ans = min(ans, cnt[4]-cnt[0]);
}

void setBoundary(){
	for(int i=0; i<N-2; i++){
		for(int j=1; j<N-1; j++){
			for(int d1=1; 0<=j-d1; d1++){
				for(int d2=1; j+d2<N && i+d1+d2<N; d2++){
					divideCity(i, j, d1, d2);
				}
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
			cin >> A[i][j];
		}
	}
	
	setBoundary();
	
	cout << ans << "\n";
}
