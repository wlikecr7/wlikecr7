#include <stdlib.h>
#include <stdio.h>
int GetMaxChildArraySum(int * pInput, int nLen, int * pOut)
{
    if (!pInput || !pOut)
        return 0;
    if (nLen < 0)
        return 0;
    int nSum = 0;
    int nTempSum = 0;
    int nMax = pInput[0];
    int i = 0;
    for (i = 0; i < nLen; i++)
    {
        if (nTempSum <= 0)
        {
            nTempSum = pInput[i];
        }
        else
        {
            nTempSum += pInput[i];
        }    
        if (pInput[i] > nMax)
        {
            nMax = pInput[i];
        }
        if (nTempSum > nSum)
        {
            nSum = nTempSum;
        }
    }
    if (nMax < 0)
    {
        *pOut = nMax;
        return 1;
    }
    *pOut = nSum;        
    return 1;
}
int main()
{
    int Array[] = { 1, 2, 3, 7, 10, -7, -2, -5 };
    int nTemp = 0;
    GetMaxChildArraySum(Array, 8, &nTemp);
    printf("数组最大和:%d\n", nTemp);
    system("pause");
    return 0;
}