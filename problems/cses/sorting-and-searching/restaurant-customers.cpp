#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arrival,leaving;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,l;
        cin>>a>>l;
        arrival.push_back(a);
        leaving.push_back(l);
    }
    sort(arrival.begin(),arrival.end());
    sort(leaving.begin(),leaving.end());
    int tatual=arrival[0],cont=0,i=0,j=0,max_customers=-1;
    while(tatual!=leaving[n-1]){
        if(i!=n&&arrival[i]==leaving[j]){
            tatual=arrival[i];
            i++;
            j++;
        }else if(i!=n&&arrival[i]<leaving[j]){
            tatual=arrival[i];
            i++;
            cont++;
        }else{
            tatual=leaving[j];
            j++;
            cont--;
        }
        if(max_customers<cont)
            max_customers=cont;
    }
    cout<<max_customers<<endl;
    return 0;
}
