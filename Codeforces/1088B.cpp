#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
    int n,k,a;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        st.insert(a);
    }
    int temp=0;
    for(int i=0;i<k;i++) {
        if(st.empty()) puts("0");
        else {
            printf("%d\n",*st.begin()-temp);
            temp=*st.begin();
            st.erase(st.begin());
        }
    }
    return 0;
}
