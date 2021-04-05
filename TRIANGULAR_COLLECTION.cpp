#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<ll>

vector<ll> A;
int main()
{
    ll n;
    cin>>n;
    A.resize(n);
    for(ll i=0;i<n;i++) cin>>A[i];
    sort(A.begin(),A.end());
    //[1,3,5,9,10]
    ll ans = 0;
    for(ll i=0;i<n-2;i++){
        for(ll j=i+1;j<n-1;j++){
            ll sumSmall = A[i]+A[j];
            ll k;
            for(k=j+1;k<n;k++){
                if(sumSmall<=A[k]) break;
            }
            k--;
            if(k>j && sumSmall>A[k]){
                ans+=pow(2,k-j)-1;
            }
        }
    }
    //cout<<endl;
    cout<<ans<<endl;

    return 0;
}