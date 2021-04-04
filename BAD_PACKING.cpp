#include <bits/stdc++.h>

using namespace std;
#define vi vector<ll>
#define ll long long
const ll INF = (ll)1e9+7;
vi A;
ll prefix[1005];
ll n,c;
ll dp[1005][(int)1e5+10];
int main() 
{
    cin>>n>>c;
    A.resize(n);
    for(ll i=0;i<n;i++) cin>>A[i];
    sort(A.begin(),A.end());
    prefix[0] = A[0];
    for(ll i=1;i<n;i++){
        prefix[i] = prefix[i-1]+A[i];
    }
    memset(dp,0,sizeof dp);
    for(ll i=0;i<=n;i++) dp[i][0] = 1;
    for(ll j=1;j<=n;j++){
        for(ll k=1;k<=c;k++){
            if(prefix[j-1]==k)
                dp[j][k] = j+1;
            else{
                if((k-A[j-1])>=0) 
                    dp[j][k] = max(dp[j-1][k],dp[j-1][k-A[j-1]]);
                else 
                    dp[j][k] = dp[j-1][k];
            }
        }
    }

    ll ans = INF;
    for(ll i=1;i<=c;i++){
        ll largest = dp[n][i];
        if(largest>n) ans = i;
        if(largest>0 && i+A[largest-1]>c){
            ans = min(ans,i);
        }
    }
    if(ans==INF) cout<<0<<endl;
    else cout<<ans<<endl;

}