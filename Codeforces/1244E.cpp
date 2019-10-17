#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
map<int,int> mp;
int a[maxn];
int main() {
    int n;
    long long k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    auto itl=mp.begin();
    auto itr=mp.rbegin();
    while(k>0&&itl->first<itr->first) {
        if(itl->second<itr->second) {
            auto _it=itl;
            _it++;
            long long temp=min(1ll*(_it->first)-(itl->first),k/(itl->second));
            if(temp==0) {k=0;break;}
            mp[(itl->first)+temp]+=itl->second;
            k-=temp*(itl->second);
            mp.erase(itl);
            itl=mp.begin();
        } else {
            auto _it=itr;
            _it++;
            long long temp=min(1ll*(itr->first)-(_it->first),k/(itr->second));
            if(temp==0) {k=0;break;}
            mp[(itr->first)-temp]+=itr->second;
            k-=temp*(itr->second);
            mp.erase(itr->first);
            itr=mp.rbegin();
        }
    }
    if(k==0) {
        itl=mp.begin();itr=mp.rbegin();
        cout<<(itr->first)-(itl->first)<<endl;
    } else cout<<0<<endl;
    return 0;
}
