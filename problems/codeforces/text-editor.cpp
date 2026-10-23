#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int INF = 0x3f3f3f3f;
int l[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(c2 >= c1){
        int c_min = c1;
        if(r1 > r2){
            for(int i = r2; i <= r1; i++)
                c_min = min(c_min, l[i] + 1);
        }else{
            for(int i = r1; i <= r2; i++)
                c_min = min(c_min, l[i] + 1);
        }
        cout << abs(r1 - r2) + abs(c_min - c2);
    }else{
        int dist = INF;
        if(r2 < r1){
            int min_up = c1;
            for(int i = r1 - 1; i >= r2; i--)
                min_up = min(min_up, l[i] + 1);
            dist = abs(min_up - c2) + (r1 - r2);
            int min_up2 = min_up;
            for(int i = r2 - 1; i >= 1; i--){
                min_up2 = min(min_up2, l[i] + 1);
                dist = min(dist, (r1 - r2) + 2 * (r2 - i) + abs(min_up2 - c2));
            }
            int min_down = min_up;
            for(int i = r1 + 1; i <= n; i++){
                min_down = min(min_down, l[i] + 1);
                dist = min(dist, 2 * (i - r1) + (r1 - r2) +  abs(min_down - c2));
            }
        }else if(r2 > r1){
            int min_down = c1;
            for(int i = r1 + 1; i <= r2; i++)
                min_down = min(min_down, l[i] + 1);
            dist = abs(min_down - c2) + (r2 - r1);
            int min_down2 = min_down;
            for(int i = r2 + 1; i <= n; i++){
                min_down2 = min(min_down2, l[i] + 1);
                dist = min(dist, (r2 - r1) + 2 * (i - r2) + abs(min_down2 - c2));
            }
            int min_up = min_down;
            for(int i = r1 - 1; i >= 1; i--){
                min_up = min(min_up, l[i] + 1);
                dist = min(dist, 2 * (r1 - i) + (r2 - r1) + abs(min_up - c2));
            }
        }else{
            int min_down = c1, min_up = c1;
            for(int i = r1 + 1; i <= n; i++){
                min_down = min(min_down, l[i] + 1);
                dist = min(dist, 2 * (i - r1) + abs(min_down - c2));
            }
            for(int i = r1 - 1; i >= 1; i--){
                min_up = min(min_up, l[i] + 1);
                dist = min(dist, 2 * (r1 - i) + abs(min_up - c2));
            }
        }
        cout << dist << endl;
    }
}