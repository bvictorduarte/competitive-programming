#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
int main(){
    int h,w,n,cont=0;
    cin>>h>>w>>n;
    string c;
    vector<string> grid;
    cin>>c;
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }
    for(int i=0;i<(int)grid.size();i++){
        for(int j=0;j<(int)grid[i].size();j++){
            bool confere=true;
            int ver=i,hori=j;
            if(grid[ver][hori]=='#')continue;
            for(int k=0;k<(int)c.size();k++){
                if(c[k]=='L'&&grid[ver][hori-1]=='#'){
                    confere=false;
                    break;
                }else if(c[k]=='L'&&grid[ver][hori-1]=='.')hori--;
                else if(c[k]=='R'&&grid[ver][hori+1]=='#'){
                    confere=false;
                    break;
                }else if(c[k]=='R'&&grid[ver][hori+1]=='.')hori++;
                else if(c[k]=='U'&&grid[ver-1][hori]=='#'){
                    confere=false;
                    break;
                }else if(c[k]=='U'&&grid[ver-1][hori]=='.')ver--;
                else if(c[k]=='D'&&grid[ver+1][hori]=='#'){
                    confere=false;
                    break;
                }else if(c[k]=='D'&&grid[ver+1][hori]=='.')ver++;
            }
            if(confere)cont++;
        }
    }
    cout<<cont<<endl;
    return 0;
}