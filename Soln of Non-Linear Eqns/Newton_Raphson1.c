#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int * derivative( int * arr, int n);
float fn_value( int * arr, int n, float x);

int main (void)
{
    float fx, f_x, x0, x1,error, err_check;
    int degree,i,j=1;
    int * eqn;
    int * deriv_eqn;
    
    printf("Enter the maximum degree of equation: ");
    scanf("%d",&degree);
    
    eqn = (int*) malloc(degree+1);
    deriv_eqn = (int*) malloc(degree);
        
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
    
    deriv_eqn = derivative(eqn, degree);
    
    printf("\nEnter the initial guess value for x0 :");
    scanf("%f",&x0);
    printf("\nNow enter the error precision (less than 0.0005 is recommended) : ");
    scanf("%f",&error);
    
    while(1)
    {
            printf("\n\nIteration no %d",j++);
            printf("\n-------------------------------");
            
            fx = fn_value(eqn, degree, x0);
            printf("\nf(x0)\t = %f  ",fx); 
    
            f_x = fn_value (deriv_eqn, degree-1, x0);
            printf("\nf'(x0)\t = %f  ",f_x);
            
            x1 = (x0-(fx/f_x));
            printf("\nx1\t = %f ",x1);
            
            err_check = fabs((x1-x0)/x1);
            printf("\nRelative error = %f ",err_check);
            
            if( err_check <= error)
                break;
            else
                x0 = x1;
    }//end while
    
        
    printf("\n\nThe root is %f ",x1);
                  
    getch();
    return 0;
}//end main

int* derivative( int * arr, int n)
{
     int i;
     int * deriv = (int*)malloc(n);
     
     for( i = n; i > 0; i--)
     {
          deriv[i-1] = arr[i]*i;
          
     }      
     return deriv;
}//end derivative

float fn_value( int * arr, int n, float x)
{
      float value = 0;
      int i;
      for( i = n; i>=0; i--)
           value += (arr[i]*pow(x,i));
           
      return value;
}//end fn_value
