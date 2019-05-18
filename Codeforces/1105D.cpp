#include<bits/stdc++.h>
using namespace std;
const int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct State {
    int x,y,remain,step,player;
    bool operator < (const State &s) const {
        if(step==s.step&&player==s.player) return remain<s.remain;
        else if(step==s.step) return player>s.player;
        else return step>s.step;
    }
    void show() {
        cout<<x<<" "<<y<<" "<<remain<<" "<<step<<" "<<player<<endl;
    }
};
char mp[1005][1005];
int s[10],ans[10];
int main() {
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=p;++i) scanf("%d",&s[i]);
    for(int i=1;i<=n;++i) scanf("%s",mp[i]+1);
    priority_queue<State> quu;
    for(int k=1;k<=p;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(mp[i][j]=='0'+k) {
                    quu.push({i,j,0,0,k});
                    ++ans[k];
                }
    while(!quu.empty()) {
        State cur=quu.top();
        quu.pop();
//        cur.show();
        int _remain=cur.remain,_step=cur.step,_player=cur.player;
        if(_remain==0) {
            quu.push({cur.x,cur.y,s[_player],_step+1,_player});
        } else {
            for(int i=0;i<4;i++) {
                int _x=cur.x+dir[i][0],_y=cur.y+dir[i][1];
                if(_x>=1&&_x<=n&&_y>=1&&_y<=m
                   &&mp[_x][_y]=='.') {
                    quu.push({_x,_y,_remain-1,_step,_player});
                    mp[_x][_y]='0'+_player;
                    ++ans[_player];
                }
            }
        }
    }
    for(int i=1;i<=p;++i) printf("%d%c",ans[i]," \n"[i==p]);
    return 0;
}
