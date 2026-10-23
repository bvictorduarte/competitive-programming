#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define X first
#define Y second
vector<P> tree;
stack<P> convex_hull;
ll cross_product(P a, P b){
    return a.X*b.Y-a.Y*b.X;
}
P dif_points(P a, P b){
    return make_pair(a.X-b.X,a.Y-b.Y);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        tree.push_back(make_pair(a,b));
    }
    sort(tree.begin(),tree.end());
    for(int i=0;i<n;i++){
        if((int)convex_hull.size()<=1)
            convex_hull.push(tree[i]);
        else{
            P b=convex_hull.top();convex_hull.pop();
            P a=convex_hull.top();convex_hull.pop();
            while(!convex_hull.empty()&&cross_product(dif_points(tree[i],a),dif_points(tree[i],b))>=0){
                swap(a,b);
                a=convex_hull.top();convex_hull.pop();
            }
            if((convex_hull.empty()&&cross_product(dif_points(tree[i],a),dif_points(tree[i],b))<0)||(!convex_hull.empty())){
                convex_hull.push(a);
                convex_hull.push(b);
                convex_hull.push(tree[i]);
            }else if(convex_hull.empty()){
                convex_hull.push(a);
                convex_hull.push(tree[i]);
            }
        }
    }
    cout<<(int)convex_hull.size()-1<<endl;
    return 0;
}