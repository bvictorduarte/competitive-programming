#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,v=0,aux;
    vector<int> a,s1,s2;
    cin>>n;
    for(i=1;i<=n;i++)a.push_back(i);
    if((n%4)==0||(n%4)==3){
        printf("YES\n");
        if(n%4!=0){
            n++;
            v=1;
        }
        int k=0;
        for(i=1;i<=n/4;i++){
            s1.push_back(a[k]);
            s1.push_back(a[n-1-k]);
            k=k+2;
        }
        k=1;
        for(i=1;i<=(n/4);i++){
            s2.push_back(a[k]);
            s2.push_back(a[n-1-k]);
            k=k+2;
        }
        if(v){
            s1[1]=-1;
            aux=s1[0];
            s1[0]=s2[(n/2)-1];
            s2[(n/2)-1]=aux;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(v){
            printf("%d\n", n/2);
            for(i=0;i<n/2;i++){
                if(i!=(n/2)-1)
                    printf("%d ", s2[i]);
                else
                    printf("%d\n", s2[i]);
            }
            printf("%d\n", (n/2)-1);
            for(i=0;i<n/2;i++){
                if(s1[i]!=-1){
                    if(i!=(n/2)-1)
                        printf("%d ", s1[i]);
                    else
                        printf("%d\n", s1[i]);
                }
            }
        }else{
            printf("%d\n", n/2);
            for(i=0;i<n/2;i++){
                if(s1[i]!=-1){
                    if(i!=(n/2)-1)
                        printf("%d ", s1[i]);
                    else
                        printf("%d\n", s1[i]);
                }
            }
            printf("%d\n", n/2);
            for(i=0;i<n/2;i++){
                if(i!=(n/2)-1)
                    printf("%d ", s2[i]);
                else
                    printf("%d\n", s2[i]);
            }
        }
    }else printf("NO\n");
    return 0;
}
