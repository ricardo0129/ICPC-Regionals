#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define pii pair<int,int>

int ne;
vi C;
int position[(int)1e6+1];
class SegmentTree{
	public:
	int n; 
	vector<int> st,A;
	int left(int p) {return p<<1;} //*2
	int right(int p ) {return (p<<1)|1;} //*2+1
	void build(int p, int l, int r){
		if(l==r) 
		st[p]=A[l];
		else{
			build(left(p),l,(l+r)/2);
			build(right(p),(l+r)/2+1,r);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = max(p1,p2);
		}
	}
	int rmq(int p, int l, int r, int i, int j){
		if(i>r || j<l) return INT_MIN;
		if(l>=i && r<=j) return st[p];
		int p1 = rmq(left(p),l,(l+r)/2,i,j);
		int p2 = rmq(right(p),(l+r)/2+1,r,i,j);
		if(p1==-1) return p2;
		if(p2==-1) return p1;
		return max(p1,p2);
	}
	int rmq(int i, int j) {return rmq(1,0,n-1,i,j);}
	SegmentTree(const vector<int>& B){
		A = B; n = (int)A.size();
		st.assign(4*n,INT_MAX);
		build(1,0,n-1);
	}
};

SegmentTree* st;
int solve(int l, int r, int leftMax, int rightMax){
    if(l>r || l<0 || r>ne)  return 0;
    int maximum = 0,pos = 0;
    maximum = st->rmq(l,r);
    pos = position[maximum];
    int total = 0;
    if(leftMax!=-1 && (pos-leftMax)>=2) total++;
    if(rightMax!=-1 && (rightMax-pos)>=2) total++;
    total+=solve(l,pos-1,leftMax,pos);
    total+=solve(pos+1,r,pos,rightMax);
    return total;
}
int main()
{
    cin>>ne;
    C.resize(ne);
    for(int i=0;i<ne;i++){
        cin>>C[i];
        position[C[i]] = i;
    }
    st = new SegmentTree(C);

    int ans1 = solve(0,ne-1,-1,-1);
    cout<<ans1+ne-1<<endl;

    return 0;
}