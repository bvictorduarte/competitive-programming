#include <bits/stdc++.h>
#define ll long long int
#define rep(a) for(ll i = 0; i<a; i++)

using namespace std;

int main(){
    ll m, n, l, k;
    while(cin>>m>>n && (m!=0 || n!=0)){
        cin>>l>>k;
        vector<ll> woods(k);
        rep(k) cin>>woods[i];
        if((100*m)%l != 0 && (100*n)%l != 0){
            cout<<"impossivel\n";
            continue;
        }
        sort(woods.begin(), woods.end());
        ll i = 0, j = k-1, num, ans = 0;
        bool flag = false;
        if((100*m)%l == 0){
            num = (100*m)/l;
            while(num != 0 && j > i){
                if(woods[j] == n){
                    num--;
                    ans++;
                    j--;
                }
                else if(woods[j] > n) j--;
                else{
                    auto itr = lower_bound(woods.begin()+i, woods.begin()+j, n-woods[j]);
                    if(itr == woods.begin()+j || *itr != n-woods[j]){
                        j--;
                        continue;
                    }
                    num--;
                    i = itr-woods.begin();
                    i++;
                    j--;
                    ans+=2;
                }
            }
            if(i == j && num == 1 && woods[j] == n){
                num--;
                ans++;
            }
            if(num <= 0){
                flag = true;
                cout<<ans<<'\n';
            }
        }
        i = 0, j = k-1, ans = 0;
        if((100*n)%l == 0 && !flag){
            num = (100*n)/l;
            while(num != 0 && j > i){
                if(woods[j] == m){
                    num--;
                    ans++;
                    j--;
                }
                else if(woods[j] > m) j--;
                else{
                    auto itr = lower_bound(woods.begin()+i, woods.begin()+j, m-woods[j]);
                    if(itr == woods.begin()+j || *itr != m-woods[j]){
                        j--;
                        continue;
                    }
                    num--;
                    i = itr-woods.begin();
                    i++;
                    j--;
                    ans+=2;
                }
            }
            if(i == j && num == 1 && woods[j] == m){
                num--;
                ans++;
            }
            if(num <= 0){
                flag = true;
                cout<<ans<<'\n';
            }
        }
        if(!flag) cout<<"impossivel\n";
    }
}