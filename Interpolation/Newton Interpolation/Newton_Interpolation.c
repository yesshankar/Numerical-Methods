/* This program estimates the value of log 2.5 using third order Newton Interpolation
   polynomial from the given values of logx ( which here is fx[] values ) for 4 values
   (points) of x i.e. x = 1,2,3,4 */

#include <stdio.h>
#include <conio.h>

float newdiv(int u, int l);
float multiple(int, float);

float x[4] = { 1, 2, 3, 4 };
float fx[4] = { 0, 0.3010, 0.4771, 0.6021 };
    
int main()
{
    
    int i, j, n = sizeof(x)/4; // n is number of points available 
    float reqd_x = 2.5; // value of x for wihich we need f(x) value
    
    float px = fx[0];
    
    for( i = 1; i < n; i++ )
    {
         px += (newdiv(i,0) * multiple(i,reqd_x));
    }
    
    printf("\nValue of f(%.2f) at p%d(%.2f) =  %f\n",reqd_x, n-1, reqd_x, px);
    
    
    getch();
    return 0;
} //end main

float newdiv(int u, int l) // this function returns Newton Divided Difference value for given boundries
{
     float result =0.0;
     int lb = l, ub = u;
     
     if( (ub - lb) == 1 ){
         result = ((fx[ub] - fx[lb])/(x[ub] - x[lb]));
     }else
     {
         result = ((newdiv(ub,lb+1) - newdiv(ub-1,lb))/(x[ub] - x[lb]));
     }
       
     return result;    
} // end function newdiv

float multiple(int n, float var) // gives the value of multiple of (x-xj) where j is 0 to n
{
      float result = 1.0;
      int i;
      
      for ( i = 0; i < n; i++ )
      {
          result *= (var - x[i]);
      }
      
      return result;
} //end function multiple
