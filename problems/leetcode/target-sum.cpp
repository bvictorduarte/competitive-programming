#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int maxs = 1050;
map<int, int> dp[maxn];
int main(){
    vector<int> nums;
    int target;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cin >> target;
    dp[0][nums[0]] += 1;
    if(nums[0] == 0)
        dp[0][-nums[0]] += 1;
    else
        dp[0][-nums[0]] = 1;
    for(int i = 1; i < n; i++)
        for(int j = -maxs; j <= maxs; j++)
            dp[i][j] += (dp[i - 1][j + nums[i]] + dp[i - 1][j - nums[i]]);
    cout << dp[n - 1][target] << endl;
    return 0;
}
