// from http://blog.csdn.net/jasison/article/details/8753814

struct BigInt
{
    int data[60];
    BigInt& operator = (const BigInt &ob)
    {
        memcpy(data, ob.data, sizeof(data));
        return *this;
    }
    BigInt& operator += (const BigInt &ob)
    {
        if (data[0] < ob.data[0]) data[0] = ob.data[0];
        for (int i = 1; i <= data[0]; ++ i)
        {
            data[i] += ob.data[i];
            if (data[i] >= 10)
            {
                data[i] -= 10;
                data[i+1] ++;
            }
        }
        if (data[data[0]+1] != 0) data[0] ++;
        return *this;
    }
    void setDigit(int n)
    {
        memset(data, 0, sizeof(data));
        data[0] = 1;
        data[1] = n;
    }
    BigInt operator * (const BigInt &ob)
    {
        BigInt pro;
        pro.setDigit(0);
        pro.data[0] = data[0] + ob.data[0] - 1;
        for (int i = 1; i <= data[0]; ++ i)
            for (int j = 1; j <= ob.data[0]; ++ j)
                pro.data[i+j-1] += data[i] * ob.data[j];
        for (int i = 1; i <= pro.data[0]; ++ i)
        {
            pro.data[i+1] += pro.data[i] / 10;
            pro.data[i] %= 10;
        }
        while (pro.data[pro.data[0]] >= 10)
        {
            pro.data[pro.data[0]+1] += pro.data[pro.data[0]] / 10;
            pro.data[pro.data[0]] %= 10;
            pro.data[0] ++;
        }
        return pro;
    }
    void print()
    {
        for (int i = data[0]; i > 0; -- i)
            printf("%d", data[i]);
    }
} f[105];

//usage example: Catalan Numbers;
void calc()
{
    f[0].setDigit(1);
    f[1].setDigit(1);
    for (int i = 2; i <= 100; ++ i)
    {
        f[i].setDigit(0);
        for (int j = 0; j < i; ++ j)
            f[i] += f[j] * f[i-j-1];
    }
}
