#include<bits/stdc++.h>
using namespace std;
char s[5000006];
char t[5000006];
int nxt[5000006];
void getNext(const char* str,int len)
{
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
            nxt[++i]=++j;
        else
            j=nxt[j];
    }
}
int main() {
    scanf("%s%s",s,t);
    int n=strlen(t);
    getNext(t,n);
    int p=n-nxt[n],c0=0,c1=0,_c0=0,_c1=0;
    for(int i=0;s[i];i++) {
        if(s[i]=='0') c0++;
        else c1++;
    }
    for(int i=0;i<p;i++) {
        if(t[i]=='0') _c0++;
        else _c1++;
    }
//    cout<<c0<<" "<<c1<<" "<<_c0<<" "<<_c1<<endl;
    while(c0-_c0>=0&&c1-_c1>=0) {
        for(int i=0;i<p;i++) printf("%c",t[i]);
        c0-=_c0;
        c1-=_c1;
    }
    int now=0;
    while(1) {
        if(t[now]=='1'&&c1) {
            printf("1");
            c1--;
        } else if(t[now]=='1') break;
        else if(t[now]=='0'&&c0) {
            printf("0");
            c0--;
        } else if(t[now]=='1') break;
        now++;
    }
    for(int i=0;i<c0;i++) printf("0");
    for(int i=0;i<c1;i++) printf("1");
    printf("\n");
    return 0;
}
