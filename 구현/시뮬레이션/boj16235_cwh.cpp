#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int yard[10][10];
int A[10][10];
vector<int> trees[10][10];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M,K;
	int ans=0;
	cin >> N >> M >> K;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			yard[i][j]=5;
			cin >> A[i][j];
		}
	}
	
	for(int i=0; i<M; i++){
		int x, y, z;
		cin >> x >> y >> z;
		trees[x-1][y-1].push_back(z);
	}
	
	while(K>0){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				sort(trees[i][j].begin(), trees[i][j].end());
				for(int k=0; k<trees[i][j].size(); k++){
					if(yard[i][j]>=trees[i][j][k]){
						yard[i][j]-=trees[i][j][k];
						trees[i][j][k]++;
					} else {
						trees[i][j][k] = -trees[i][j][k];
					}
				}
			}
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				sort(trees[i][j].begin(), trees[i][j].end(), greater<int>());
				for(int k=trees[i][j].size()-1; k>=0; k--){
					if(trees[i][j][k]<=0){
						yard[i][j] += (-1)*(trees[i][j][k])/2;
						trees[i][j].pop_back();
					} else{
						break;
					}	
				}
			}
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<trees[i][j].size(); k++){
					if(trees[i][j][k]%5==0){
						for(int l=0; l<8; l++){
							int ny = i+dy[l];
							int nx = j+dx[l];
							if(0<=ny && ny<N && 0<=nx && nx<N){
								trees[ny][nx].push_back(1);
							}
						}
					}
				}
			}
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				yard[i][j] += A[i][j];
			}
		}
		
		K--;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<trees[i][j].size(); k++){
				if(trees[i][j][k]>0){
					ans++;
				}
			}
		}
	}
	
	cout << ans << "\n";
}
