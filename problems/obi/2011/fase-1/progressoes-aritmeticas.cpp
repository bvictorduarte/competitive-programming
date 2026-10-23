#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> p;
    int a,b,i=0,r1,r2,cont=1;
    bool v=false;
    cin>>b;
    do{
        cin>>a;
        if(p.empty())
            p.push(a);
        else if((int)p.size()==1||v){
            r2=r1=a-p.top();
            p.push(a);
            v=false;
        }else{
            r2=a-p.top();
            if(r2!=r1){
                cont++;
                v=true;
            }
            p.push(a);
        }
        i++;
    }while(i<b);
    cout<<cont<<endl;
    return 0;
}
