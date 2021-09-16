#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int dp[100000][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = -1001;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(i==0) {
			dp[i][0] = arr[i];
			dp[i][1] = arr[i];
		}
		else{
			if(dp[i-1][0]+arr[i]>arr[i]) dp[i][0] = dp[i-1][0]+arr[i];
			else dp[i][0] = arr[i];
			if(dp[i-1][1]+arr[i]>dp[i-1][0]) dp[i][1] = dp[i-1][1]+arr[i];
			else dp[i][1] = dp[i-1][0];
		}
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	
	cout << ans << "\n";
}
