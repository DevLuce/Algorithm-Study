#include <iostream>

using namespace std;

int loc[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0}; // ¿ß, º≠, µø, ≥≤, ∫œ, πÿ  
int N, M, x, y;

int moveDice(int typ){
	switch(typ){
		case 1: // µø¿∏∑Œ ¿Ãµø 
			if(y+1<M){
				int tmp = dice[0];
				dice[0] = dice[1]; // º≠ -> ¿ß 
				dice[1] = dice[5]; // πÿ -> º≠ 
				dice[5] = dice[2]; // µø -> πÿ
				dice[2] = tmp; // ¿ß -> µø 
				y++;
			} else {
				return -1;
			}
			break;
		case 2: // º≠∑Œ ¿Ãµø 
			if(0<=y-1){
				int tmp = dice[0];
				dice[0] = dice[2]; // µø -> ¿ß 
				dice[2] = dice[5]; // πÿ -> µø 
				dice[5] = dice[1]; // º≠ -> πÿ 
				dice[1] = tmp; // ¿ß -> º≠ 
				y--;
			} else {
				return -1;
			}
			break;
		case 3: // ∫œ¿∏∑Œ ¿Ãµø 
			if(0<=x-1){
				int tmp = dice[0];
				dice[0] = dice[3]; // ≥≤ -> ¿ß 
				dice[3] = dice[5]; // πÿ -> ≥≤ 
				dice[5] = dice[4]; // ∫œ -> πÿ 
				dice[4] = tmp; // ¿ß -> ∫œ 
				x--;
			} else {
				return -1;
			}
			break;
		case 4: // ≥≤¿∏∑Œ ¿Ãµø 
			if(x+1<N){
				int tmp = dice[0];
				dice[0] = dice[4]; // ∫œ -> ¿ß 
				dice[4] = dice[5]; // πÿ -> ∫œ 
				dice[5] = dice[3]; // ≥≤ -> πÿ 
				dice[3] = tmp; // ¿ß -> ≥≤  
				x++;
			} else {
				return -1;
			}
			break;
	}
	if(loc[x][y]==0){
		loc[x][y]=dice[5];
	} else {
		dice[5]=loc[x][y];
		loc[x][y]=0;
	}
	return dice[0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int K;
	cin >> N >> M >> x >> y >> K;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> loc[i][j];
		}
	}
	
	for(int i=0; i<K; i++){
		int op;
		cin >> op;
		int ret = moveDice(op);
		
		if(ret!=-1){
			cout << ret << "\n";
		}
	}
}
