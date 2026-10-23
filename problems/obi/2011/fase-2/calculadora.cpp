#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,pr[4]={2,3,5,7};
    long long ans=1;
    multiset<int> num,den;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        char op;
        scanf("%d %c", &k, &op);
        if(op=='*'){
            for(int j=0;j<4;j++){
                while(k%pr[j]==0){
                    if(!den.empty()&&den.find(pr[j])!=den.end())
                        den.erase(den.find(pr[j]));
                    else
                        num.insert(pr[j]);
                    k/=pr[j];
                }
            }
        }else{
            for(int j=0;j<4;j++){
                while(k%pr[j]==0){
                    if(!num.empty()&&num.find(pr[j])!=num.end())
                        num.erase(num.find(pr[j]));
                    else
                        den.insert(pr[j]);
                    k/=pr[j];
                }
            }
        }
    }
    for(auto x:num)
        ans*=(long long)x;
    cout<<ans<<endl;
    return 0;
}