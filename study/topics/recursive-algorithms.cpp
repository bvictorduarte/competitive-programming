/*
Generating subsets
ideia: incluir um elemento no conjunto, fazer uma busca, excluir o mesmo elemento e fazer uma busca.
vector<int> subset;
void search(int k){
    int n=(int)subset.size();
    if(k==n+1){
        //process subset
    }
    else{
        //include k in the subset
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
}
Generating Permutations
ideia: incluir um elemento no conjunto, caso não tenha sido incluido, e fazer uma busca, excluir o mesmo do conjunto.
vector<int> permutation;
bool ready[n+1];
void search(){
    if((int)permutation.size()==n){
        //process permutation
    }else{
        for(int i=1;i<=n;i++){
            if(ready[i])continue;
            ready[i]=true;
            permutation.push_back(i);
            search();
            ready[i]=false;
            permutation.pop_back();
        }
    }
}
*/