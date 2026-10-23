#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    stack<pair<int,int>> p;
    printf("0");
    p.push(make_pair(v[0],1));
    for(int i=1;i<n;i++){
        while(!p.empty()&&p.top().first>=v[i])
            p.pop();
        if(p.empty())
            printf(" 0");
        else
            printf(" %d", p.top().second);
        p.push(make_pair(v[i],i+1));
    }
    printf("\n");
    return 0;
}