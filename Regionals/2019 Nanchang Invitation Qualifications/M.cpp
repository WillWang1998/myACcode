#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
set<int> st[26];
char S[maxn],T[maxn];
int nxt[maxn][26];
int main() {
    int n;
    scanf("%s",S+1);
    int len=strlen(S+1);
    memset(nxt,-1,sizeof(nxt));
    for(int i=1;i<=len;i++)
        st[S[i]-'a'].insert(i);
    for(int i=0;i<=len;i++)
        for(int j=0;j<26;j++) {
            auto it=st[j].lower_bound(i);
            if(it!=st[j].end()) nxt[i][j]=*it;
        }
    scanf("%d",&n);
    while(n--) {
        scanf("%s",T);
        int now=0;
        int l=0;
        while(T[now]!=0) {
            if(nxt[l][T[now]-'a']==-1) break;
            else {
                l=nxt[l][T[now]-'a']+1;
                now++;
            }
        }
        puts(T[now]==0?"YES":"NO");
    }
    return 0;
}
