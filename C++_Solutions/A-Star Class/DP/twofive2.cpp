/*
ID:t-x.h1
LANG:C++
TASK:twofive
*/
#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define ok(x) (!t[x] || t[x]==deep+'A')
using namespace std;
FILE *fi=fopen("twofive.in","r"),*fo=fopen("twofive.out","w");
const int N=25;
char c,t[N+9];
int f[6][6][6][6][6];
bool mark[128];
int dfs(int a,int b,int c,int d,int e,int deep)
{
        if(deep==N)
                return 1;
        int &now=f[a][b][c][d][e];
        if(now)
                return now;
        if(a<5 && ok(a))
                now+=dfs(a+1,b,c,d,e,deep+1);
        if(b<a && ok(b+5))
                now+=dfs(a,b+1,c,d,e,deep+1);
        if(c<b && ok(c+10))
                now+=dfs(a,b,c+1,d,e,deep+1);
        if(d<c && ok(d+15))
                now+=dfs(a,b,c,d+1,e,deep+1);
        if(e<d && ok(e+20))
                now+=dfs(a,b,c,d,e+1,deep+1);
        return now;
}
int main()
{
        t[0] = 'A'; t[1] = 'B'; t[2] = 'C'; t[5] = 'D';
        cout << dfs(0, 0, 0, 0,0, 0);
        /*int i=fgetc(fi),ans=0;
        if(i=='N')
        {
                int n,tmp;
                fscanf(fi,"%d",&n);
                for(i=0;i<N;++i)
                        for(t[i]='A';memset(f,0,sizeof(f)),(tmp=dfs(0,0,0,0,0,0))<n;++t[i])
                                n-=tmp;
                fprintf(fo,"%s\n",t);
        }
        else
        {
                char s[N+9];
                fscanf(fi,"%s",s);
                for(i=0;i<N;++i)
                        for(t[i]='A';t[i]<s[i];++t[i])
                        {
                                memset(f,0,sizeof(f));
                                ans+=dfs(0,0,0,0,0,0);
                        }
                fprintf(fo,"%d\n",ans+1);
        }
        fclose(fi);
        fclose(fo);*/
        return 0;
}
