#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int counter = 0;
    int counter2 = 0;


    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] ==' ')
        {
            counter++;
        }
        if(str[i] =='s')
        {
            counter2= counter2 +1;
        }
         if(str[i] == '\n')
        {
        break;
        }

    }
    cout<<counter<<' '<<counter2<<endl;

}
