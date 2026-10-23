#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+50;
vector<int> nu[MAXN],u[MAXN];
int v[4];
int main(){
    int e,m,d;
    cin>>e>>m>>d;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        u[a].push_back(b);
    }
    for(int i=0;i<d;i++){
        int a,b;
        cin>>a>>b;
        nu[a].push_back(b);
    }
    int cont=0;
    for(int i=0;i<e/3;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(auto p:u[a]){
            if(p!=b&&p!=c){
                cont++;
            }
        }
        for(auto p:nu[a]){
            if(p==b||p==c){
                cont++;
            }
        }
        for(auto p:u[b]){
            if(p!=a&&p!=c){
                cont++;
            }
        }
        for(auto p:nu[b]){
            if(p==a||p==c){
                cont++;
            }
        }
        for(auto p:u[c]){
            if(p!=b&&p!=a){
                cont++;
            }
        }
        for(auto p:nu[c]){
            if(p==b||p==a){
                cont++;
            }
        }
    }
    cout<<cont<<endl;
    return 0;
}