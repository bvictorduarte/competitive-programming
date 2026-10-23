#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int max_a = -1;
        vector<int> v;
        int posi;
        for(int i = 1; i <= k; i++){
            int a;
            cin >> a;
            if(max_a < a){
                max_a = a;
                posi = i - 1;
            }
            v.push_back(a);
        }
        int ans = 0;
        for(int i = 0; i < k; i++)
            if(i != posi && v[i] != 1)
                ans += v[i] - 1;
        ans += n - max_a;
        cout << ans << endl;
    }


    return 0;
}