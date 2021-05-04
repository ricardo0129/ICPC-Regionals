#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define pii pair<int,int>
const int INF = (int)1e9+7;
int n, k;
vi P;
map<int,int> points;
map<int,int> weights;


class SegTree{
    public:
    int st[(int)4e5+4][4];
    int s[(int)4e5+4];

    int left(int p){return (p<<1);}
    int right(int p){return (p<<1)|1;}

    int merge(int arr1[], int arr2[], int arr3[], int n1, int n2){
        int n3 = 0, i_1=0, i_2=0;
        while(i_1<n1 && i_2<n2 && n3<k){
            if(arr1[i_1]>arr2[i_2])
                arr3[n3++] = arr1[i_1++];
            else 
                arr3[n3++] = arr2[i_2++];
        }
        while(i_1<n1 && n3<k)
            arr3[n3++] = arr1[i_1++];
        while(i_2<n2 && n3<k)
            arr3[n3++] = arr2[i_2++];
        return n3;
    }
    void build(int p, int l, int r){
        if(l==r){
            s[p] = 1;
            st[p][0] = points.find(P[l])->second;
            return;
        }
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        s[p] = merge(st[left(p)],st[right(p)],st[p],s[left(p)],s[right(p)]);
    }
    int rmq(int p, int l, int r, int i, int j, int arr[]){
        if(i>r || j<l) return 0;
        if(l>=i && r<=j){
            for(int k=0;k<s[p];k++){
                arr[k] = st[p][k];
            }
            return s[p];
        }
        int arr1[4], arr2[4];
        int s1 = rmq(left(p),l,(l+r)/2,i,j,arr1);
        int s2 = rmq(right(p),(l+r)/2+1,r,i,j,arr2);
        return merge(arr1,arr2,arr,s1,s2);
    }

    SegTree(){
        build(1,0,n-1);
    }
};

SegTree* st;

int getView(int l, int r, int arr[]){
    int i = lower_bound(P.begin(),P.end(),l)-P.begin();
    int j = lower_bound(P.begin(),P.end(),r)-P.begin();
    i = max(0,i); j = min(j,n-1);
    if(P[j]>r) j--;
    if(P[i]<l) i++;
    if(i>j || i<0 || j>=n) return 0;
    int s = st->rmq(1,0,n-1,i,j,arr);
    return s; 
}
vector<pii> G[(int)1e5+7][29];

int main()
{
    scanf("%d %d",&n, &k);
    P.resize(n);
    int x;
    weights[0] = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        P[i] = x;
        points[x] = i+1;
        weights[i+1] = x;
    }
    sort(P.begin(),P.end());

    st = new SegTree();
    //(weight,(pos,zoom))
    //set<pair<int,pii>> pq;
    //priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    queue<pair<int,pii>> pq;

    vector<vi> dist(n+1,vi(29,INF));
    dist[0][1] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<29;j++){
            if(j!=28)
                G[i][j].push_back({i,j+1});
            if(j!=0)
                G[i][j].push_back({i,j-1});
            int l,r;
            if(j==0){
                l = weights.find(i)->second; r = weights.find(i)->second;
            }
            else{
                l = -(1<<(j-1))+weights.find(i)->second; r = (1<<(j-1))+weights.find(i)->second;
            }
            int arr[4];
            int nodes = getView(l,r,arr);
            for(int k=0;k<nodes;k++){
                int xs = arr[k];
                if(xs!=i){
                    G[i][j].push_back({xs,j});
                }
            }
        }
    }
    pq.push({0,{0,1}});
    while(!pq.empty()){
        pair<int,pii> q = pq.front();   
        pq.pop();
        int w = q.first; pii v = q.second;
        if(dist[v.first][v.second]!=w) continue;
        for(pii u: G[v.first][v.second]){
            if(dist[u.first][u.second]>dist[v.first][v.second]+1){
                dist[u.first][u.second] = dist[v.first][v.second]+1;
                pq.push({dist[u.first][u.second],{u.first,u.second}});
            }
        }
    }

    for(int i=0;i<n;i++){
        int ans = INF;
        for(int j=0;j<29;j++){
            int l,r;
            if(j==0){
                l = weights.find(i+1)->second; r = weights.find(i+1)->second;
            }
            else{
                l = -(1<<(j-1))+weights.find(i+1)->second; r = (1<<(j-1))+weights.find(i+1)->second;
            }
            int arr[4];
            int nodes = getView(l,r,arr);
            bool inside = false;
            for(int s = 0;s<nodes;s++){
                if(arr[s]==i+1) inside = true;
            }
            if(inside)
                ans = min(ans,dist[i+1][j]);
        }
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}