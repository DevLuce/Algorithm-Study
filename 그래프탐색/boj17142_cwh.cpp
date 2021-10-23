#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int lab[50][50];
int N, M;
int ans = 5000;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus;

void calculateTime(){
	queue<pair<int, int>> q;
	int tmpLab[50][50];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			tmpLab[i][j] = lab[i][j];
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(tmpLab[i][j]==0){
				q.push(make_pair(i, j));
			}
		}
	}
	
	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = r+dy[i];
			int nx = c+dx[i];
			if(0<=ny && ny<N && 0<=nx && nx<N && (tmpLab[ny][nx]==-1||tmpLab[ny][nx]==-3)){
				tmpLab[ny][nx]=tmpLab[r][c]+1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	
	int maxTime = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(tmpLab[i][j]>0 && lab[i][j]!=-3){
				maxTime = max(maxTime, tmpLab[i][j]);
			} else if(tmpLab[i][j]==-1){
				return;
			}
		}
	}
	ans = min(ans, maxTime);
}

void dfs(int cnt, int idx){
	if(cnt==M){
		calculateTime();
		return;
	}
	
	for(int i=idx; i<virus.size(); i++){
		int r = virus[i].first;
		int c = virus[i].second;
		lab[r][c]=0;
		dfs(cnt+1, i+1);
		lab[r][c]=-3;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int a;
			cin >> a;
			if(a==2){
				lab[i][j]=-3; // ¹ÙÀÌ·¯½º
				virus.push_back(make_pair(i, j));
			} else if(a==1){
				lab[i][j]=-2; // º® 
			} else {
				lab[i][j]=-1; // ºó Ä­ 
			}
		}
	}
	
	dfs(0, 0);
	
	if(ans==5000){
		cout << -1 << "\n";
	} else {
		cout << ans << "\n";	
	}
}

