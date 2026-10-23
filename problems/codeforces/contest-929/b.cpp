#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int n,s=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
            s+=a;
        }
        if(s%3==0)
            cout<<0;
        else if(s%3==2)
            cout<<1;
        else{
            bool k=true;
            for(auto u:v)
                if(u%3==1){
                    cout<<1;
                    k=false;
                    break;
                }
            if(n>=2&&k)
                cout<<2;
            else if(k)
                cout<<1;
        }
        cout<<endl;
    }



    return 0;
}