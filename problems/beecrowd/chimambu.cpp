#include <bits/stdc++.h>
using namespace std;
const long long m=1e9+9;
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans=0;
    long long n,q;
    cin>>n>>q;
    long long a,b;
    long long t=binpow((long long)2,n);
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        vector<long long> aa, bbb;
        set<long long> bb;
        long long p=t;
        aa.push_back(a);
        bb.insert(b);
        bbb.push_back(b);
        while(aa[(int)aa.size()-1]!=0){
            a=((long long)2*a)%t;
            aa.push_back(a);
        }
        while(1){
            b=((long long)2*b)%t;
            bb.insert(b);
            bbb.push_back(b);
            if(b==0)
                break;
        }
        int v=0;
        for(long long j=0;j<(long long)aa.size();j++){
            if(bb.find(aa[j]) != bb.end())
                v = aa[j];
            if(v)
             break;
        }
        v=false;
        for(long long j=0;j<(long long)bb.size();j++){
            for(long long k=0;k<(long long)aa.size();k++)
                if(aa[j]==bb[k]){
                    p=min(k+j,p);
                    v=true;
                    break;
                }
            if(v)
             break;
        }
        ans+=(p%m)*(binpow(n,i-1)%m);
        a%=m;



    }
    cout<<ans<<endl;
    return 0;
}