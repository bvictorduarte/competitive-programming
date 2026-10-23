#include<bits/stdc++.h>
using namespace std;
string students[110];
vector<int> positions;
int main(){
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        string l;
        cin>>l;
        if(l!="?")
            positions.push_back(i);
        students[i]=l;
    }
    int t=(int)positions.size();
    cin>>k;
    for(int i=1;i<=k;i++){
        int a;
        cin>>a;
        int j=0;
        while(j<t&&a>positions[j])
            j++;
        if(positions[j]==a)
            cout<<students[a]<<endl;
        else if(j==t){
            --j;
            for(int y=1;y<=a-positions[j];y++)
                cout<<"right of ";
            cout<<students[positions[j]]<<endl;
        }else if(j==0){
            for(int y=1;y<=positions[0]-a;y++)
                cout<<"left of ";
            cout<<students[positions[j]]<<endl;
        }
        else if(a-positions[j-1]==positions[j]-a)
            cout<<"middle of "<<students[positions[j-1]]<<" and "<<students[positions[j]]<<endl;
        else if(a-positions[j-1]<positions[j]-a){
            for(int y=1;y<=a-positions[j-1];y++)
                cout<<"right of ";
            cout<<students[positions[j-1]]<<endl;
        }else{
            for(int y=1;y<=positions[j]-a;y++)
                cout<<"left of ";
            cout<<students[positions[j]]<<endl;
        }
    }
    return 0;
}