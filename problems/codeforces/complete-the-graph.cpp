#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 50;
const int maxm = 1e4 + 50;
const ll LINF = 1e18;
int n, m, s, t, pre[maxn], l[maxm], r[maxm];
ll L, dist1[maxn], dist2[maxn], edge[maxn][maxn];
vector<pair<int, ll>> adj1[maxn];
vector<int> adj2[maxn];
bool vis1[maxn], vis2[maxn], unmarked[maxn][maxn];
bool dijkstra1(){
    for(int i = 0; i < n; i++)
        dist1[i] = LINF;
    dist1[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(vis1[a]) continue;
        vis1[a] = true;
        for(auto u : adj1[a]){
            int b = u.first;
            ll w = u.second;
            if (dist1[a] + w < dist1[b]){
                dist1[b] = dist1[a] + w;
                pq.push({-dist1[b], b});
            }
        }
    }
    if(dist1[t] < L)
        return false;
    else
        return true;
}
bool dijkstra2(){
    for(int i = 0; i < n; i++)
        dist2[i] = LINF;
    dist2[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(vis2[a]) continue;
        vis2[a] = true;
        for(auto b : adj2[a]){
            ll w = edge[a][b];
            if(dist2[a] + abs(w) < dist2[b]){
                dist2[b] = dist2[a] + abs(w);
                pq.push({-dist2[b], b});
                pre[b] = a;
            }
        }
    }
    if(dist2[t] > L)
        return false;
    int cur = t;
    while(cur != s){
        int ant = pre[cur];
        if(edge[ant][cur] < 0){
            unmarked[ant][cur] = true;
            unmarked[cur][ant] = true;
        }
        cur = ant;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!unmarked[i][j] && edge[i][j] < 0)
                edge[i][j] = L + 1;
    return true;
}
bool test(){
    for(int i = 0; i < n; i++){
        vis2[i] = false;
        dist2[i] = LINF;
        pre[i] = 0;
    }
	dist2[s] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		int a = pq.top().second;
        pq.pop();
        if(vis2[a]) continue;
        vis2[a] = true;
		for(auto b : adj2[a]){
			ll w = edge[a][b];
			if(dist2[a] + abs(w) < dist2[b]){
                dist2[b] = dist2[a] + abs(w);
                pq.push({-dist2[b], b});
                pre[b] = a;
            }
		}
	}
	if(dist2[t] == L)
        return true;
	int cur = t;
    bool meet = false;
	while(cur != s){
		int ant = pre[cur];
		if(!meet && edge[ant][cur] < 0){
			ll d = abs(edge[ant][cur]);
			edge[ant][cur] = d + L - dist2[t];
			edge[cur][ant] = d + L - dist2[t];
			meet = true;
		}
		if(meet)
            break;
		cur = pre[cur];
	}
	return false;
}
void print(bool have_sol){
    if(!have_sol)
        cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i = 0; i < m; i++)
            cout << l[i] << ' ' << r[i] << ' ' << abs(edge[l[i]][r[i]]) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        if(w){
            adj1[a].push_back(make_pair(b, w));
            adj1[b].push_back(make_pair(a, w));
        }
        adj2[a].push_back(b);
        adj2[b].push_back(a);
        edge[a][b] = edge[b][a] = ((w == 0) ? -1 : w);
        l[i] = a;
        r[i] = b;
    }
    if(!dijkstra1()){
        print(false);
        return 0;
    }
    if(dist1[t] == L){
        cout << "YES\n";
        for(int i = 0; i < m; i++)
            cout << l[i] << ' ' << r[i] << ' ' << ((edge[l[i]][r[i]] < 0) ? LINF : edge[l[i]][r[i]]) << '\n';
        return 0;
    }
    if(!dijkstra2()){
        print(false);
        return 0;
    }
    while(!test())
        test();
    print(true);
}