#include<bits/stdc++.h>
using namespace std;
string s,t;
set<int> st[26];
int main() {
    cin>>s>>t;
    long long ans=0,__i=0;
    for(int i=0;i<s.length();i++)
        st[s[i]-'a'].insert(i);
    for(int i=0;i<s.length();i++) {
        int _i=i,now=0;
        while(s[_i]==t[now]&&now<t.length()) {
            if(now+1!=t.length()) {
                auto it=st[t[now+1]-'a'].upper_bound(_i);
                if(it!=st[t[now+1]-'a'].end()) _i=*it;
                else break;
            }
            now++;
        }
        if(now==t.length()) {
            ans+=1ll*(i-__i+1)*(s.length()-_i);
            __i=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
