#include<iostream>

void Permutation(char* pStr, char *pBegin)
{
    if(*pBegin == '\0')
        std::cout<<pStr<<std::endl;
    else
    {
        for(char* pCh = pBegin;*pCh != '\0'; ++pCh)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
            
            Permutation(pStr, pBegin + 1);
            
            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
        }
    }
}

void Permutation(char *pStr)
{
    if(pStr == NULL)
        return;
    Permutation(pStr, pStr);
}
