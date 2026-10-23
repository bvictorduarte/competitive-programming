    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1e6+50;
    int freq[maxn];
    int main(){
        int n,cont=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d", &a);
            if(freq[a]){
                freq[a]--;
                freq[a-1]++;
            }else{
                freq[a-1]++;
                cont++;
            }
        }
        printf("%d\n", cont);
        return 0;
    }