#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int n,t,i,h,k;
    string name;
    vector<pair<int, string> > a;
    vector<vector<string> > b;
    scanf("%d%d", &n, &t);
    fflush(stdin);
    rep(i,n){
        cin>>name;
        scanf("%d", &h);
        fflush(stdin);
        a.PB(MP(h,name));
    }
    sort(a.begin(),a.end());
    k=0;
    b.resize(t);
    rep(i,n){
        b[k].PB(a[(int)a.size()-1].S);
        a.pop_back();
        k++;
        if(k==t)k=0;
    }
    rep(i,t)
        sort(b[i].begin(),b[i].end());
    rep(i,t){
        cout<<"Time "<<i+1<<"\n";
        rep(k,(int)b[i].size())cout<<b[i][k]<<"\n";
        cout<<"\n";
    }
    return 0;
}
