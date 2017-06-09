/*
From http://blog.csdn.net/u013480600/article/details/39269495
because I could not get the implementation right :(
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
};

typedef Point Vector;
Vector operator-(Point A,Point B) {
    return Vector(A.x-B.x, A.y-B.y);
}

long long Cross(Vector A,Vector B) {
    return A.x*B.y-A.y*B.x;
}

long long PolygonArea(Point *p,int n) {
    long long area=0;
    for(int i=1;i<n-1;++i)
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area<0?-area:area;
}

const int dx[]={0,-1,0,1,-1,0,1,-1,0,1};//
const int dy[]={0,-1,-1,-1,0,0,0,1,1,1};
const int maxn=1000000+5;
char str[maxn];
Point p[maxn];
int n;

int main()
{
    int T; scanf("%d%*c",&T);
    while(T--) {
        n=0;
        p[0]=Point(0,0);
        scanf("%s",str);
        n=strlen(str)-1;
        for(int i=0;i<n-1;++i)
            p[i+1]=Point(p[i].x+dx[str[i]-'0'], p[i].y+dy[str[i]-'0']);
        long long ans=PolygonArea(p,n);
        if(ans%2==0)printf("%I64d\n",ans/2);
        else printf("%I64d.5\n",ans/2);
    }
    return 0;
}
