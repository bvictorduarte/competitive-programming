#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int link[maxn], sz[maxn], v[maxn];
set<int> freq[maxn];
int n;
void set_dsu(){
    for(int i = 1; i <= n; i++){
        link[i] = i;
        sz[i] = 1;
    }
}
int find(int x){
    while(x != link[x])
        x = link[x];
    return x;
}
bool same(int a, int b){
    return find(a) == find(b);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b])
        swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        set_dsu();
        for(int i = 1; i <= n; i++)
            freq[i].clear();
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            freq[i].insert(v[i]);
            freq[v[i]].insert(i);
            if(!same(i, v[i]))
                unite(i, v[i]);
        }
        set<int> comps_max, comps_min;
        for(int i = 1; i <= n; i++){
            comps_max.insert(find(i));
            if((int)freq[i].size() == 1)
                comps_min.insert(find(i));
        }
        int ans_max = (int)comps_max.size(), ans_min = (int)comps_min.size() > 0 ? ans_max - (int)comps_min.size() + 1 : ans_max;
        cout << ans_min << ' ' << ans_max << endl;
    }
}