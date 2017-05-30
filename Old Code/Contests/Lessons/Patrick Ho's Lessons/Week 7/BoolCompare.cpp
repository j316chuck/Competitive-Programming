class three
{
    int x;
    int y;
    bool operator<(const three &a) const {
        if x < a.x return true;
        if x > a.x return false;
        return y < a.y
    }
};
1 1
2 2
3 3
4 4
