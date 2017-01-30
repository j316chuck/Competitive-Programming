void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;

    if(rank[PX]>rank[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY])
            rank[PY]++;
    }
}
