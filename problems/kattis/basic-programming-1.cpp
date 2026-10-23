#include <bits/stdc++.h>
using namespace std;
bool visited[200050];
int main(){
    vector<int> a;
    int n,op,sum=0,even_sum=0;
    cin>>n>>op;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.push_back(k);
        if(k%2==0)
            even_sum+=k;
        sum+=k;
    }
    if(op==1)
        cout<<7<<endl;
    else if(op==2)
        if(a[0]>a[1])
            cout<<"Bigger\n";
        else if(a[0]==a[1])
            cout<<"Equal\n";
        else    
            cout<<"Smaller\n";
    else if(op==3){
        int sup,inf;
        sup=max(a[0],a[1]);inf=min(a[0],a[1]);
        sup=max(sup,a[2]);inf=min(inf,a[2]);
        cout<<a[0]+a[1]+a[2]-sup-inf<<endl;
    }
    else if(op==4)
        cout<<sum<<endl;
    else if(op==5)
        cout<<even_sum<<endl;
    else if(op==6){
        string p;
        for(int j=0;j<n;j++)
            p.push_back('a'+a[j]%26);
        cout<<p<<endl;
    }else{
        visited[0]=true;
        int j=0;
        while(true){
            j=a[j];
            if(j>n-1){
                cout<<"Out\n";
                break;
            }else if(j==n-1){
                cout<<"Done\n";
                break;
            }else if(visited[j]){
                cout<<"Cyclic\n";
                break;
            }
            visited[j]=true;
        }
   }
    return 0;
}