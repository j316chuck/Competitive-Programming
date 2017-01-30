#include <iostream>
using namespace std;


int Palindrome(int i)
{
    if(i >= 100000){
        if((i-i%100000)/100000 == i%10 ){
            if((i%100000-i%10000)/10000== (i%100-i%10)/10){
                if((i%10000-i%1000)/1000==(i%1000-i%100)/100){}
                return 1;
            }
        }
    }

    else if (i < 100000){
        if( (i-i % 100000)/100000 == i%10){
           if((i%100000-i%10000)/10000==(i%100-i%10)/10){
            return 1;
           }


        }
}
}

int main()
{
    int large = 1;

    for(int a = 100 ; a < 1000; a++){
        for(int b = 100 ; b < 1000; b++)
          {
              if( Palindrome(a*b)==1)
                if(a*b > large)
                large = a* b;
          }

    }

    cout<<large<< endl;
}

