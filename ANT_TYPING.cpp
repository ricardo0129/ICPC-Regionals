#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long 

int A[10][10];
int main()
{
    string number;
    cin>>number;
    memset(A,0,sizeof A);

    for(int i=0;i<number.size()-1;i++){
        A[number[i]-'0'][number[i+1]-'0']++;      
    }
    vi keyboard = {1,2,3,4,5,6,7,8,9};
    sort(keyboard.begin(),keyboard.end());
    int ans = INT_MAX;
    do{
        int weight[10][10];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int u = keyboard[i];
                int v = keyboard[j];
                weight[u][v] = abs(i-j)+1;
            }
        }
        int currSum = 0;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                currSum+=A[i][j]*weight[i][j];
            }
        }
        ans = min(ans,currSum+weight[keyboard[0]][number[0]-'0']);

    }while(next_permutation(keyboard.begin(),keyboard.end()));

    cout<<ans<<endl;
    return 0;
}