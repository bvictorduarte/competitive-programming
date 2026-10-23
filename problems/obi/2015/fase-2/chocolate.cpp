#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int x1,y1,x2,y2;
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    n=n/2;
    if((x1>n&&y1>n&&x2>n&&y2>n)||(x1<=n&&y1>n&&x2<=n&&y2>n)||(x1<=n&&y1<=n&&x2<=n&&y2<=n)||(x1>n&&y1<=n&&x2>n&&y2<=n))
        cout<<"N"<<endl;
    else
        cout<<"S"<<endl;
    return 0;
}