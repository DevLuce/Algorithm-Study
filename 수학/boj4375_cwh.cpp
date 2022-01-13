#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(n==EOF) break;

        int num = 1;
        int ans = 1;
        while(num%n!=0){
            num = num*10 + 1;
            num %= n;
            cout << num << endl;
            ans++;
        }
        cout << ans << "\n";
    }
}