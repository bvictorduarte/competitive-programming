#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> t;
    int n,i;
    scanf("%d", &n);
    while(n--){
        scanf("%d",&i);
        t.insert(i);
    }
    printf("%d\n", (int)t.size());
    return 0;
}
