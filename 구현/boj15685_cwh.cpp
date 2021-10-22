#include <iostream>
#include <vector>

using namespace std;

int board[101][101];
vector<pair<int, int>> genInfo;

void makeGen(int g){
	if(genInfo.size()<(1<<(g-1))){
		makeGen(g-1);
	}
	
	int curIdx = genInfo.size()-1;
	while(curIdx>=0){
		int x = genInfo[curIdx].first;
		int y = -genInfo[curIdx].second;
		genInfo.push_back(make_pair(y, x));
		curIdx--;
	}
}

void dragonCurve(int x, int y, int d, int g){
	int cnt = 1<<g;
	
	board[y][x]=1;
	int ny=y;
	int nx=x;
	
	for(int i=0; i<cnt; i++){
		switch(d){
			case 0:
				ny += genInfo[i].first;
				nx += genInfo[i].second;
				break;
			case 1:
				ny -= genInfo[i].second;
				nx += genInfo[i].first;
				break;
			case 2:
				ny -= genInfo[i].first;
				nx -= genInfo[i].second;
				break;
			case 3:
				ny += genInfo[i].second;
				nx -= genInfo[i].first;
				break;
		}
		board[ny][nx]=1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;	
	cin >> N;
	
	genInfo.push_back(make_pair(0, 1));
	
	for(int i=0; i<N; i++){
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		
		if(genInfo.size()<(1<<g)){
			makeGen(g);
		}
		
		dragonCurve(x, y, d, g);
	}
	
	int ans=0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(board[i][j]==1 && board[i][j+1]==1 && board[i+1][j]==1 && board[i+1][j+1]){
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
}
