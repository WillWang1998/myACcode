#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int maxn=400005;
bool isprime[maxn];
vector<int> prime;
int a[maxn],sum,cnt[3],num_a[maxn],num_b[maxn];
struct Seg {
    int i,l,r;
    bool operator < (const Seg &s) {
        if(r-l==s.r-s.l) return i<s.i;
        return r-l>s.r-s.l;
    }
};
vector<Seg> vec;
void init() {
    for(int i=2;i<prime.size();i++) {
        vec.push_back({i,prime[i-1],prime[i]});
    }
    vec.push_back({(int)prime.size(),prime[prime.size()-1],sum+1});
    sort(vec.begin(),vec.end());
}
int solve(int a,int b,int *num) {
    int ans=0;
    for(int i=0;i<vec.size();i++) {
        for(int j=vec[i].l;j<min(vec[i].r,sum);) {
            if(isprime[j]) ans++;
            if(b&&min(vec[i].r,sum)-j>=2) {
                num[j]=2;
                j+=2;
                b--;
            } else {
                num[j]=1;
                j++;
                a--;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        sum+=a[i];
    }
    if(n==1) {
        printf("%d\n",a[1]);
        return 0;
    }
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=sum;i++) {
        if(isprime[i]) prime.push_back(i);
        for(int j=0;j<prime.size()&&prime[j]<=sum/i;j++) {
            isprime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    init();
    int ans_a=0,ans_b=0;
    if(cnt[1]==0) {
        for(int i=1;i<=n;i++) printf("%d%c",2," \n"[i==n]);
        return 0;
    } else if(cnt[2]==0) {
        for(int i=1;i<=n;i++) printf("%d%c",1," \n"[i==n]);
        return 0;
    } else if(cnt[1]==1) {
        for(int i=1;i<=n;i++) printf("%d%c",i==2?1:2," \n"[i==n]);
        return 0;
    } else if(cnt[2]==1) {
        for(int i=1;i<=n;i++) printf("%d%c",i==1?2:1," \n"[i==n]);
        return 0;
    } else if(cnt[1]>=3) {
        ans_a=solve(cnt[1]-3,cnt[2],num_a);
    } else if(cnt[1]>=1&&cnt[2]>=1) {
        ans_b=solve(cnt[1]-1,cnt[2]-1,num_b);
    }
    if(ans_a>ans_b) {
        printf("1 1 1");
        for(int i=3;i<sum;i+=num_a[i]) {
            printf(" %d",num_a[i]);
        }
        printf("\n");
    } else {
        printf("2 1");
        for(int i=3;i<sum;i+=num_b[i])
            printf(" %d",num_b[i]);
        printf("\n");
    }
    return 0;
}
