#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;;
int v[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        int n,r;
        cin>>n;
        cin>>v[0];
        vector<int> tin,tout;
        tin.push_back(0);
        r=v[0];
        for(int i=1;i<n;i++){
            cin>>v[i];
            if(v[i]!=r){
                tout.push_back(i-1);
                tin.push_back(i);
                r=v[i];
            }
        }
        tout.push_back(n-1);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            int k=0;
            for(int b=(int)tin.size()/2;b>=1;b/=2)
                while(k+b<(int)tin.size()&&tin[k+b]<=l)k+=b;
            if(tout[k]>=r)
                cout<<-1<<" "<<-1<<endl;
            else if(v[l]!=v[r]){
                cout<<l+1<<" "<<r+1<<endl;
            }else{
                int k=0;
                for(int b=(int)tout.size()/2;b>=1;b/=2)
                    while(k+b<(int)tout.size()&&tout[k+b]<=r)k+=b;
                if(tout[k]!=r)
                    cout<<l+1<<" "<<tout[k]+1<<endl;
                else
                    cout<<l+1<<" "<<tout[k-1]+1<<endl;
            }
        }   
    }
    return 0;
}