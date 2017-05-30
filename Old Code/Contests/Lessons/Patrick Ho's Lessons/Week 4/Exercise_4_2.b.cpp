#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int a, b, c;
    char op1, op2;
    int r1, r2;

    for(int i = 0; i < N; i++)
    {
       scanf("%d %c %d %c %d",&a,&op1,&b,&op1,&c);
      // cin>>a>>op1>>b>>op2>>c;



       if(op1=='+' && op2=='+')
       {
           r1 = (a+b)+c;
           r2 =  a+(b+c);
       }

       else if(op1=='+' && op2=='-')
       {
           r1 = (a+b)-c;
           r2 =  a+(b-c);
       }

       else if(op1=='+' && op2=='*')
       {

           r1 = (a+b)*c;
           r2 =  a+(b*c);
       }

       else if(op1=='-' && op2=='+')
       {

           r1 = (a-b)+c;
           r2 =  a-(b+c);
       }

       else if(op1=='-' && op2=='+')
           r1 = (a-b)-c;
           r2 =  a-(b-c);
       }

       else if(op1=='-' && op2=='*')
           r1 = (a-b)*c;
           r2 =  a-(b*c);
       }

       else if(op1=='*' && op2=='+')
           r1 = (a*b)+c;
           r2 =  a*(b+c);
       }

       else if(op1=='*' && op2=='-')
           r1 = (a*b)-c;
           r2 =  a*(b-c);
       }

       else if(op1=='*' && op2=='*')
       {

           r1 = (a*b)*c;
           r2 =  a*(b*c);
       }

       if(r1>r2)
       {
           cout<<r1<<'\n';
       }
       else
        cout<<r2<<'\n';

    }
}
