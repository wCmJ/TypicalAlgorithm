void ReverseOddEven(int *pdata, int length)
{
    if(pdata == NULL || length <= 1)
        return;
    int index1 = 0;
    int index2 = length - 1;
    while(index1 < index2)
    {
        while(index1 < index2 && ((pdata[index1] & 0x1) == 1)
            ++index1;
        while(index1 < index2 && ((pdata[index2] & 0x1) == 0))
            --index2;
        if(index1 < index2)
        {
            pdata[index1] = pdata[index1] ^ p[index2];
            pdata[index2] = pdata[index1] ^ p[index2];
            pdata[index1] = pdata[index1] ^ p[index2];
        }
    
    }
}
