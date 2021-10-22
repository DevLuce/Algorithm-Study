#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
int lad[11][31];

int ans = 4;

bool isCorrect(){
	for(int i=1; i<=N; i++){
		int curLine=i;
		int curHor=1;
		while(curHor<=H){
			if(lad[curLine][curHor]==1){
				curLine++;
			} else if(lad[curLine-1][curHor]==1){
				curLine--;
			}
			curHor++;
		}
		if(i!=curLine) return false;
	}
	return true;
}

void dfs(int cnt, int ci, int cj){
	if(cnt>=ans){
		return;
	}
	
	if(isCorrect()){
		ans = min(ans, cnt);
	}
	
	for(int i=ci; i<N; i++){
		for(int j=cj; j<=H; j++){
			if(i==1){
				if(lad[i][j]==0 && lad[i+1][j]==0){
					lad[i][j]=1;
					dfs(cnt+1, i, j);
					lad[i][j]=0;
				}
			} else {
				if(lad[i][j]==0 && lad[i+1][j]==0){
					lad[i][j]=1;
					dfs(cnt+1, i, j);
					lad[i][j]=0;
				}
				if(lad[i][j]==0 && lad[i-1][j]==0){
					lad[i-1][j]=1;
					dfs(cnt+1, i, j);
					lad[i-1][j]=0;
				}
			}		
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> H;
	
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		lad[b][a] = 1;
	}
	
	dfs(0, 1, 1);
	if(ans>3){
		cout << -1 << "\n";
	} else {
		cout << ans << "\n";	
	}
}
