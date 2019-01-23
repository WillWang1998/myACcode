#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int c1=0,c2=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='0') {
            c1++;
            cout<<1<<" "<<c1<<endl;
            if(c1==4) c1=0;
        } else {
            c2++;
            cout<<4<<" "<<c2*2-1<<endl;
            if(c2==2) c2=0;
        }
    }
    return 0;
}
