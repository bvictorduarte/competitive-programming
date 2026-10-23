#include <bits/stdc++.h>
using namespace std;
int v[550];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ordenado=true;
        vector<int> vord;
        for(int i=0;i<n;i++){
            scanf("%d", &v[i]);
            vord.push_back(v[i]);
        }
        sort(vord.begin(),vord.end());
        int min_dif=v[1]-v[0];
        for(int i=0;i<n-1;i++){
            if(vord[i]!=v[i]){
                printf("0\n");
                ordenado=false;
                break;
            }
            min_dif=min(min_dif,v[i+1]-v[i]);
        }
        if(!ordenado)continue;
        printf("%d\n",min_dif/2+1);
        vord.erase(vord.begin(),vord.end());
    }
    return 0;
}