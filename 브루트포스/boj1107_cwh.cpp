#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool button[10];

int chk(int n){
	if(n==0){
		if(button[0]) return 0;
		else return 1;
	}
	int len = 0;
	while(n>0){
		if(button[n%10]) return 0;
		n = n/10;
		len += 1;
	}
	return len;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a;
		cin >> a;
		button[a] = true;
	}
	
	int ans = abs(N-100);
	for(int i=0; i<=1000000; i++){
		int len = chk(i);
		if(len > 0){
			int tmp = abs(N-i);
			ans = min(ans, tmp+len);
		}
	}
	cout << ans << "\n";
}
