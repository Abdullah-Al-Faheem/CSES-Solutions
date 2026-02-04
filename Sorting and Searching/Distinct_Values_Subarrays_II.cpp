#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,k ; cin>>n >>k;

    int arr[n+3];
    for (int i = 1; i <= n; i++) cin>> arr[i];

    set<int> st;
    map<int,int>mp;

    int l = 0, r= 0, ans =0;

    while(r<n)
    {
        r++;

        if(!st.count(arr[r]) and st.size()==k)
        {
            while(st.size()==k)
            {
                l++;
                mp[arr[l]]--;
                
                ans+= r-l;

                if(mp[arr[l]]==0) st.erase(arr[l]);
            }
        }

        mp[arr[r]]++;
        st.insert(arr[r]);
    }

    int x = r-l;
    ans+= x*(x+1)/2;

    cout<<ans<<nl;
}