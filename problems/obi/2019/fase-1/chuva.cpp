#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    string linha[550];
    for(int i=0;i<n;i++)
        cin>>linha[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0)
                if(linha[i-1][j]=='o'&&linha[i][j]=='.')
                    linha[i][j]='o';
            if(linha[i][j]=='o'){
                if(j<m-1&&i<n-1)
                    if(linha[i+1][j]=='#')
                        linha[i][j+1]='o';
                if(j>0&&i<n-1){
                    int k=0;
                    while(j-k>0&&linha[i][j-k]=='o'){
                        if(linha[i+1][j-k]=='#'&&linha[i][j-k-1]=='.')
                            linha[i][j-k-1]='o';
                        k++;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<linha[i];
        printf("\n");
    }
}
