#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int tab[maxn], n, m;
bool vis[maxn];
int cont = 0;
int dfs(int x, int p = 0){
    int ans = 0;
    if(m & 1){

    }else{
        if(x + m + 1 <= (n * m + 1) / 2 && (x % (m / 2) != 0) && x + m + 1 != p){
            if((x / (m / 2)) & 1){
                if(tab[x + (m / 2) + 1] == 2 && tab[x + m + 1] == 0){
                    cout<<1<<" "<<x<<endl;
                    tab[x + (m / 2) + 1] = 0;
                    ans = max(ans, 1 + dfs(x + m + 1, x));
                    tab[x + (m / 2) + 1] = 2;
                }
            }
            else{
                if(tab[x + (m / 2)] == 2 && tab[x + m + 1] == 0){
                    cout<<1<<" "<<x<<endl;
                    tab[x + (m / 2)] = 0;
                    ans = max(ans, 1 + dfs(x + m + 1, x));
                    tab[x + (m / 2)] = 2;
                }
            }
        }
        if(x + m - 1 <= (n * m + 1) / 2 && (x % (m / 2) != 1) && x + m - 1 != p){
            if((x / (m / 2)) & 1 || (x % (m / 2) == 0 && !(x / (m / 2) & 1))){
                if(tab[x + (m / 2)] == 2 && tab[x + m - 1] == 0){
                    cout<<2<<" "<<x<<endl;
                    tab[x + (m / 2)] = 0;
                    ans = max(ans, 1 + dfs(x + m - 1, x));
                    tab[x + (m / 2)] = 2;
                }
            }
            else{
                if(tab[x + (m / 2) - 1] == 2 && tab[x + m - 1] == 0){
                    cout<<2<<" "<<x<<endl;
                    tab[x + (m / 2) - 1] = 0;
                    ans = max(ans, 1 + dfs(x + m - 1, x));
                    tab[x + (m / 2) - 1] = 2;
                }
            }
        }
        if(x - m - 1 >= 1 && (x % (m / 2) != 1) && x - m - 1 != p){
            if((x / (m / 2)) & 1 || (x % (m / 2) == 0 && !(x / (m / 2) & 1))){
                if(tab[x - (m / 2)] == 2 && tab[x - m - 1] == 0){
                    cout<<3<<" "<<x<<endl;
                    tab[x - (m / 2)] = 0;
                    ans = max(ans, 1 + dfs(x - m - 1, x));
                    tab[x - (m / 2)] = 2;
                }
            }
            else{
                if(tab[x - (m / 2) - 1] == 2 && tab[x - m - 1] == 0){
                    cout<<3<<" "<<x<<endl;
                    tab[x - (m / 2) - 1] = 0;
                    ans = max(ans, 1 + dfs(x - m - 1, x));
                    tab[x - (m / 2) - 1] = 2;
                }
            }
        }
        if(x - m + 1 >= 1 && (x % (m / 2) != 0) && x - m + 1 != p){
            if((x / (m / 2)) & 1){
                if(tab[x - (m / 2) + 1] == 2 && tab[x - m + 1] == 0){
                    cout<<4<<" "<<x<<endl;
                    tab[x - (m / 2) + 1] = 0;
                    ans = max(ans, 1 + dfs(x - m + 1, x));
                    tab[x - (m / 2) + 1] = 2;
                }
            }
            else{
                if(tab[x - (m / 2)] == 2 && tab[x - m + 1] == 0){
                    cout<<4<<" "<<x<<endl;
                    tab[x - (m / 2)] = 0;
                    ans = max(ans, 1 + dfs(x - m + 1, x));
                    tab[x - (m / 2)] = 2;
                }
            }
        }
    }
    return ans;
}
int main(){
    while(cin >> n >> m && !(!n && !m)){
        int ans = 0;
        for(int i = 1; i <= (n * m + 1) / 2; i++)
            cin >> tab[i];
        for(int i = 1; i <= (n * m + 1) / 2; i++)
            if(tab[i] == 1){
                tab[i] = 0;
                ans = max(ans, dfs(i));
                tab[i] = 1;
            }
        cout<<ans<<endl;
    }
    return 0;
}