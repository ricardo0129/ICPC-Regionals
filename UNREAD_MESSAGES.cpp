#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long 

short A[(int)1e9+10];

int main()
{
    int n, m;
    cin>>n>>m;
    memset(A,0,sizeof(A));
    int x;
    ll total = 0;
    ll sub = 0;
    for(int i=0;i<m;i++){
        cin>>x;
        total+=n;
        total-=(i-A[x]+1);
        A[x] = i+1;
        //for(int j=1;j<=n;j++) cout<<A[j]<<" ";
        cout<<total<<endl;
    }
    return 0;
}