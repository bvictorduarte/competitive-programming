#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+50;
char m1[maxn][maxn],m2[maxn][maxn],lixo;
void solve(){
    int n,cont=0;
    scanf("%d", &n);
    fflush(stdin);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c", &m1[i][j]);
            m2[j][n-i-1]=m1[i][j];
        }
        scanf("%c", &lixo);
    }
    for(int i=0;i*2<n;i++)
        for(int j=0;j*2<n;j++){
            char charmax;
            charmax=max(m1[i][j],m2[i][j]);
            charmax=max(charmax,m1[j][n-i-1]);
            charmax=max(charmax,m2[n-j-1][i]);
            cont+=4*(int)charmax-((int)m1[i][j]+(int)m2[i][j]+(int)m1[j][n-i-1]+(int)m2[n-j-1][i]);
        }
    printf("%d\n", cont);
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}