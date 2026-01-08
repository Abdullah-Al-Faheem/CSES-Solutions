#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin>> str;

    vector<char> A, C;


    sort(all(str));

    map<char,int>mp;

    for (auto it: str) mp[it]++;

    for (auto &it: mp)
    {
        while(it.second>=2)  
        {
            A.push_back(it.first);

            it.second-=2;
        }

        if(it.second)
        {
            C.push_back(it.first);
            it.second-=1;
        }
    }

    if(C.size()>1) {cout<<"NO SOLUTION"<<nl; return 0;}
    
    for (auto it: A) cout<<it;
    for (auto it: C) cout<<it;
    reverse(all(A));
    for (auto it: A) cout<<it;
    cout<<nl;
}