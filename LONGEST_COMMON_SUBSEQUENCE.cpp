#include <bits/stdc++.h>

using namespace std;
#define vi vector<ll>
#define ll long long
#define pii pair<int,int>
const ll INF = (ll)1e9+7;

vi G[26];
int main() 
{
    int n,k;
    cin>>n>>k;
    string in;
    int count[26][26];
    memset(count,0,sizeof count);
    for(int i=0;i<n;i++){
        cin>>in;
        for(int j=0;j<k;j++){
            int u = (in[j]-'A');
            for(int l=j+1;l<k;l++){
                int v = (in[l]-'A');    
                count[u][v]++;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(count[i][j]==n){
                G[i].push_back(j);
            }
        }
    }
    queue<int> nodes;
    int dist[k];
    for(int i=0;i<k;i++) dist[i] = -INF;
    int into[k];
    memset(into,0,sizeof into);
    for(int u=0;u<k;u++){
        for(int v:G[u]){
            into[v]++;
        }
    }
    for(int i=0;i<k;i++){
        if(into[i]==0){
            nodes.push(i);
            dist[i] = 1;
        }
    }
    int ans = 1;
    while(!nodes.empty()){
        int u = nodes.front(); nodes.pop();
        for(int v: G[u]){
            if(dist[v]<dist[u]+1){
                dist[v] = dist[u]+1;
                nodes.push(v);
                ans = max(ans,dist[v]);
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}