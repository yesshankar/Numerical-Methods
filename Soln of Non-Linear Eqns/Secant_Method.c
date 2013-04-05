#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float fn_value( int * arr, int n, float x);

int main (void)
{
    float fx1, fx2, x1, x2, x3, error, err_check;
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
    
    printf("\nEnter the initial guess value for x1 and x2 :");
    scanf("%f%f",&x1,&x2);
    printf("\nNow enter the error precision (less than 0.0005 is recommended) : ");
    scanf("%f",&error);
    
    while(1)
    {
            printf("\n\nIteration no %d",j++);
            printf("\n-------------------------------");
            
            printf("\nx1\t = %f\nx2\t = %f",x1,x2);
            fx1 = fn_value(eqn, degree, x1);
            printf("\nf(x1)\t = %f  ",fx1); 
    
            fx2 = fn_value(eqn, degree, x2);
            printf("\nf(x2)\t = %f  ",fx2);
            
            x3 = (x2-((fx2*(x2-x1))/(fx2-fx1)));
            printf("\nx3\t = %f ",x3);
            
            err_check = fabs((x3-x2)/x3);
            printf("\nRelative error = %f ",err_check);
            
            if( err_check <= error)
                break;
            else
            {
                x1 = x2;
                //fx1 = fx2;
                x2 = x3;
                //fx2 = fn_value(eqn, degree, x3);
                
            }
    }//end while
    
        
    printf("\n\nThe root is %f ",x3);
                  
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
