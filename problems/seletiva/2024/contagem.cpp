#include<bits/stdc++.h>
using namespace std;
int dp[20][20];
int pot(int e){
    int ans = 1;
    for(int i = 1; i <= e; i++)
        ans *= 10;
    return ans;
}
int main(){
    for(int i = 0; i <= 9; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= 10; i++)
        for(int j = 0; j <= 9; j++){
            dp[j][i] += dp[j][i - 1] * 10 + 10;
        }
}