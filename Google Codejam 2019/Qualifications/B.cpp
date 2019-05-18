#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        int a;
        printf("Case #%d: ",tt);
        scanf("%d",&a);
        scanf("%s",s+1);
        for(int i=1;i<=2*(a-1);i++)
            if(s[i]=='E') printf("S");
            else printf("E");
        printf("\n");
    }
    return 0;
}
