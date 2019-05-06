#include<bits/stdc++.h>
using namespace std;
int n,dp[505][505];
string s;
vector<pair<char,int>> vec;
int main() {
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++) {
        if(i!=0&&s[i]!=s[i-1]) {
            vec.push_back(make_pair(s[i-1],cnt));
            cnt=0;
        }
        cnt++;
    }
    vec.push_back(make_pair(s.back(),cnt));
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<vec.size();i++)
        dp[i][i]=1;
    for(int l=2;l<=vec.size();l++) {
        for(int i=0;i+l-1<vec.size();i++) {
            dp[i][i+l-1]=min(dp[i][i+l-2],dp[i+1][i+l-1])+1;
            if(vec[i].first==vec[i+l-1].first)
                dp[i][i+l-1]=min(dp[i][i+l-1],dp[i+1][i+l-2]+1);
            for(int j=i+1;j<=i+l-2;j++)
                dp[i][i+l-1]=min(dp[i][i+l-1],dp[i][j]+dp[j][i+l-1]-1);
        }
    }
    cout<<dp[0][vec.size()-1]<<endl;
    return 0;
}
