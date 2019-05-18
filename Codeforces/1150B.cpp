#include<bits/stdc++.h>
using namespace std;
char mp[55][55];
int dir[4][2]={1,0,2,0,1,1,1,-1};
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>mp[i]+1;
    bool flag=true;
    bool _flag=false;
    for(int i=1;i<=n-2&&flag;i++) {
        for(int j=2;j<=n-1&&flag;j++) {
            if(mp[i][j]=='#') continue;
            else _flag=true;
            bool flag=true;
            for(int k=0;k<4;k++) {
                if(mp[i+dir[k][0]][j+dir[k][1]]=='#') {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                mp[i][j]='#';
                for(int k=0;k<4;k++) mp[i+dir[k][0]][j+dir[k][1]]='#';
            }

        }
    }
    if(_flag) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(mp[i][j]=='.')
                    _flag=false;
        if(_flag) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
