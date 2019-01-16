#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a;
    scanf("%d%d",&n,&m);
    map<int,int> mp;
    for(int i=1;i<=m;i++) {
        scanf("%d",&a);
        mp[a]++;
        if(mp.size()==n) {
            printf("1");
            for(auto it=mp.begin();it!=mp.end();) {
                it->second--;
                if(it->second==0) {
                    auto _it=it;
                    _it++;
                    mp.erase(it);
                    it=_it;
                } else it++;
            }
        } else printf("0");
    }
    return 0;
}
