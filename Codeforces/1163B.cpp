#include<bits/stdc++.h>
using namespace std;
int cnt[100005],a[100005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=1;
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        if(cnt[a[i]]) {
            mp[cnt[a[i]]]--;
            if(mp[cnt[a[i]]]==0) {
                mp.erase(cnt[a[i]]);
            }
        }
        cnt[a[i]]++;
        mp[cnt[a[i]]]++;
        if(mp.size()==1&&((mp.begin()->second==1)||(mp.begin()->first==1))) {
            ans=max(ans,i);
        } else if(mp.size()==2) {
            auto it=mp.begin();
            if(it->first==1&&it->second==1) {
                ans=max(ans,i);
            } else {
                int x=it->first;
                it++;
                int y=it->first;
                if(it->second==1&&y==x+1) {
                    ans=max(ans,i);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
