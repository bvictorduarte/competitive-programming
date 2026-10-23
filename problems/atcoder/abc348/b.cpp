#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+50;
pair<int,int> points[maxn];
int dist(pair<int,int> a,pair<int,int> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>points[i].first>>points[i].second;
    for(int i=1;i<=n;i++){
        int ans_i=1;
        for(int j=1;j<=n;j++)
            if(i!=j&&!(i==1&&ans_i==1)&&dist(points[i],points[ans_i])<dist(points[i],points[j]))
                    ans_i=j;
            else if(i==1&&ans_i==1)
                ans_i=2;
        cout<<ans_i<<endl;
    }
    return 0;
}