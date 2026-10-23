#include<bits/stdc++.h>
using namespace std;
int queries[10050];
int main(){
    int t,i=1;
    cin>>t;
    while(t--){
        memset(queries,0,sizeof(queries));
        vector<int> c[5],pr[5];
        int q[5]={0}, m=0;
        for(int j=1;j<=3;j++){
            int quant,v;
            cin>>quant;
            while(quant--){
                cin>>v;
                c[j].push_back(v);
                queries[v]++;
            }
        }
        for(int j=1;j<=3;j++){
            for(auto u:c[j])
                if(queries[u]==1){
                    q[j]++;
                    pr[j].push_back(u);
                }
            m=max(q[j],m);
        }
        cout<<"Case #"<<i<<":"<<endl;
        for(int j=1;j<=3;j++)
            if(q[j]==m){
                cout<<j<<" "<<m;
                sort(pr[j].begin(),pr[j].end());
                for(auto u:pr[j])
                    cout<<" "<<u;
                cout<<endl;
            }
        i++;
    }
    return 0;
}