#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,s;
    cin>>m>>s;
    if(s>9*m||(s==0&&m!=1)){
        cout<<"-1 -1\n";
        return 0;
    }
    if(s==0){
        cout<<"0 0\n";
        return 0;
    }
    if(m==1){
        cout<<s<<" "<<s;
        return 0;
    }
    vector<int> great,small;
    for(int i=0;i<s/9;i++)
        great.push_back(9);
    great.push_back(s%9);
    for(int i=s/9+1;i<m;i++)
        great.push_back(0);
    if(!((s/9+1==m&&s%9!=0)||(s/9==m&&s%9==0))){
        small.push_back(1);
        s--;
        if(s%9==0){
            for(int i=0;i<m-1-s/9;i++)
                small.push_back(0);
            for(int i=0;i<s/9;i++)
                small.push_back(9);
        }
        else{
            for(int i=0;i<m-s/9-2;i++)
                small.push_back(0);
            small.push_back(s%9);
            for(int i=0;i<s/9;i++)
                small.push_back(9);
        }
    }else{
        int j=m-1;
        for(int i=0;i<m;i++){
            small.push_back(great[j]);
            j--;
        }
    }
    for(int i=0;i<m;i++)
        cout<<small[i];
    cout<<" ";
    for(int i=0;i<m;i++)
        cout<<great[i];
    cout<<endl;
    return 0;
}