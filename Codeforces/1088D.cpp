#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,flag,c1,c2,_a=0,_b=0;
    string s;
    cout<<"? 0 0"<<endl;
    cin>>flag;
    for(int i=29;i>=0;i--) {
        if(flag==1) {
            cout<<"? "<<(_a^(1<<i))<<" "<<(_b^(1<<i))<<endl;
            cin>>c1;
            if(c1==-1) {
                _a^=(1<<i);
                cout<<"? "<<_a<<" "<<_b<<endl;
                cin>>flag;
            } else {
                cout<<"? "<<(_a^(1<<i))<<" "<<_b<<endl;
                cin>>c2;
                if(c2==-1) {
                    _a^=(1<<i);
                    _b^=(1<<i);
                }
            }
        } else if(flag==0){
            cout<<"? "<<(_a^(1<<i))<<" "<<_b<<endl;
            cin>>c1;
            if(c1==-1) {
                _a^=(1<<i);
                _b^=(1<<i);
            }
        } else {
            cout<<"? "<<(_a^(1<<i))<<" "<<(_b^(1<<i))<<endl;
            cin>>c1;
            if(c1==1) {
                _b^=(1<<i);
                cout<<"? "<<(_a^(1<<i))<<" "<<(_b^(1<<i))<<endl;
                cin>>flag;
            } else {
                cout<<"? "<<(_a^(1<<i))<<" "<<_b<<endl;
                cin>>c2;
                if(c2==-1) {
                    _a^=(1<<i);
                    _b^=(1<<i);
                }
            }
        }
    }
    cout<<"! "<<_a<<" "<<_b<<endl;
    return 0;
}
