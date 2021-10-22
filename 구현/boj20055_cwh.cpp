#include <iostream>

using namespace std;

int N, K;
int A[200];
int robots[200];

void rotateBelt(){
	int tmp=A[2*N-1];
	int tmpR=robots[2*N-1];
	for(int i=2*N-1; i>0; i--){
		A[i]=A[i-1];
		robots[i]=robots[i-1];
	}
	A[0]=tmp;
	robots[0]=tmpR;
	if(robots[N-1]>0){
		robots[N-1]=0;
	}
}

void moveRobot(){
	for(int i=N-1; i>0; i--){
		if(robots[i]==0 && robots[i-1]>0 && A[i]>0){
			robots[i]=robots[i-1];
			robots[i-1]=0;
			A[i]--;
		}
	}
	if(robots[N-1]>0){
		robots[N-1]=0;
	}
}

void liftRobot(){
	if(robots[0]==0 && A[0]>0){
		robots[0]=1;
		A[0]--;
	}
}

bool checkBelt(){
	int cnt=0;
	for(int i=0; i<2*N; i++){
		if(A[i]==0){
			cnt++;
		}
		if(cnt>=K){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	for(int i=0; i<2*N; i++){
		cin >> A[i];
	}
	
	int step=1;
	
	while(true){
		// 벨트 회전
		rotateBelt();
		
		// 로봇 이동
		moveRobot();
		
		// 로봇 올림
		liftRobot();
		
		// 내구도 확인
		if(checkBelt()){
			break;
		}
		step++;
	}
	
	cout << step << "\n";
}
