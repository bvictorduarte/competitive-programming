#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,p;
    cin>>n>>i>>p;
    if((i+p)%n==0)
        cout<<n<<endl;
    else
        cout<<(i+p)%n<<endl;

    return 0;
}