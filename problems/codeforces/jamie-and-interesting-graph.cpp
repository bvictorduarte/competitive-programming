    #include<bits/stdc++.h>
    using namespace std;
    int n, m;
    const int maxn=1e6+50;
    int sieve[maxn];
    vector<int> primes;
    void sieve_of_eratostenes(){
        for(int i = 2; i < maxn; i++){
            if(sieve[i])
                continue;
            primes.push_back(i);
            for(int j = 2 * i; j < maxn; j += i)
                sieve[j] = 1;
        }
    }
    int main(){
        ios::sync_with_stdio(0);
        cout.tie(0);
        sieve_of_eratostenes();
        cin >> n >> m;
        int mstp = primes[lower_bound(primes.begin(), primes.end(), n) - primes.begin()];
        cout << 2 << ' ' << mstp << endl;
        cout << 1 << ' ' << n << ' ' << 2 << endl;
        if(n > 2)
            cout << n << ' ' << 2 << ' ' << 1 << endl;
        for(int i = 2; i <= n - 3; i++)
            cout << i << ' ' << i + 1 << ' ' << 1 << endl;
        if(n > 3)
            cout << n - 2 << ' ' << n - 1 << ' ' << mstp - n + 1 << endl;
        int maxw = mstp - n + 2;
        m -= (n - 1);
        for(int i = 2; i <= n - 3; i++){
            if(m == 0)
                break;
            for(int j = i + 2; j <= n - 1; j++){
                if(m == 0)
                    break;
                cout << i << ' ' << j << ' ' << maxw << endl;
                m--;
            }
        }
        for(int i = 3; i <= n - 1; i++){
            if(m == 0)
                break;
            cout << n << ' ' << i << ' ' << maxw << endl;
            m--;
        }
        for(int i = 2; i <= n - 1; i++){
            if(m == 0)
                break;
            cout << 1 << ' ' << i << ' ' << maxw << endl;
            m--;
        }
        return 0;
    }