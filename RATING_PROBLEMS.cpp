#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    double sum = 0;
    double val;
    for(int i=0;i<k;i++){
        cin>>val;
        sum+=val;
    }
    int missingScores = (n-k);
    double maximum = (sum+missingScores*3)/n;
    double minimum = (sum+missingScores*-3)/n;
    printf("%lf %lf\n", minimum, maximum);
    return 0;
}