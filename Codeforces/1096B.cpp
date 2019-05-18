#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
char s[maxn];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    set<char> st;
    for(int i=0;i<n;i++)
        st.insert(s[i]);
    if(st.size()==1) {
        printf("%lld\n",(1ll*n*(n+1)/2)%998244353);
    } else if(s[0]!=s[n-1]) {
        int l=0,r=0;
        for(;l<n&&s[l]==s[0];l++);
        for(;r>=0&&s[n-1-r]==s[n-1];r++);
        l++;
        r++;
        printf("%d\n",l+r-1);
    } else {
        int l=0,r=0;
        for(;l<n&&s[l]==s[0];l++);
        for(;r>=0&&s[n-1-r]==s[n-1];r++);
        l++;
        r++;
        printf("%lld\n",1ll*l*r%998244353);
    }
    return 0;
}
