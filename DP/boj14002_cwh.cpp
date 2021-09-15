#include <iostream>
#include <vector>

using namespace std;

int arr[1000];
vector<int> dp[1000];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];

		dp[i].push_back(arr[i]);
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				if(dp[i].size()<dp[j].size()+1){
					dp[i].clear();
					dp[i] = dp[j];
					dp[i].push_back(arr[i]);
				}
			}	
		}
		if(ans.size() < dp[i].size()) ans = dp[i];
	}
	
	cout << ans.size() << "\n";
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

