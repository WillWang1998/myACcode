#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=100005;
char s[maxn];
int dx[maxn],dy[maxn];
int main() {
    int n,x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        if(s[i]=='U') {
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]+1;
        } else if(s[i]=='D') {
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]-1;
        } else if(s[i]=='L') {
            dx[i]=dx[i-1]-1;
            dy[i]=dy[i-1];
        } else {
            dx[i]=dx[i-1]+1;
            dy[i]=dy[i-1];
        }
    }
    LL l=0,r=2e14;
    while(l<=r) {
        LL mid=(l+r)>>1;
        LL t=mid/n;
        LL sur=mid%n;
        if(abs(x2-(x1+t*dx[n]+dx[sur]))+abs(y2-(y1+t*dy[n]+dy[sur]))<=mid) r=mid-1;
        else l=mid+1;
    }
    if(l>2e14) l=-1;
    printf("%lld\n",l);
    return 0;
}
