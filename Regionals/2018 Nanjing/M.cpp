#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
char s[maxn],t[maxn],_s[maxn],ma[maxn<<1];
int len_s,len_t,nxt[maxn],extend[maxn],mp[maxn<<1];
void pre_EKMP(char *x,int m,int *nxt) {
    nxt[0]=m;
    int j=0;
    while(j+1<m&&x[j]==x[j+1]) j++;
    nxt[1]=j;
    int k=1;
    for(int i=2;i<m;i++) {
        int p=nxt[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1) nxt[i]=L;
        else {
            j=max(0,p-i+1);
            while(i+j<m&&x[i+j]==x[j]) j++;
            nxt[i]=j;
            k=i;
        }
    }
}
void EKMP(char *x,int m,char *y,int n,int *nxt,int *extend){
    pre_EKMP(x,m,nxt);
    int j=0;
    while(j<n&&j<m&&x[j]==y[j]) j++;
    extend[0]=j;
    int k=0;
    for(int i=1;i<n;i++) {
        int p=extend[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1) extend[i]=L;
        else {
            j=max(0,p-i+1);
            while(i+j<n&&j<m&&y[i+j]==x[j]) j++;
            extend[i]=j;
            k=i;
        }
    }
}
int cnt[maxn];
void manacher(char *s,int len) {
    int l=0;
    ma[l++]='$';
    ma[l++]='#';
    for(int i=0;i<len;i++) {
        ma[l++]=s[i];
        ma[l++]='#';
    }
    ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++) {
        mp[i]=mx>i?min(mp[2*id-i],mx-i):1;
        while(ma[i+mp[i]]==ma[i-mp[i]]) mp[i]++;
        if(i+mp[i]>mx) {
            mx=i+mp[i];
            id=i;
        }
        cnt[max(0,(i-mp[i])/2-1)]++;
        cnt[max(0,i/2-1)]--;
    }
}
int main() {
    scanf("%s",s);
    scanf("%s",t);
    len_s=strlen(s);
    len_t=strlen(t);
    strcpy(_s,s);
    reverse(_s,_s+len_s);
    manacher(s,len_s);
    EKMP(t,len_t,_s,len_s,nxt,extend);
    for(int i=1;i<len_s;i++)
        cnt[i]+=cnt[i-1];
    long long ans=0;
    for(int i=0;i<len_s;i++)
        ans+=1ll*cnt[i]*extend[len_s-1-i];
    printf("%lld\n",ans);
    return 0;
}
