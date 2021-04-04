#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define pi pair<int,int>

vi G[5000];
int Trees[5000];
int A_X[5000][5000];
int B_X[5000][5000];
//https://mathoverflow.net/questions/86817/counting-the-number-of-subgraphs-in-a-given-labeled-tree/86944#86944?newreg=357f098ffc2c4036925ae4b8192f918d

int n;
ll k;
void countTrees(int u, int p){
    int A = 1;
    int B = 0;
    for(int v: G[u]){
        if(p!=v)
            countTrees(v,u);
        A*=(1+A_X[v]);
    }
    for(int v:G[u]){
        B+=A_X[v]+B_X[v];
    }
    A_X[u] = A;
    B_X[u] = B;
    cout<<u<<" "<<A<<" "<<B<<endl;
}

int main()
{
    cin>>n>>k;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout<<"N"<<" "<<"A"<<" "<<"B"<<endl;
    memset(A_X,0,sizeof A_X);
    memset(B_X,0,sizeof B_X);
    countTrees(0,-1);


    return 0;
}