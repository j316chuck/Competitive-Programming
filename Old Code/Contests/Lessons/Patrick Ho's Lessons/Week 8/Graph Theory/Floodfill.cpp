#include <iostream>
using namespace std;
string array[10][10];
void Floodfill(int x, int y)
{
    if(x<0||y<0||x>=10||y>=10||array[x][y]=="a")
    {
        return;
    }
    array[x][y]="a";
   Floodfill(x+1,y);
   Floodfill(x,y+1);
   Floodfill(x,y-1);
   Floodfill(x-1,y);
    array[x][y]="c";
}

int main()
{
    for(int i=0; i <10; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            cin>>array[i][k];
        }
    }
    Floodfill(0,0);
    cout<<total<<endl;
}
