#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long 

int n,k;
vector<string> Students;
int ans = 0;
void solve(int i,int bitsum){
    if(i==k){
        int minimum = 50;
        for(int j=0;j<n;j++){
            int current = 0;
            for(int s=0;s<k;s++){
                if(Students[j][s]=='T' && bitsum&(1<<s)) current++;
                if(Students[j][s]=='F' && !(bitsum&(1<<s))) current++;
            }
            minimum = min(minimum,current);
        }
        //cout<<minimum<<endl;
        ans = max(ans,minimum);
        return;
    }
    solve(i+1,bitsum);
    solve(i+1,bitsum|(1<<(i)));
}
int main()
{
    cin>>n>>k;
    Students.resize(n);
    for(int i=0;i<n;i++){
        cin>>Students[i];
    }
    solve(0,0);
    cout<<ans<<endl;

    return 0;
}