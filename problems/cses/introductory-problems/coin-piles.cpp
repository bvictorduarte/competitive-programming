#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(((2*a-b)>=0)&&((2*b-a)>=0)&&(((2*a-b)%3)==0)&&(((2*b-a)%3)==0))printf("YES\n");
        else printf("NO\n");
    }
}
