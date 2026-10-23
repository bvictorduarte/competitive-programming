#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ans=1,c,l,r,sum;
    c=1;
    for(c=0;c<n;c++){
        l=c-1;
        r=c+1;
        sum=1;
        while(l>=0&&r<n){
            if(s[l]==s[r]){
                sum+=2;
                l--;
                r++;
            }
            else
                break;
        }
        ans=max(ans,sum);
    }
    for(int i=0;i<n-1;i++){
        l=i;
        r=i+1;
        sum=0;
        while(l>=0&&r<n){
            if(s[l]==s[r]){
                sum+=2;
                l--;
                r++;
            }
            else
                break;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}