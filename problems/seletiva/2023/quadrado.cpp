#include <bits/stdc++.h>
using namespace std;
int mat[4][4],l[4],c[4];
int lzero[4],czero[4];
int main(){
    int k=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j]==0){
                lzero[k]=i;
                czero[k]=j;
                k++;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                l[i]+=mat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            c[i]+=mat[j][i];
    }

    return 0;
}