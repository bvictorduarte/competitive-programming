#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50;
int N[MAXN];
int main(){
    int n,cont5=0,cont0=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d", &N[i]);
        if(N[i]==5)cont5++;
        if(N[i]==0)cont0++;
    }
    int i;
    if(cont0==0&&cont5==0)
        cout<<-1<<endl;
    else if(cont0==0){
        if(N[n-1]<5){
            i=n-1;
            while(N[i]!=5)
                i--;
            swap(N[i],N[n-1]);
            cout<<N[0];
            for(i=1;i<n;i++)
                cout<<" "<<N[i];
            cout<<endl;
        }else{
            i=0;
            while(N[i]!=5)
                i++;
            swap(N[i],N[n-1]);
            cout<<N[0];
            for(i=1;i<n;i++)
                cout<<" "<<N[i];
            cout<<endl;
        }
    }else if(cont5==0){
            i=0;
            while(N[i]!=0)
                i++;
            swap(N[i],N[n-1]);
            cout<<N[0];
            for(i=1;i<n;i++)
                cout<<" "<<N[i];
            cout<<endl;
    }else{
        if(N[n-1]>5){
            i=0;
            while(N[i]!=5&&N[i]!=0)
                i++;
            swap(N[i],N[n-1]);
            cout<<N[0];
            for(i=1;i<n;i++)
                cout<<" "<<N[i];
            cout<<endl;
        }else{
            i=0;
            while(N[i]!=0)
                i++;
            swap(N[i],N[n-1]);
            cout<<N[0];
            for(i=1;i<n;i++)
                cout<<" "<<N[i];
            cout<<endl;
        }
    }
    return 0;
}