#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[50][50];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int>> cloud;
vector<pair<int, int>> copyQ;

void copyWater(){
	for(int w=0; w<copyQ.size(); w++){
		int r = copyQ[w].first;
		int c = copyQ[w].second;
		
		for(int i=1; i<8; i=i+2){
			int ny = r+dy[i];
			int nx = c+dx[i];
			if(0<=ny && ny<N && 0<=nx && nx<N && A[ny][nx]>0){
				A[r][c]+=1;
			}
		}
	}
}

void moveCloud(int d, int s){
	for(int i=0; i<cloud.size(); i++){
		int r = cloud[i].first;
		int c = cloud[i].second;
		
		int ny = (r+N+(dy[d-1]*s%N))%N;
		int nx = (c+N+(dx[d-1]*s%N))%N;
		A[ny][nx]+=1;
		copyQ.push_back(make_pair(ny, nx));
	}
	cloud.clear();
}

void createCloud(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i][j]>=2){
				bool isExist=false;
				for(int k=0; k<copyQ.size(); k++){
					if(i==copyQ[k].first && j==copyQ[k].second){
						isExist=true;
						break;
					}
				}
				if(isExist) continue;
				A[i][j]-=2;
				cloud.push_back(make_pair(i, j));
			}
		}
	}
	copyQ.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	
	cloud.push_back(make_pair(N-1, 0));
	cloud.push_back(make_pair(N-1, 1));
	cloud.push_back(make_pair(N-2, 0));
	cloud.push_back(make_pair(N-2, 1));
	
	for(int i=0; i<M; i++){
		int d, s;
		cin >> d >> s;
		
		// 구름 이동
		moveCloud(d, s);
		// 물 복사
		copyWater(); 
		
		// 구름 생성
		createCloud();
	}
	
	int ans=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ans+=A[i][j];
		}
	}
	
	cout << ans << "\n";
}
