#include<bits/stdc++.h>
using namespace std;
const int maxn = 2050;
int a[maxn], remainds[maxn];
int link[maxn], sz[maxn];
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
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        set_dsu();
        cout << "YES\n";
        vector<pair<int, int>> ans;
        for(int x = n - 1; x >= 1; x--){
            for(int i = 0; i < x; i++)
                remainds[i] = 0;
            int n1;
            for(int i = 1; i <= n; i++)
                if(link[i] == i){
                    if(remainds[a[i] % x] == 1){
                        n1 = i;
                        break;
                    }else
                        remainds[a[i] % x]++;
                }
            for(int i = 1; i <= n; i++)
                if(a[n1] % x == a[i] % x && i != n1 && link[i] == i){
                    ans.push_back(make_pair(i, n1));
                    unite(n1, i);
                    break;
                }
        }
        reverse(ans.begin(), ans.end());
        for(auto p : ans)
            cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}