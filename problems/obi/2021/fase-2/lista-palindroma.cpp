#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<long long> dq;
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        dq.push_back(a);
    }
    long long cont=0;
    for(int i=0;i<n;i++){
        if(dq.empty())break;
        if(dq.front()==dq.back()){
            if((int)dq.size()!=1){
                dq.pop_back();
                dq.pop_front();
            }else
                dq.pop_back();
            continue;
        }
        if(dq.front()>dq.back()){
            long long b;
            b=dq.back();
            dq.pop_back();
            b+=dq.back();
            dq.pop_back();
            dq.push_back(b);
            cont++;
            continue;
        }
        if(dq.front()<dq.back()){
            long long b;
            b=dq.front();
            dq.pop_front();
            b+=dq.front();
            dq.pop_front();
            dq.push_front(b);
            cont++;
            continue;
        }
    }
    cout<<cont<<endl;
}