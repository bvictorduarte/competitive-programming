#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int maxn=2e5+30;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int qtd[maxn];
ordered_set s;
int main(){
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        qtd[i] = (a / p);
    }
    for(int i = 1; i <= n; i++){
        s.insert(make_pair(qtd[i], i));
        cout << -s.order_of_key(make_pair(qtd[i], i)) + i - 1 << ' ';
    }
    cout << endl;
    return 0;
}