#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
    string com,ans;
    while(cin>>com) {
        if(com!="start") break;
        cout<<"? 0 1"<<endl;
        cin>>ans;
        if(ans=="x") {
            cout<<"! 1"<<endl;
        } else {
            LL l=1,r=2;
            bool flag=true;
            while(flag) {
                cout<<"? "<<l<<" "<<r<<endl;
                cin>>ans;
                if(ans=="x") {
                    flag=false;
                } else {
                    l<<=1;
                    r<<=1;
                }
            }
            l++;
            while(l<=r) {
                LL mid=(l+r)>>1;
                cout<<"? "<<mid<<" "<<l-1<<endl;
                cin>>ans;
                if(ans=="x") l=mid+1;
                else if(ans=="y") r=mid-1;
                else return 0;
            }
            cout<<"! "<<l<<endl;
        }
    }
    return 0;
}
