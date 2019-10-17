#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        int ans=n;
        int st1=0;
        for(;st1<n;st1++) {
            if(s[st1]=='1') {
                break;
            }
        }
        if(ans<(n-st1)*2) {
            ans=(n-st1)*2;
        }
        reverse(s.begin(),s.end());
        int st2=0;
        for(;st2<n;st2++) {
            if(s[st2]=='1') {
                break;
            }
        }
        if(ans<(n-st2)*2) {
            ans=(n-st2)*2;
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            cnt+=(s[i]=='1');
        }
        ans=max(ans,cnt+n);
        cout<<ans<<endl;
    }
    return 0;
}
