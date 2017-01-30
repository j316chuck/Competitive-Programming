#include <iostream>
using namespace std;

int main()
{
    string str;
    cin>>str;
    string str2;
    cin>>str2;

    int counter = 0;
    for(int i = 0; i < str.length(); i++)
    {

        if(str2[0]==str[i]&&str2[1]==str[i+1])
        {
            for(int k = 0; k < str2.size(); k++)
            {
                if(str2[k]!=str[i+k])
                {
                    break;
                }
                if(k == str2.size()-1)
                {
                    counter =1;
                    cout<<i<<'\n';
                    break;
                }
            }
            s
        }
    }

    if(counter !=1)
    {
        cout<<"-1"<<'\n';
    }
}
