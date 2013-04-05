#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float fn_value( int * arr, int n, float x);

int main (void)
{
    float xl, xu, err, xm, errcheck, fxl, fxm;
    int degree,i,j=1;
    int * eqn;
    
    printf("Enter the maximum degree of equation: ");
    scanf("%d",&degree);
    
    eqn = (int*) malloc(degree+1);
        
    for( i = degree; i>=0; i--)
    {
         if ( i == 0)
         {
              printf("\nNow enter the constant term : ");
              scanf("%d",&eqn[i]);
         }
         else
         {
             printf("\nEnter the coefficents of x^%d : ",i);
             scanf("%d",&eqn[i]);
         }
    }//end for
    
    printf("\nEnter the initial guess value for xl and xu :");
    scanf("%f%f",&xl,&xu);
    printf("\nNow enter the error precision (less than 0.0005 is recommended) : ");
    scanf("%f",&err);
    
    while (1)
    {
          xm = ((xl+xu)/2);
          errcheck = fabs((xu-xl)/xu);
          fxl = fn_value(eqn, degree, xl);
          fxm = fn_value(eqn, degree, xm);
          printf("Iteration %d \n",j++);
          printf("------------------------------------------\n");
          printf(" xl\t= %.3f   xm\t= %.3f \n",xl, xm);
          printf(" f(xl)\t= %.3f   f(xu)\t= %.3f   f(xm)\t= %.3f \n\n", fxl, fn_value(eqn, degree, xu), fxm);
          
          if ( errcheck < err)
          {
               printf("\nThe Approximate root is\t= %f \n",xm);
               break;
          }
             
          else 
          {
               if ( (fxl * fxm) < 0 )
                  xu = xm;
               else 
                    xl = xm;
          }
    }//end while
                  
    getch();
    return 0;
}//end main

float fn_value( int * arr, int n, float x)
{
      float value = 0;
      int i;
      for( i = n; i>=0; i--)
           value += (arr[i]*pow(x,i));
           
      return value;
}//end fn_value
