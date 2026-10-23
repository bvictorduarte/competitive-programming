#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int freq[maxn];
int sum_dig(int x){
    int sum=0;
    while(x){
        sum+=(x%10);
        x/=10;
    }
    return sum;
}
int main(){
    int n,k,m=-1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        m=max(m,a);
        freq[a]++;
    }
    int abelhas=0,j=m;
    while(j>=0){
        if(freq[j]+abelhas<k){
            abelhas+=freq[j];
            freq[j-sum_dig(j)]+=freq[j];
        }else{
            cout<<sum_dig(j)<<endl;
            return 0;
        }
        j--;
    }
    cout<<0<<endl;
    return 0;
}