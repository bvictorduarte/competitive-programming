 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 const int maxn=2e5+50;
 ll freq[maxn];
 int main(){
    ll n,a,ans=0,sum_remainder=0;
    cin>>n;
    freq[0]=1;
    for(int i=0;i<n;i++){
        cin>>a;
        ll remain;
        remain=a%n;
        if(remain<0)
            remain+=n;
        sum_remainder+=remain;
        sum_remainder%=n;
        ans+=freq[sum_remainder];
        freq[sum_remainder]++;
    }
    cout<<ans<<endl;
    return 0;
 }