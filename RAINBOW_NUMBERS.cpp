#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>

const ll MOD = 998244353;
string L,U;
int n;
ll dp[(int)1e5][10][2][2];

ll solve(int i, int previous,bool allZeros,bool allNines){
    if(i>=n){
        return 1;
    }
    if(previous!=-1 && dp[i][previous][allZeros][allNines]!=-1){
        return dp[i][previous][allZeros][allNines];
    }

    int start = L[i]-'0', end = U[i]-'0';
    if(allZeros) start = 0; if(allNines) end = 9;
    int ans = 0;
    for(int j=start;j<=end;j++){
        if(start==end){
            if(previous!=j)
                ans = (ans+solve(i+1,j,allZeros,allNines))%MOD;
        }
        else if(j==start){
            if(previous!=j)
                ans=(ans+solve(i+1,j,allZeros,true))%MOD;
        }
        else if(j==end){
            if(previous!=j)
                ans=(ans+solve(i+1,j,true,allNines))%MOD;
        }
        else{
            if(previous!=j)
                ans=(ans+solve(i+1,j,true,true))%MOD;
            }
        }
        return dp[i][previous][allZeros][allNines] = ans%MOD;
}

int main()
{
    cin>>L>>U;
    if(L.size()!=U.size()){
        L = string(U.size()-L.size(),'0')+L;
    }
    n = L.size();
    memset(dp,-1,sizeof dp);
    int ans = solve(0,-1,false,false);
    cout<<ans<<endl;

    return 0;
}