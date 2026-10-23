#include<bits/stdc++.h>
using namespace std;
int main(){
    int s=0;
    vector<int> v;
    for(int i=0;i<6;i++){
        int a;
        cin>>a;
        v.push_back(a);
        s+=a;
    }
    sort(v.begin(),v.end());
    int b,c;
    c=v[5];
    s-=c;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            b=v[i]+v[j];
            if(b==s-b&&c==b){
                cout<<"S\n";
                return 0;
            }
        }
    }
    cout<<"N\n";
    return 0;
}