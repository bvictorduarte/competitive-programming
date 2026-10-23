#include<bits/stdc++.h>
using namespace std;
int v[12];
int main(){
    for(int i=0;i<8;i++){
        int a;
        cin>>a;
        v[a]++;
    }
    for(int i=0;i<=9;i++){
        if(v[i]>=5){
            cout<<"N"<<endl;
            return 0;
        }
    }
    cout<<"S"<<endl;
    return 0;
}