#include<bits/stdc++.h>
using namespace std;
const int maxs = 1e6 + 50;
vector<int> subset;
int freq[maxs];
void search(int k, int n) {
    if(k == n + 1){
        freq[accumulate(subset.begin(), subset.end(), 0)]++;
    }else{
        subset.push_back(k);
        search(k + 1, n);
        subset.pop_back();
        search(k + 1, n);
    }
}

class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            
        }
};

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int k;
    cin >> k;


}