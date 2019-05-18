#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    stack<char> stk;
    int ans=0;
    for(int i=0;i<s.length();i++) {
        if(!stk.empty()&&s[i]==stk.top()) {
            stk.pop();
            ans++;
        }
        else stk.push(s[i]);
    }
    if(ans&1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
