#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0, resp;
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = i; j <= n; j += i)
                sum += j;
            if(ans < sum){
                ans = sum;
                resp = i;
            }   
        }
        cout << resp << endl;
    }
    return 0;
}