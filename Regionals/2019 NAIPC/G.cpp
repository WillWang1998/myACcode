#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
struct Line {
    int y;
    pii p;
    bool flag;
    bool operator < (const Line &l) {
        if(y==l.y) return flag<l.flag;
        return y<l.y;
    }
    void print() {
        cout<<y<<" "<<p.first<<" "<<p.second<<endl;
    }
}line[200005];
bool intersect(pii a,pii b) {
    if((b.first<a.first&&a.first<b.second)||(b.first<a.second&&a.second<b.second))
        return true;
    else return false;
}
int main() {
    int n,x1,y1,x2,y2;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x1>>y1>>x2>>y2;
        line[i<<1]={y1,make_pair(x1,x2),true};
        line[i<<1|1]={y2,make_pair(x1,x2),false};
    }
    sort(line,line+2*n);
    map<int,int> mp;
    mp[-1000000007]=-1000000001;
    mp[1000000001]=1000000007;
    for(int i=0;i<2*n;i++) {
        if(line[i].flag) {
            auto it=mp.upper_bound(line[i].p.first);
            pii l1=*it;
            it--;
            pii l2=*it;
            if(intersect(l1,line[i].p)||intersect(l2,line[i].p)) {
                cout<<1<<endl;
                return 0;
            } else mp.insert(line[i].p);
        } else {
            auto it=mp.find(line[i].p.first);
            mp.erase(it);
        }
    }
    mp[-1000000007]=-1000000001;
    mp[1000000001]=1000000007;
    reverse(line,line+2*n);
    for(int i=0;i<2*n;i++) {
        if(!line[i].flag) {
            auto it=mp.upper_bound(line[i].p.first);
            pii l1=*it;
            it--;
            pii l2=*it;
            if(intersect(l1,line[i].p)||intersect(l2,line[i].p)) {
                cout<<1<<endl;
                return 0;
            } else mp.insert(line[i].p);
        } else {
            auto it=mp.find(line[i].p.first);
            mp.erase(it);
        }
    }
    cout<<0<<endl;
    return 0;
}
