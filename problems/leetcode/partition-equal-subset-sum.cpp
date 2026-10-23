#include<bits/stdc++.h>
using namespace std;
const int maxn = 250;
const int maxs = 2e4 + 50;
bool dp[maxn][maxs];
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = accumulate(nums.begin(), nums.end(), 0);
            for(int i = 0; i < n; i++)
                for(int j = 1; j <= maxs; j++)
                    dp[i][j] = false;
            dp[0][nums[0]] = true;
            for(int i = 1; i < n; i++)
                for(int j = 1; j <= maxs / 2 + 1; j++)
                    if(j - nums[i] >= 1)
                        dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - nums[i]]);
                    else
                        dp[i][j] = dp[i - 1][j];
            if(sum % 2 == 0 && dp[n - 1][sum / 2])
                return true;
            else
                return false;
        }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    n = nums.size();
    Solution solution;
    bool ans = solution.canPartition(nums);
    cout << ans << endl;
    return 0;
}