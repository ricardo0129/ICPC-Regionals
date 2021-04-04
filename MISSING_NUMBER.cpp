#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long 


int main()
{
    int n;
    cin>>n;
    string A;
    cin>>A;
    int ans = -1;
    int current = 1;
    int ccc = 1;
    for(int i=0;i<A.size();i++){
       // cout<<i<<" "<<ccc<<" "<<(A.substr(i,ccc))<<" "<<ccc<<endl;
        if(current==10) ccc++;
        if(current==100) ccc++;
        if(stoi(A.substr(i,ccc))==current){
        }
        else{
            ans = current;
            break;
        }
        current++;
        i+=(ccc-1);
    }
    if(ans==-1) cout<<current<<endl;
    else cout<<ans<<endl;
    return 0;
}