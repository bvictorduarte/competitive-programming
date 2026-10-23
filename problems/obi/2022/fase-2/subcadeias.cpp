#include<bits/stdc++.h>
using namespace std;
bool there_is_palindrome(string str, int k){
    for(int i=0;i<=(int)str.size()-k;i++){
        int r=i,l=i+k-1;
        while(r<=l){
            if(str[r]!=str[l])
                break;
            r++;
            l--;
        }
        if(r>l)
            return true;
    }
    return false;
}
int main(){
    string str;
    int ans=1,n;
    cin>>n>>str;
    for(int i=2;i<=n;i++)
        if(there_is_palindrome(str,i))
            ans=i;
    cout<<ans<<endl;
    return 0;
}