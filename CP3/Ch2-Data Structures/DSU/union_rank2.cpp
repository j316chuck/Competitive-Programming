#include<stdio.h>
#define MOD 1000000007
int findParent(int i,int parent[])
//function to find the connected component that the ith node belongs to
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}
void unionNodes(int a,int b,int parent[],int size[])
//to merge the connected components of nodes a and b
{
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}

int main()
{

    int N,M,i,a,b;
    scanf(" %d %d",&N,&M);
    int parent[100001]={0},size[100001]={0};
    for(i=1;i<=N;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(i=1;i<=M;i++)
    {
        //scan each edge and merge the connected components of the two nodes
        scanf(" %d %d",&a,&b);
        unionNodes(a,b,parent,size);
    }

    for(i=1;i<=N;i++)
        printf("Node %d belongs to connected component %d\n",i,findParent(i,parent));
    long long ways=1;
    int nos=0;
    for(i=1;i<=N;i++)
    {
        if(findParent(i,parent)==i)//this condition is true only for disjoint connected components
        {
            printf("%d leader %d size\n",i,size[i]);
            nos++;
        }

    }
    printf("Total connected components : %d",nos);

    return 0;
}
