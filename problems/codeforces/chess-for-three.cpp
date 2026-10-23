#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if(p1 == p2 && p2 == p3 && p1 == 0)
            cout << 0 << endl;
        else{
            int ans = 0;
            bool v = false;
            for(int e12 = 0; e12 <= p1 && e12 <= p2; e12++){
                for(int e23 = 0; e23 <= p2 && e23 <= p3; e23++){
                    for(int e13 = 0; e13 <= p3 && e13 <= p1; e13++){
                        int p1f = p1 - e12 - e13, p2f = p2 - e12 - e23, p3f = p3 - e23 - e13;
                        if(p1f >= 0 && p2f >= 0 && p3f >= 0 && p1f % 2 == 0 && p2f % 2 == 0 && p3f % 2 == 0){
                            ans = max(ans, e12 + e23 + e13);
                            v = true;
                        }
                    }
                }
            }
            if(v)
                cout << ans << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}