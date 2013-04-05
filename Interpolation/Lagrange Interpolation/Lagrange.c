/* This program estimates the value of x at x = 1.2 from the given 4 data points
   using Lagrange Interpolation polynomial. */

#include <stdio.h>
#include <conio.h>

int main()
{
    int i, j, n = 4;
    float value = 1.0, pnvalue = 0.0, est = 1.2;
    float x[4] = { 0.0, 1.0, 2.0, 3.0 };
    float fx[4] = { 1.0, 2.7183, 7.3891, 20.0855 };

    float lix[4] = {0.0};
    
    for( i = 0; i < n; i++ )
    {
         for( j = 0; j < n; j++ )
         {
              if( i != j )
              {
                  value *= ((est - x[j])/(x[i] - x[j]));
              }
         }
         lix[i] = value;
         printf("\nl(%d)x = %.4f\n",i,value);
         value = 1.0;
    }
    
    for( i = 0; i < n; i++ )
    {
         pnvalue += (fx[i] * lix[i]);
    }
    
    printf("\nFinal value of p(%.2f) = %f",est,pnvalue);
        
    getch();
    return 0;
}//end main
