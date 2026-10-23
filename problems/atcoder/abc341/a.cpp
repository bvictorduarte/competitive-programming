#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=2*n+1;i++)
        if(i%2!=0)
            cout<<"1";
        else
            cout<<"0";
    cout<<endl;
    return 0;
}