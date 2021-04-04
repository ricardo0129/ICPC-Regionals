#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    cin>>in;
    int occurence[26];
    memset(occurence,0,sizeof occurence);
    bool possible = true;
    for(int i=0;i<in.size();i++){
        int letter = (in[i]-'a');
        occurence[letter]++;
        if(occurence[letter]>=2) possible = false;
    }
    cout<<possible<<endl;
    return 0;
}