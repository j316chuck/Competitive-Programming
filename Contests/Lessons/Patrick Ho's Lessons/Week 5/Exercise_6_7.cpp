#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string str;
    map <string, double> chart;

    while(getline(cin, str))
    {

         map<string, double>::iterator itr=chart.find(str);
            if (itr == chart.end())
            {
               chart[str]= 1;
            }
            else
            {
                chart[str]= (*itr).second+1;
            }

            map<string, double>::iterator itr2 = chart.begin();

            int a = chart.size()
            if(a>=10)
            {
                while(itr2!=chart.end())
                {
                    sort((*itr).second, (*itr).second+10)
                }
            }

            else
            {
                while(itr2!=char.end())
                {
                    sort((*itr).second, (*itr).second+a)
                }
            }
    }
}
