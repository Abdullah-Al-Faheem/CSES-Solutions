#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m, a,b, x, y; 
    cin>>n>>m;
    vector<int> arr(n+3); 
    for (int i = 1; i <= n; i++)cin>> arr[i];

    set<int> st;
    int pos[n+3];
    pos[0]=0, pos[n+1]=n+1;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        st.insert(arr[i]);
        pos[arr[i]]=i;

        if(!st.count(arr[i]-1)) ans++;
    }


    while(m--)
    {
        cin>>a>>b;
        if(a==b) {cout<<ans<<nl; continue;}
        if(a>b)swap(a,b);

        x= arr[a], y= arr[b];

        if(pos[x-1]>a and pos[x-1]<b) ans--;
        if(pos[x+1]>a and pos[x+1]<b) ans++;

        if(pos[y-1]<b and pos[y-1]>a) ans++;
        if(pos[y+1]<b and pos[y+1]>a) ans--;

        if(x-1==y) ans--;
        if(x+1==y) ans++;

        pos[x]= b;
        pos[y]=a;

        swap(arr[a],arr[b]);

        cout<<ans<<nl;
    }
}