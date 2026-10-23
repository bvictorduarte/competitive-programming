#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxk = 25;
#define sz(x) (int) (x).size()
map<char, int> mp;
int a[maxn], dp[maxn][maxk][6];
bool wins(int a, int b){
    if((a == 1 && b == 3) || (a == 3 && b == 2) || (a == 2 && b == 1))
        return true;
    return false;
}
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
int main(){
    //setIO("hps");
    int n, k;
    mp['P'] = 1;
    mp['S'] = 2;
    mp['H'] = 3;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        a[i] = mp[s[0]];
    }
    for(int i = 1; i <= 3; i++)
        if(wins(i, a[1]))
            dp[1][0][i] = 1;
    for(int j = 1; j <= 3; j++)
        for(int i = 2; i <= n; i++){
            dp[i][0][j] = dp[i - 1][0][j];
            if(wins(j, a[i]))
                dp[i][0][j]++;
        }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= min(k, i - 1); j++){
            for(int op = 1; op <= 3; op++){
                for(int aux = 1; aux <= 3; aux++)
                    if(aux != op)
                        dp[i][j][op] = max(dp[i - 1][j - 1][aux], dp[i - 1][j][op]);
                if(wins(op, a[i]))
                    dp[i][j][op]++;
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= 3; i++)
        ans = max(ans, dp[n][k][i]);
    cout << ans << endl;
    return 0;
}