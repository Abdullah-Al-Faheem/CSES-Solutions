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

set<int> st;

void fun(set<int>::iterator it, bool ok)
{
    if(st.empty()) return;
    if(st.size()==1)
    {
        cout<<*st.begin()<<nl;
        return;
    }
    if(it==st.end()) it= st.begin();

    if(it!= st.end()) dbug(*it)

    auto curr = it;
    it++;

    if(ok) 
    {
        cout<<*curr<<" ";
        st.erase(curr);
    }

    fun(it, ok^=1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) st.insert(i);

    fun(st.begin(), false);
    cout<<nl;
}