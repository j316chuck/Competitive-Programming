#include <iostream>
using namespace std;

int main()
{

    string str;
    getline(cin, str);
    int counter = 0;
    int counter2 = 0;


    for(int i = 0; i < 100; i++)
    {
        if(str[i] == ' ')
        {
            counter++;
        }
         if(str[i] == '\n')
        {
        break;
        }
        if(str[i]== 's')
        {
            counter2++;
        }
    }
    cout<<counter<<' '<<counter2<<endl;

}
