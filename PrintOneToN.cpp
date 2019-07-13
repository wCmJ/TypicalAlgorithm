/*-----------------------METHOD 1------------------------------*/
#include<iostream>
void PrintNumber(char *pOut, int len, int index)
{
    if(index >= len)
    {
        std::cout<<pOut<<std::endl;
        return;
    }
    for(int i=0;i<=9;++i)
    {
        pOut[index] = '0' + i;
        PrintNumber(pOut, len, index + 1);    
    }
}
void PrintOneN(int n)
{
    if(n < 1)
        return;
    char *pOut = new char[n+1];
    int tmp = 1;
    while(tmp <= n)
    {
        pOut[tmp] = '\0';
        for(int i = 1;i<=9;++i)
        {
            pOut[0] = '0' + i;
            PrintNumber(pOut, tmp, 1);
        }
        ++tmp;
    }
}
/*-----------------------METHOD 1------------------------------*/

