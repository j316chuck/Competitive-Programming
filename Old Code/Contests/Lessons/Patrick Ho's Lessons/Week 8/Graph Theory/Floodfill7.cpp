#include <iostream>
using namespace std;

string A[100];
int N;
bool valid[256][256];
bool visited[100][100];

void visit(int i, int j)
{
    if(visited[i][j]) return;
    visited[i][j]=true;
    if(i>0 &&valid[A[i-1][j]][A[i][j]]) visit(i-1, j);
    if(j>0 &&valid[A[i][j-1]][A[i][j]]) visit(i, j-1);
    if(i<N-1 &&valid[A[i+1][j]][A[i][j]]) visit(i+1, j);
    if(i<N-1 &&valid[A[i][j+1]][A[i][j]]) visit(i, j+1);

}

int solve()
{
    int count =0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j]=false;


    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!visited[i][j])
            {
                count++;
                visit(i, j);
            }
            return count;
}

int main()
{
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    valid['R']['R']=valid['B']['B']=valid['G']['G']=true;
    int human =solve();
    cout<<human<<endl;
}


