#include <bits/stdc++.h>

using namespace std;
#define vi vector<ll>
#define ll long long
#define pii pair<int,int>

int n;
ll prefix[(int)3e5+1];
ll postfix[(int)3e5+1];
vector<ll> A;

class BIT{
    public:
    int tsize;
    vector<ll> table;
    BIT(int size){
        table.assign(size,0);
        tsize = size;
    }
    void update(int i, int delta){
        while(i<tsize){
            table[i]+=delta;
            i += (i&(-i));
        }
    }
    ll sum(int i){
        ll sum = 0;
        while(i>0){
            sum+=table[i];
            i-=(i&(-i));
        }
        return sum;
    }
    ll rangeSum(int i, int j){
        return sum(j)-sum(i);
    }

};

void countInversions(){
    prefix[0] = 0;
    BIT* fenwick = new BIT(n+2);
    fenwick->update(A[0],1);
    for(int i=1;i<n;i++){
       prefix[i] = prefix[i-1]+ fenwick->rangeSum(A[i],n);
       fenwick->update(A[i],1);
    }
    postfix[n-1] = 0;
    fenwick = new BIT(n+2);
    fenwick->update(A[n-1],1);
    for(int i=n-2;i>=0;i--){
        postfix[i] = postfix[i+1] + fenwick->rangeSum(A[i],n);
        fenwick->update(A[i],1);
    }
}

int main() 
{
    memset(prefix,0,sizeof prefix);
    memset(postfix,0,sizeof postfix);
    cin>>n;
    vector<ll> B;
    A.resize(n); B.resize(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[i] = A[i];
    }
    sort(B.begin(),B.end());
    map<ll,ll> mapping;
    for(int i=0;i<n;i++){
        mapping[B[i]] = i+1;
    }
    B.clear();
    for(int i=0;i<n;i++){
        A[i] = mapping.find(A[i])->second;
    }
    // for(int i=0;i<n;i++) cout<<A[i]<<" ";
    // cout<<endl;
    countInversions();

    ll ans = 0;

    for(int i=1;i<n;i++){
        ll leftInversions,rightInversions;
        if(i==n-1) rightInversions = 0;
        else rightInversions = (postfix[i]-postfix[i+1]);
        leftInversions = prefix[i]-prefix[i-1];
        ans += min(leftInversions,rightInversions);
    }
    cout<<ans<<endl;

    return 0;
}