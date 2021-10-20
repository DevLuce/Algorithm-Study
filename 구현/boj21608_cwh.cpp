#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};
int classroom[20][20];
int student[400][4];
int N;

void setLoc(int s){
	priority_queue<tuple<int, int, int, int>> pq;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(classroom[i][j]==0){
				int zeroCnt=0;
				int friendCnt=0;
				for(int k=0; k<4; k++){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(0<=ny && ny<N && 0<=nx && nx<N){
						if(classroom[ny][nx]==0){
							zeroCnt++;
						} else {
							for(int l=0; l<4; l++){
								if(classroom[ny][nx]==student[s-1][l]){
									friendCnt++;
									break;
								}
							}
						}
					}
				}
				pq.push({friendCnt, zeroCnt, -i, -j});	
			}
		}
	}
	
	int a, b, r, c;
	tie(a,b,r,c) = pq.top();
	pq.pop(); 
	
	classroom[-r][-c]=s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	for(int i=0; i<N*N; i++){
		int s;
		cin >> s >> student[s-1][0] >> student[s-1][1] >> student[s-1][2] >> student[s-1][3];
		setLoc(s);
	}
	
	int score=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int num = classroom[i][j];
			int friendCnt=0;
			for(int k=0; k<4; k++){
				int ny=i+dy[k];
				int nx=j+dx[k];
				if(0<=ny && ny<N && 0<=nx && nx<N){
					for(int l=0; l<4; l++){
						if(classroom[ny][nx]==student[num-1][l]){
							friendCnt++;
							break;
						}
					}
				}
			}
			switch(friendCnt){
				case 0:
					break;
				case 1:
					score+=1;
					break;
				case 2:
					score+=10;
					break;
				case 3:
					score+=100;
					break;
				case 4:
					score+=1000;
					break;
			}
		}
	}
	
	cout << score << "\n";
}
