#include<bits/stdc++.h>
using namespace std;
vector<int> v,v1,v2;
int main(){
    int n,k;
    bool c1=true;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        if(a!=2&&a!=1)
            c1=false;
        else if(a==1)
            v1.push_back(1);
        else
            v2.push_back(2);
    }
    if(c1){
        int ans=0;
        for(int i=0;i<k;i++){
            if((int)v1.size()>=2){
                v1.pop_back();
                v1.pop_back();
                if(!v2.empty())
                    v2.pop_back();
                else
                    v1.pop_back();
            }
            else if((int)v2.size()>=3){
                v2.pop_back();
                v2.pop_back();
                v2.pop_back();
            }else{
                v1.pop_back();
                v2.pop_back();
                v2.pop_back();
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}