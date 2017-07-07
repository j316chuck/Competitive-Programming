#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

struct P
{
    int x,y,type ; /// 0 : G , 1 : H
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
}p[maxn];

int n ;
int ansnum=0 , area=0 ;
void up(int num,int A)
{
    if(num>ansnum || (num==ansnum && A<area)) ansnum=num , area=A ;
}

void solve(int y1,int y2)
{
    for(int i=1,num=0,last=0;i<=n;)
    {
        int j ;
        bool ok=1 ;
        for(j=i;j<=n && p[i].x==p[j].x;j++)
            if(p[j].y>=y1 && p[j].y<=y2)
        {
            if(p[j].type==0) ok=0 ;
            else
            {
                if(!num) last=p[j].x ;
                num++ ;
            }
        }

        if(!ok) { num=0 ; i=j ; continue ; }
        up(num,(y2-y1)*(p[i].x-last)) ;
        i=j ;
    }
}

vector<int> vy ;
main()
{

        freopen("cowrect.in","r",stdin) ;
        //freopen("cowrect.out","w",stdout) ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        char s[3] ; scanf("%d%d%s",&p[i].x,&p[i].y,s) ;
        if(s[0]=='H') p[i].type=1 ;
        else p[i].type=0 ;
        vy.push_back(p[i].y) ;
    }
    sort(p+1,p+n+1) ;
    sort(vy.begin(),vy.end()) ;
    vy.resize(unique(vy.begin(),vy.end())-vy.begin()) ;
    for(int i=0;i<vy.size();i++) for(int j=i;j<vy.size();j++)
        solve(vy[i],vy[j]) ;
    printf("%d\n%d\n",ansnum,area) ;
}

