#include<bits/stdc++.h>
using namespace std;
const int maxn=1825*100+7;
int cnt[maxn];
int main() {
    int n,h,r,t,max_h=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&h,&r,&t);
        max_h=max(max_h,h);
        if(r<t) {
            cnt[0]++;
            cnt[r+1]--;
            cnt[t]++;
            for(int rr=r+h;rr+1<maxn;rr+=h)
                cnt[rr+1]--;
            for(int tt=t+h;tt<maxn;tt+=h)
                cnt[tt]++;
        } else {
            for(int rr=r;rr+1<maxn;rr+=h)
                cnt[rr+1]--;
            for(int tt=t;tt<maxn;tt+=h)
                cnt[tt]++;
        }
    }
    for(int i=0;i<=max_h*1825;i++) {
        cnt[i]+=cnt[i-1];
        if(cnt[i]==n) {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("impossible");
    return 0;
}
