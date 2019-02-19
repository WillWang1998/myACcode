#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    int a,q;
    mp[3]=1;
    mp[7]=1;
    mp[15]=5;
    mp[31]=1;
    mp[63]=21;
    mp[127]=1;
    mp[255]=85;
    mp[511]=73;
    mp[1023]=341;
    mp[2047]=89;
    mp[4095]=1365;
    mp[8191]=1;
    mp[16383]=5461;
    mp[32767]=4681;
    mp[65535]=21845;
    mp[131071]=1;
    mp[262143]=87381;
    mp[524287]=1;
    mp[1048575]=349525;
    mp[2097151]=299593;
    mp[4194303]=1398101;
    mp[8388607]=178481;
    mp[16777215]=5592405;
    mp[33554431]=1082401;
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&a);
        if(mp.count(a)) {
            printf("%d\n",mp[a]);
        } else {
            int ans=0;
            while(a) {
                ans=((ans<<1)|1);
                a>>=1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
