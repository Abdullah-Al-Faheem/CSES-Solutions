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
    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int sq = i*i;

        int ways = sq*(sq-1);
        
        int bad =0;

        if(i<3){}
        else if(i==3) bad=  16;
        else if(i==4) bad = 48;
        else
        {
            int mid = i/2;

            // upper part
            int a = 2+3+ (mid-2)*4;
            a*=2;
            if(i&1) a+= 4;

            int b = 3+4+ (mid-2)*6;
            b*=2;
            if(i&1) b+= 6;

            //mid part
            int c = 4+6+ (mid-2)*8;
            c*=2;
            if(i&1) c+= 8;
            
            bad = (a*2)+(b*2)+ (mid-2)*c*2;

            if(i&1)bad+=c;
        }

        ways-=bad;

        cout<< ways/2<<nl;
    }
}