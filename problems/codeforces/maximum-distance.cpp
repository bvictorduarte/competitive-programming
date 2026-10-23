#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int link[maxn], sz[maxn], sz1[maxn];
vector<tuple<int, int, int>> edges;
int find(int a){
    while(link[a] != a)
        a = link[a];
    return a;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    if(sz[a] > sz[b])
        swap(a, b);
    link[a] = b;
    sz[b] += sz[a];
    sz1[b] += sz1[a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int a;
        cin >> a;
        sz1[a] = 1;
    }
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(w, a, b));
        edges.push_back(make_tuple(w, b, a));
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++){
        link[i] = i;
        sz[i] = 1;
    }
    int ans;
    for(auto e : edges){
        int a, b, w;
        tie(w, a, b) = e;
        if(!same(a, b)){
            a = find(a);
            b = find(b);
            if(sz1[a] > 0 && sz1[b] > 0)
                ans = w;
            unite(a, b);
            if(sz[a] == n)
                break;
        }
    }
    for(int i = 1; i <= k; i++)
        cout << ans << ' ';
    cout << endl;
    return 0;
}