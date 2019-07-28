#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int maxn=1e5+1;
int N,G,M,H[maxn],latest[maxn][2],ans[maxn],start[maxn][2];
bool di[maxn];
char s[3];
vector<int> vec[maxn][2];
set<int> st[2];
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        for(int i=0;i<maxn;i++) {
            vec[i][0].clear();
            vec[i][1].clear();
        }
        st[0].clear();
        st[1].clear();
        memset(ans,0,sizeof(ans));
        memset(latest,-1,sizeof(latest));
        memset(start,0,sizeof(start));
        printf("Case #%d:",t);
        scanf("%d%d%d",&N,&G,&M);
        for(int i=0;i<G;i++) {
            scanf("%d%s",&H[i],s);
            H[i]--;
            if(s[0]=='C') {
                st[0].insert(H[i]);
                di[i]=0;
            }
            else {
                st[1].insert(H[i]);
                di[i]=1;
            }
            vec[H[i]][di[i]].push_back(i);
        }
        for(auto it=st[0].begin();it!=st[0].end();it++) {
            auto _it=it;
            if(_it==st[0].begin()) _it=st[0].end();
            _it--;
            int itv=*it-*_it;
            if(itv<=0) itv+=N;
            int step=min(itv,M);
            int now=(*it+M)%N;
            for(int j=0;j<=step;j++) {
                if(now<0) now=N-1;
                if(latest[now][0]<M-j) {
                    latest[now][0]=M-j;
                    start[now][0]=*it;
                }
                now--;
            }
        }
        for(auto it=st[1].rbegin();it!=st[1].rend();it++) {
            auto _it=it;
            if(_it==st[1].rbegin()) _it=st[1].rend();
            _it--;
            int itv=*_it-*it;
            if(itv<=0) itv+=N;
            int step=min(itv,M);
            int now=((*it-M)%N+N)%N;
            for(int j=0;j<=step;j++) {
                if(now>=N) now=0;
                if(latest[now][1]<M-j) {
                    latest[now][1]=M-j;
                    start[now][1]=*it;
                }
                now++;
            }
        }
        for(int i=0;i<N;i++) {
            if(latest[i][0]<latest[i][1]) {
                for(auto it:vec[start[i][1]][1])
                    ans[it]++;
            } else if(latest[i][0]>latest[i][1]) {
                for(auto it:vec[start[i][0]][0])
                    ans[it]++;
            } else if(latest[i][0]!=-1){
                for(auto it:vec[start[i][0]][0])
                    ans[it]++;
                for(auto it:vec[start[i][1]][1])
                    ans[it]++;
            }
        }
        for(int i=0;i<G;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
