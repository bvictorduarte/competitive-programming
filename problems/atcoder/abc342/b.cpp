#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int v[105];
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,pa,pb;
        cin>>a>>b;
        for(int k=1;k<=n;k++){
            if(a==v[k])
                pa=k;
            if(b==v[k])
                pb=k;
        }
        if(pa<pb)
            cout<<a<<endl;
        else
            cout<<b<<endl;
    }
    return 0;
}