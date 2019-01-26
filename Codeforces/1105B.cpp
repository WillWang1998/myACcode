#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int ans=0;
    for(int i=0;i<26;i++) {
        int cnt=0,temp=0;
        for(int j=0;j<s.length();j++) {
            if(s[j]=='a'+i) cnt++;
            else cnt=0;
            if(cnt==k) {
                temp++;
                cnt=0;
            }
        }
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
