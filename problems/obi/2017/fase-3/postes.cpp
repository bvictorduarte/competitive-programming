#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s1=0,s2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<50)s1++;
        else if(a<85)s2++;
    }
    cout<<s1<<" "<<s2<<endl;
    return 0;
}