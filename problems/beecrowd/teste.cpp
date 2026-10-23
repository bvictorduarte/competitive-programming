#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1050;
const ll LINF = 0x3f3f3f3f3f3f;
const ll maxk = (1<<11);



int n; // numero de vertices
vector < pair <int , double > > g [ MAX ]; // { vizinho , peso }
double d [maxk][ MAX ]; // dp[ mask ][v] = arvore minima com o
//subconjunto mask de S e o vertice v
double steiner ( const vector <int > & S ) {
int k = S . size () ; // k - -;
for ( int mask = 0; mask < (1 << k ) ; mask ++) for (int v = 0; v <
n ; v ++) d [ mask ][ v ] = LINF ;
for ( int v = 0; v < n ; v ++) d [0][ v ] = 0;
for ( int i = 0; i < k ; ++ i ) d [1 << i ][ S [ i ]] = 0;
for ( int mask = 1; mask < (1 << k ) ; mask ++) {
for ( int a = ( mask - 1) & mask ; a ; a = ( a - 1) & mask ) {
int b = mask ^ a ;
if ( b > a ) break ;
for (int v = 0; v < n ; v ++)
d [ mask ][ v ] = min ( d [ mask ][ v ] , d [ a ][ v ] + d [ b ][ v ]) ;
}
priority_queue < pair < double , int > > pq ;
for ( int v = 0; v < n ; v ++) {
if ( d [ mask ][ v ] == LINF ) continue ;
pq . emplace ( - d [ mask ][ v ] , v ) ;
}
while ( pq . size () ) {
    double ndist = pq.top().first;
    int u = pq.top().second;
    pq . pop () ;
if ( - ndist > d [ mask ][ u ]) continue ;
for ( auto aux : g [ u ]){
int idx = aux.first;
double w = aux.second;
if (d [ mask ][ idx ] >
d [ mask ][ u ] + w) {
d [ mask ][ idx ] = d [ mask ][ u ] + w;
pq . emplace ( - d[ mask ][ idx ] , idx ) ;
}
}
}
}
return d [(1 << k ) - 1][ S [0]]; // S[k]
}

double compute_dist(pair<int, int> p1, pair<int, int> p2){
    int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    return sqrt((x1-x2) * (x1-x2) + (y1 - y2) * (y1 - y2));
}
pair<int, int> points[MAX];
int main(){
    int k;
    cin >> n >> k;
    vector<int> S;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        points[i] = make_pair(a, b);
        if(i < k)
            S.push_back(i);
    }
    for(int i = 0; i < k; i++)
        for(int j = k; j < n; j++)
            g[i].push_back(make_pair(j,compute_dist(points[i], points[j])));
    for(int i = k; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i].push_back(make_pair(j,compute_dist(points[i], points[j])));
    cout << steiner(S) << endl;
    return 0;
}
