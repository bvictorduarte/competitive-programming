#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c;
    int g=gcd(a,b,x,y);
    if(c%g==0){
        x*=(c/g);
        y*=(c/g);
        int lcm=(a*b)/g;
        int dx=lcm/a,dy=lcm/b;
        if(x<=0&&y<=0)
            cout<<"No\n";
        else if(x<0){
            int aux_x=-x;
            int n=aux_x/dx;
            if(aux_x%dx!=0)
                n++;
            if(y-n*dy>=0)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }else if(y<0){
            int aux_y=-y;
            int n=aux_y/dy;
            if(aux_y%dy!=0)
                n++;
            if(x-n*dx>=0)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }else
            cout<<"Yes\n";
    }else
        cout<<"No\n";
}