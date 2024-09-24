#include <bits/stdc++.h>  
using namespace std;  
int getNumberOfInfestor(); // you should finish this  
const int POPULATION = 1000000;  
bool test(int y)  
{  
    if (y < 1 || y > POPULATION) {  
        printf("error");  
        return false;  
    }  
    // result = 随机从POPULATION人中抽取y人核酸检测的结果。  
    return result;  
}  
int main()  
{  
    int n;  
    scanf("%d", &n);  
    long long seed;  
    scanf("%lld", &seed);  
    int result = getNumberOfInfestor();  
    printf("%d\n", result);  
    // 输出你的询问记录  
    return 0;  
}  
int getNumberOfInfestor() {  
    int l = 1, r = POPULATION, res = 1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (test(mid))
            l = mid + 1, res = mid;
        else 
            r = mid - 1;
    }
    return res;
   // you should finish this  
}  
