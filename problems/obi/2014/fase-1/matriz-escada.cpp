    #include<bits/stdc++.h>
    using namespace std;
    int c[505];
    int main(){
        int n,m,i,j,k,a[505][505],y,v2,v3;
        cin>>n>>m;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)scanf("%d", &a[i][j]);
        }
        for(i=0;i<n-1;i++){
            k=0;
            v2=0;
            v3=0;
            while(k<m){
                if(a[i][k]!=0)break;
                k++;
            }
            if(k!=m){
                //printf("\n\npinto %d\n\n", i);
                for(y=k;y>=0;y--){
                    if(c[y]!=1){
                        for(j=i+1;j<n;j++){
                            if(a[j][y]!=0){
                                v2=1;
                                break;
                            }
                        }
                        if(v2==0)c[y]=1;
                        else{
                            printf("N\n");
                            return 0;
                        }
                    }
                }
                //printf("\n\nPINTAO %d\n\n", i);
            }else{
                for(y=i+1;y<n;y++){
                    for(j=0;j<m;j++)
                        if(a[y][j]!=0){
                            printf("N\n");
                            return 0;
                    }
                }
            }
        }
        printf("S\n");
        return 0;
    }
