#include <iostream>

using namespace std;

int dp[201][201];
int N, K;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	
	for(int i=0; i<=N; i++){
		for(int j=1; j<=K; j++){
			if(j==1) dp[i][j] = 1;
			else{
				for(int k=0; k<=i; k++){
					dp[i][j] = (dp[i][j] + dp[k][j-1]) % 1000000000;
				}
			}
		}
	}
	
	cout << dp[N][K] << "\n";
}
