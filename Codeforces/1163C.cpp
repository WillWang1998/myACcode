#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct Point {
    int x,y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y) {}
    Point operator -(const Point &p) {
        return Point(x-p.x,y-p.y);
    }
    Point calc() {
        if(x==0) {
            return Point(0,1);
        } else if(y==0){
            return Point(1,0);
        }
        int g=__gcd(x,y);
        x/=g;
        y/=g;
        if(x==-1) {
            x=-x;
            y=-y;
        }
        return Point(x,y);
    }
    bool operator <(const Point &p) const {
        if(x==p.x) return y<p.y;
        return x<p.x;
    }
}point[1005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&point[i].x,&point[i].y);
    map<Point,set<int>> mp;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            Point temp=point[i]-point[j];
            temp=temp.calc();
            mp[temp].insert(point[i].y*temp.x-point[i].x*temp.y);
        }
    }
    LL ans=0,sum=0;
    for(auto it:mp) {
        LL temp=it.second.size();
        sum+=temp;
        ans-=temp*(temp-1)/2;
    }
    ans+=sum*(sum-1)/2;
    printf("%lld\n",ans);
    return 0;
}
