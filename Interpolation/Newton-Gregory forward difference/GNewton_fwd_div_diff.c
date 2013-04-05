/* This program estimates the value of sin x at x = 25 degree using the Newton-Gregory
   forward difference formula with the help of given equally spaced 5 data points (values)
   for x = 10,20,30,40,50   */

#include <stdio.h>
#include <math.h>
#include <conio.h>

float gnfd( float, int );
float delJfI(int, int, float);
float newdiv(int u, int l);
float fact(float);
float binoCoeff(float, int);

float x[5] = {10, 20, 30, 40, 50};
float fx[5] = {0.1736, 0.3420, 0.5000, 0.6428, 0.7660};

int main()
{    
    float px = 25;
    float s, result;
    int n = sizeof(x)/4; // n == total no of points availabe
    
    s = ((px - x[0])/(x[1] - x[0]));
    
    result = gnfd(s,n);
    
    printf("\n\nThe value of f(%.2f) is : %f", px,result);
    
    
    getch();
    return 0;
} //end main

float gnfd( float s, int n )
{
      int i;
      float px = fx[0];
      float h = 10;
      
      for( i = 1; i < n; i++ )
      {
           px += (binoCoeff(s,i) * delJfI(i,0,h));
           printf("\np%d(%.2f) = %f ",i,s, px);
      }
      
      return px;     
} // end function gnfd

float binoCoeff(float s, int j)
{
      int i = 1;
      float tempS = s;
      while( i < j )
      {
             tempS *= (s-i);
             i++;
      }
             
      return (tempS/fact(j));
} //end binoCoeff
             
float fact(float n) // gives factorial value of given n.
{
      if( n == 0 || n == 1 )
          return 1;
      else
          return (n*fact(n-1));
} //end fact

float delJfI(int j, int i, float h) // gives jth order divided difference for ith function
{
      float result;
      
      result = (fact(j)*pow(h,j)*newdiv((i+j),i));
      
      return result;
}

float newdiv(int u, int l) // gives the divided difference for given boundries
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
}
