#include<iostream>
#include<cmath>
float Calc(float a)
{
    if(a <= 1e-6 )
        return 0;
    float t = a;
    float x = a /2;
    while(fabs(x - t) > 1e-6)
    {
        t = x;
        x = (a / x + x) /2;
    }
    return x;
}
int main()
{
    for(int i = 0;i <10;i++)
    {
        std::cout<<Calc(i)<<"\t";
    }
    std::cout<<std::endl;
	return 0;
}
