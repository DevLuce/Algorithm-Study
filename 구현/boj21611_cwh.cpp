#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[49][49];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int my[4] = {1, 0, -1, 0};
int mx[4] = {0, 1, 0, -1};
int score = 0; 

void destroyBead(int d, int s){
	int r=N/2, c=N/2;
	while(s>0){
		r+=dy[d-1];
		c+=dx[d-1];
		A[r][c]=-1;
		s--;
	}
}

bool checkMinus(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i][j]==-1){
				return true;
			}
		}
	}
	return false;
}

void moveBead(){
	int r = N/2;
	int c = N/2-1;
	int m = 0;
	
	while(r!=0 || c!=0){
		switch(m){
			case 0:
				if(r-(N/2)==(N/2)-c){
					m++;
				} else {
					if(A[r][c]==-1){
						A[r][c]=A[r+1][c];
						A[r+1][c]=-1;
					}
					r++;
				}
				break;
			case 1:
				if(r-(N/2)==c-(N/2)){
					m++;
				} else {
					if(A[r][c]==-1){
						A[r][c]=A[r][c+1];
						A[r][c+1]=-1;
					}
					c++;
				}
				break;
			case 2:
				if((N/2)-r==c-(N/2)){
					m++;
				} else {
					if(A[r][c]==-1){
						A[r][c]=A[r-1][c];
						A[r-1][c]=-1;
					}
					r--;
				}
				break;
			case 3:
				if((N/2)-r==(N/2)-c-1){
					m=0;
				} else {
					if(A[r][c]==-1){
						A[r][c]=A[r][c-1];
						A[r][c-1]=-1;
					}
					c--;
				}
				break;
		}
	}
	if(A[r][c]==-1) A[r][c]=0;
}

void explodeBead(){
	int curNum = 0;
	int r = N/2;
	int c = N/2-1;
	vector<pair<int, int>> group;
	int m = 0;
	
	while(r!=0 || c!=0){
		if(group.size()==0){
			curNum = A[r][c];
			group.push_back(make_pair(r, c));
		} else {
			if(curNum==A[r][c]){
				group.push_back(make_pair(r,c));
			} else {
				if(group.size()>=4){
					score+=(curNum*group.size());
					for(int i=0; i<group.size(); i++){
						// Æø¹ß
						A[group[i].first][group[i].second]=-1;
					}
				}
				curNum = A[r][c];
				group.clear();
				group.push_back(make_pair(r,c));
			}
		}
		
		switch(m){
			case 0:
				if(r-(N/2)==(N/2)-c){
					m++;
					c++;
				} else {
					r++;
				}
				break;
			case 1:
				if(r-(N/2)==c-(N/2)){
					m++;
					r--;
				} else {
					c++;
				}
				break;
			case 2:
				if((N/2)-r==c-(N/2)){
					m++;
					c--;
				} else {
					r--;
				}
				break;
			case 3:
				if((N/2)-r==(N/2)-c-1){
					m=0;
					r++;
				} else {
					c--;
				}
				break;
		}
	}
	
	if(curNum==A[r][c]){
		group.push_back(make_pair(r,c));
	} 
	if(curNum!=0 && group.size()>=4){
		score+=(curNum*group.size());
		for(int i=0; i<group.size(); i++){
			// Æø¹ß
			A[group[i].first][group[i].second]=-1;
		}
	}
	group.clear();
}

void changeBead(){
	vector<pair<int, int>> bd;
	
	int curNum = 0;
	int r = N/2;
	int c = N/2-1;
	int m = 0;
	
	while(r!=0 || c!=0){
		if(A[r][c]==0){
			break;
		}
		if(A[r][c]==curNum){
			bd[bd.size()-1].first += 1;
		} else {
			curNum = A[r][c];
			bd.push_back(make_pair(1, curNum));
		}
				
		switch(m){
			case 0:
				if(r-(N/2)==(N/2)-c){
					m++;
					c++;
				} else {
					r++;
				}
				break;
			case 1:
				if(r-(N/2)==c-(N/2)){
					m++;
					r--;
				} else {
					c++;
				}
				break;
			case 2:
				if((N/2)-r==c-(N/2)){
					m++;
					c--;
				} else {
					r--;
				}
				break;
			case 3:
				if((N/2)-r==(N/2)-c-1){
					m=0;
					r++;
				} else {
					c--;
				}
				break;
		}
	}
	if(A[r][c]!=0){
		if(A[r][c]==curNum){
			bd[bd.size()].first += 1;
		} else {
			curNum = A[r][c];
			bd.push_back(make_pair(1, curNum));
		}	
	}
	
	r = N/2;
	c = N/2-1;
	m = 0;
	int flag=0;
	int idx=0;
	
	while((r!=0 || c!=0) && idx<bd.size()){
		if(flag==0){
			A[r][c] = bd[idx].first;
			flag=1;	
		} else {
			A[r][c] = bd[idx].second;
			flag=0;
			idx++;
		}
			
		switch(m){
			case 0:
				if(r-(N/2)==(N/2)-c){
					m++;
					c++;
				} else {
					r++;
				}
				break;
			case 1:
				if(r-(N/2)==c-(N/2)){
					m++;
					r--;
				} else {
					c++;
				}
				break;
			case 2:
				if((N/2)-r==c-(N/2)){
					m++;
					c--;
				} else {
					r--;
				}
				break;
			case 3:
				if((N/2)-r==(N/2)-c-1){
					m=0;
					r++;
				} else {
					c--;
				}
				break;
		}
	}
	
	if(idx<bd.size()){
		if(flag==0){
			A[r][c] = bd[idx].first;
		} else {
			A[r][c] = bd[idx].second;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	
	for(int i=0; i<M; i++){
		int d, s;
		cin >> d >> s;
		
		// ±¸½½ ÆÄ±«
		destroyBead(d, s);
		
		while(true){
			// ÀÌµ¿
			while(checkMinus()){
				moveBead();
			}
			// Æø¹ß
			explodeBead();
			if(!checkMinus()) break;
		}
		
		// º¯È­
		changeBead();
	}
	
	cout << score << endl;
}
