#include<bits/stdc++.h>
using namespace std;
int mod(int a){
    if(a>0)return a;
    return -a;
}
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        vector<int> v;
        set<int> seq;
        bool jolly=true;
        int a;
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            v.push_back(a);
        }
        for(int i=1;i<=n-1;i++){
            if((mod(v[i]-v[i-1])<1||mod(v[i]-v[i-1])>n-1)||seq.find(mod(v[i]-v[i-1]))!=seq.end()){
                jolly=false;
                break;
            }else
                seq.insert(mod(v[i]-v[i-1]));
        }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}