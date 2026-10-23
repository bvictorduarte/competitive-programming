#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>t;
    for(int o=0;o<t;o++){
        scanf("%d", &n);
        vector<int> a,b;
        vector<pair<int,int>> c;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<n;i++){
            int d;
            scanf("%d", &d);
            a.push_back(d);
        }
        for(int i=1;i<=n;i++){
            int d;
            scanf("%d", &d);
            b.push_back(d);
            c.push_back(make_pair(a[i]-d,i));
        }
        sort(c.rbegin(),c.rend());
        int m=c[0].first;
        int i=0;
        while(i<n&&c[i].first==m)
            i++;
        cout<<i<<endl;
        i--;
        cout<<c[i].second;
        i--;
        while(i>=0){
            cout<<" "<<c[i].second;
            i--;
        }
        cout<<endl;
    }
    return 0;
}