#include<bits/stdc++.h>
using namespace std;
set<string> pref;
vector<string> l[105],prefv;
const int INF=0x3f3f3f3f;
int dp[105][105],a[105];
int main(){
    string t;
    cin>>t;
    string p="";
    prefv.push_back(p);
    for(int i=0;i<(int)t.size();i++){
        p+=t[i];
        pref.insert(p);
        prefv.push_back(p);
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=1;j<=a;j++){
            string k;
            cin>>k;
            l[i].push_back(k);
        }
    }
    p="";
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            dp[i][j]=INF;
    for(int i=1;i<=(int)t.size();i++){
        p+=t[i-1];
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            for(auto s:l[j])
                if(s==p)
                    dp[i][j]=1;
                else if((int)p.size()>(int)s.size()&&pref.find(prefv[i-(int)s.size()]+s)!=pref.end())
                    dp[i][j]=min(dp[i-(int)s.size()][j-1]+1,dp[i][j]);
        }
    }
    if(dp[(int)t.size()][n]==INF)
        cout<<-1<<endl;
    else
        cout<<dp[(int)t.size()][n];
    return 0;
}