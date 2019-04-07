#include<bits/stdc++.h>
using namespace std;
char n[105];
bool dp[105][15][2],founded;
int len;
vector<int> ans;
bool dfs(int bit,int num,bool flag,bool prezero) {
    if(founded) {
        return false;
    } else if(!dp[bit][num][flag]) {
        return false;
    } else if(bit==len-1&&prezero) {
        return dp[bit][num][flag]=false;
    } else {
        int temp=n[bit]-'0';
        bool nextflag=false;
        if(temp==0&&flag) {
            temp=9;
            nextflag=true;
        } else if(flag) temp--;
        if(temp<num) {
            temp+=10;
            nextflag=true;
        }
        if(temp-num!=4&&bit==len-1&&!nextflag) {
            ans.push_back(num);
            founded=true;
            return dp[bit][num][flag]=true;
        } else if(temp-num!=4&&bit!=len-1){
            for(int i=0;i<=9;i++) {
                if(i==4) continue;
                bool nextprezero=prezero&&(i==0);
                if(dfs(bit+1,i,nextflag,nextprezero)) {
                    ans.push_back(num);
                    return dp[bit][num][flag]=true;
                }
            }
        } else {
            return dp[bit][num][flag]=false;
        }
    }
}
bool judge(char n[],int len) {
    if(n[len-1]!='1') return false;
    for(int i=0;i<len-1;i++) if(n[i]!='0') return false;
    return true;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++) {
        printf("Case #%d: ",tt);
        founded=false;
        memset(dp,true,sizeof(dp));
        scanf("%s",n);
        len=strlen(n);
        reverse(n,n+len);
        ans.clear();
        if(len==1) {
            for(int i=1;i<=9;i++) {
                if(i!=4&&n[0]-'0'-i>0&&n[0]-'0'-i!=4) {
                    printf("%d %d\n",i,n[0]-'0'-i);
                    break;
                }
            }
        } else if(judge(n,len)){
            printf("1 ");
            for(int i=0;i<len-1;i++) printf("9");
            printf("\n");
        } else {
            for(int i=0;i<=9;i++) {
                if(i==4) continue;
                if(dfs(0,i,false,i==0)) break;
            }
            vector<int> ansb;
            reverse(ans.begin(),ans.end());
            while(ans.back()==0) ans.pop_back();
            bool flag=false;
            for(int i=0;i<len;i++) {
                int temp=n[i]-'0';
                if(flag) {
                    temp--;
                    flag=false;
                }
                if(temp==-1) {
                    temp=9;
                    flag=true;
                }
                if(i<ans.size()) {
                    if(temp-ans[i]>=0) ansb.push_back(temp-ans[i]);
                    else {
                        ansb.push_back(temp+10-ans[i]);
                        flag=true;
                    }
                } else {
                    ansb.push_back(temp);
                }
            }
            reverse(ans.begin(),ans.end());
            for(auto it:ans) printf("%d",it);
            printf(" ");
            while(ansb.back()==0) ansb.pop_back();
            reverse(ansb.begin(),ansb.end());
            for(auto it:ansb) printf("%d",it);
            printf("\n");
        }
    }
    return 0;
}
