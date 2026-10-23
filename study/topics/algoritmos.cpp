
/*
                 BINARY SEARCH
/-----------------------------------------------------/
int recursive_binary_search(int inf, int sup, int x){
    int m=(inf+sup)/2;
    if(v[m]==x)
        return m;
    else if(inf>sup)
        return -1;
    else{
        if(x<v[m])
            return binary_search(inf,m-1,x);
        else if(x>v[m])
            return binary_search(m+1,sup,x);
    }
}
/-----------------------------------------------------/
int binary_search(int inf, int sup, int x){
    int tam=(sup-inf)+1,j=0;
    for(int i=tam;i>=1;i=i/2){
        while(j+i<tam&&v[j+i]<=x)
            j+=i;
    }
    if(v[j]==x)
        return j;
    else
        return -1;
}
/-----------------------------------------------------/
int binary_search(int inf, int sup, int x){
    while(inf<=sup){
        int m=(inf+sup)/2;
        if(v[m]==x)
            return m;
        else if(v[m]<x)
            inf=m+1;
        else
            sup=m-1;
    }
    return -1;
}
*/


/*
                 BEST SUBARRAY SUM
/-----------------------------------------------------/
int best_array_sum(){
    int sum=v[0],n=(int)v.size(),best=v[0];
    for(int i=0;i<n;i++){
        sum=max(sum+a[i],a[k]);
        best=max(best,sum);
    }
    return best;
}

*/