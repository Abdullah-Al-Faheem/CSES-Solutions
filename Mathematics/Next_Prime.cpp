#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
// #define cerr if(false)cerr

const int N = 1e7+9;
bitset <N> mark;
vector<int> primes;
void sieve(void)
{
    int n = N - 9;
    mark[1] = true;

    for (int i = 2; i * i <= n; i++) 
    {
        if (!mark[i]) 
        {
            for (int j = i * i; j <= n; j += i) mark[j] = true;
        }
    }

    for (int i = 2; i <= n; i++) 
    {
        if (!mark[i]) primes.push_back(i);
    }
}
bool isPrime(int n)
{
    for (int i =0; primes[i]*primes[i] <= n; i++)
    {
        if(n%primes[i] == 0) return false;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    sieve();

    // dbug(primes.back());
    int tc, test = 0; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        // if(n<primes.back()) cout<< *upper_bound(all(primes), n)<<nl;
        // else
        // {
            for (int i = n+1; ; i++)
            {
                if(isPrime(i)){cout <<i<<nl; break;}
            }
        // }
    }
}