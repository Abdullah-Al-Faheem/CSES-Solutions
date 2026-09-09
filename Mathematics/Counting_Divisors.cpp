#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define pi acos(-1.0)
#define int long long
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define sqrt(x) sqrtl(x)
#define double long double
#define rall(x) x.rbegin(), x.rend()
#define all(x) (x).begin(), (x).end()
#define fix(n) fixed<<setprecision(n) 
#define mem(a,b) memset(a,b,sizeof(a))
#define dbug(x) cout << #x<<" -> "<<x << nl
#define input(arr) for(auto &it:arr) cin>>it
#define output(arr) for(auto &it: arr) cout<<it<<" "; cout<<nl
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e7;
vector<int> primes;
// call with sieve(N) at the begining of the main programme
void sieve(int n)
{
    n++;
    vector<int> arr(n, 1);
    for (int i = 2; i*i<n; i++)    
    {
        if(arr[i])
        {
            for (int j = i+i; j<n; j+= i) arr[j] = 0;
        }
    }
    for (int i = 2; i<n; i++) if(arr[i]) primes.push_back(i);
}

// call with primeFactor(n)
int primeFactor(int n)
{
    map<int,int> factor;
    for (int i =0; primes[i]*primes[i] <= n; i++)
    {
        while(n%primes[i] == 0)
        {
            n= n/primes[i];
            factor[primes[i]]++;
        }
    }
    if(n!=1) factor[n]++;
    int ans = 1;
    for (auto it: factor) 
    {
        // cout << it.first<<"^"<<it.second<<nl;
        ans*= (it.second+1);
    }
    return ans;
}

int32_t main()
{
    fast_io;
    sieve(N);
    int tc, test = 0; cin >> tc;
    while(tc--)
    {
        //cout<<"Case "<< ++test <<": ";
        int n; cin >> n;
        cout<< primeFactor(n)<<nl;
    }   
}