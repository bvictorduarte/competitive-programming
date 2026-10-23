#include<bits/stdc++.h>
using namespace std;
int a[30];
int main(){
    int i,v=0,j,k,index;
    string p;
    cin>>p;
    for(i=0;i<(int)p.size();i++)a[p[i]-'A']++;
    if((int)p.size()%2==0){
        for(i=0;i<26;i++){
            if(a[i]%2!=0){
               v=1;
               printf("NO SOLUTION\n");
               break;
            }
        }
        j=2;
        while(j--){
            if(j==1&&v!=1){
                for(i=0;i<26;i++){
                    for(k=0;k<a[i]/2;k++)printf("%c",'A'+i);
                }
            }else if(v!=1){
                for(i=25;i>=0;i--)
                    for(k=0;k<a[i]/2;k++)printf("%c",'A'+i);
            }
        }
    }else{
        for(i=0;i<26;i++){
            if(a[i]%2!=0){
                v++;
                index=i;
                if(v==2){
                    printf("NO SOLUTION\n");
                    break;
                }
            }
        }
        if(v==1){
            j=2;
            while(j--){
                if(j==1){
                    for(i=0;i<26;i++){
                        if(i!=index)
                            for(k=0;k<a[i]/2;k++)printf("%c",'A'+i);
                    }
                    for(k=0;k<a[index];k++)printf("%c",'A'+index);
                }else{
                    for(i=25;i>=0;i--)
                        if(i!=index)
                            for(k=0;k<a[i]/2;k++)printf("%c",'A'+i);
                }
            }
        }
    }
    return 0;
}
