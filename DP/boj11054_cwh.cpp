#include <iostream>
#include <algorithm>

using namespace std;

int dpAsc[1001][1001];
int dpDes[1001][1001];
int arr[1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	int ans = 0;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}
	
	// ������ 
	for(int i=0; i<=N; i++){
		int maxAsc = 0;
		int maxDes = 0;
		int lastNum = 0; // ������ �� üũ 
		
		// �������� 
		for(int j=1; j<=i; j++){
			dpAsc[i][j] = 1;
			for(int k=1; k<j; k++){
				if(arr[j] > arr[k]){
					dpAsc[i][j] = max(dpAsc[i][j], dpAsc[i][k]+1);
				}
			}
			if(maxAsc < dpAsc[i][j]) {
				maxAsc = dpAsc[i][j];
				lastNum = arr[j];
			}
		}
		
		// �������� 
		for(int j=i+1; j<=N; j++){
			dpDes[i][j] = 1;
			if(arr[j] == lastNum) dpDes[i][j] = 0;
			for(int k=i+1; k<j; k++){
				if(arr[j] < arr[k]){
					dpDes[i][j] = max(dpDes[i][j], dpDes[i][k]+1);
				}
			}
			if(maxDes < dpDes[i][j]) maxDes = dpDes[i][j];
		}
		
		if(ans < maxAsc + maxDes) ans = maxAsc + maxDes;
	}
	
	cout << ans << "\n";
}
