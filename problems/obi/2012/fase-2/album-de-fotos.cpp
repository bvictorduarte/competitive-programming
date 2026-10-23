#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    int l1,h1,l2,h2;
    cin>>x>>y;
    cin>>h1>>l1;
    cin>>h2>>l2;
    if((h1+h2<=x&&l1<=y&&l2<=y)||(h1+h2<=y&&l1<=x&&l2<=x)||(h1+l2<=x&&l1<=y&&h2<=y)||(h1+l2<=y&&l1<=x&&h2<=x)||(l1+h2<=x&&h1<=y&&l2<=y)||(l1+h2<=y&&h1<=x&&l2<=x)||(l1+l2<=x&&h1<=y&&h2<=y)||(l1+l2<=y&&h1<=x&&h2<=x))
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    return 0;
}