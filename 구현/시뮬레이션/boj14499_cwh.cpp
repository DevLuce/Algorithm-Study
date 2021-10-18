#include <iostream>

using namespace std;

int loc[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0}; // ��, ��, ��, ��, ��, ��  
int N, M, x, y;

int moveDice(int typ){
	switch(typ){
		case 1: // ������ �̵� 
			if(y+1<M){
				int tmp = dice[0];
				dice[0] = dice[1]; // �� -> �� 
				dice[1] = dice[5]; // �� -> �� 
				dice[5] = dice[2]; // �� -> ��
				dice[2] = tmp; // �� -> �� 
				y++;
			} else {
				return -1;
			}
			break;
		case 2: // ���� �̵� 
			if(0<=y-1){
				int tmp = dice[0];
				dice[0] = dice[2]; // �� -> �� 
				dice[2] = dice[5]; // �� -> �� 
				dice[5] = dice[1]; // �� -> �� 
				dice[1] = tmp; // �� -> �� 
				y--;
			} else {
				return -1;
			}
			break;
		case 3: // ������ �̵� 
			if(0<=x-1){
				int tmp = dice[0];
				dice[0] = dice[3]; // �� -> �� 
				dice[3] = dice[5]; // �� -> �� 
				dice[5] = dice[4]; // �� -> �� 
				dice[4] = tmp; // �� -> �� 
				x--;
			} else {
				return -1;
			}
			break;
		case 4: // ������ �̵� 
			if(x+1<N){
				int tmp = dice[0];
				dice[0] = dice[4]; // �� -> �� 
				dice[4] = dice[5]; // �� -> �� 
				dice[5] = dice[3]; // �� -> �� 
				dice[3] = tmp; // �� -> ��  
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
