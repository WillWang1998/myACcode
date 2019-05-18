#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int b,k;
    scanf("%d%d",&b,&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    bool flag=false;
    for(int i=1;i<=k;i++) {
        bool temp=false;
        if(i!=k&&(b&1)&&(a[i]&1)) temp=true;
        else if(i==k) temp=(a[i]&1);
        flag^=temp;
    }
    puts(flag?"odd":"even");
    return 0;
}
