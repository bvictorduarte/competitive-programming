#include<bits/stdc++.h>
using namespace std;
map<string,int> mp,mpap,mpv;
const int MAXN=150;
int sl[MAXN],sc[MAXN];
string grid[MAXN][MAXN];
pair<int,string> apl[MAXN],apc[MAXN];
int main(){
    int l,c;
    for(int i=0;i<26;i++){
        string a;
        a.push_back('a'+i);
        for(int j=0;j<26;j++){
            a.push_back('a'+j);
            mp[a]=0;
            mpap[a]=0;
            mpv[a]=0;
        }
    }
    cin>>l>>c;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>>grid[i][j];
            mpap[grid[i][j]]++;
            if(mpap[grid[i][j]]==1){
            apl[i]=make_pair(1,grid[i][j]);
            apc[j]=make_pair(1,grid[i][j]);
            continue;
            }
            apl[i].first++;
            apc[i].first++;
        }
        cin>>sl[i];
    }
    sort(&apl[1],&apl[l]);
    sort(&apc[1],&apc[c]);
    for(int i=1;i<=c;i++)
        cin>>sc[i];
    int cont=0;
    return 0;
}