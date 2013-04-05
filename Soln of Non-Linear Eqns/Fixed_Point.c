#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float fn_value( float * arr, int n, float x);
float calculate( float * arr, int n );
void get_data();

float gx0, x0, x1, error, err_check;
int degree, gx_degree,i,j=1,choice = 0;
float * gx_eqn;
float * user_gx_eqn;

int main (void)
{
    float root = 0, root2 = 0;
    
    printf("Enter the maximum degree of equation: ");
    scanf("%d",&degree);
    
    gx_eqn = (float*) malloc(degree+1);
        
    for( i = degree; i>=0; i--)
    {
         if ( i == 0)
         {
              printf("\nNow enter the constant term : ");
              scanf("%f",&gx_eqn[i]);
         }
         else
         {
             printf("\nEnter the coefficents of x^%d : ",i);
             scanf("%f",&gx_eqn[i]);
         }
    }//end for
    printf( "\nWhich method do you prefer? Choose 1 or 2\n\n1. I Want computer to create g(x) function.\n"
            "2. I want to enter myself the value of g(x).\n\n");
    scanf("%d",&choice);
    if( choice == 1 )
        gx_eqn[1]++;
    else
        get_data();
    
    printf("\nEnter the initial guess value for x0 :");
    scanf("%f",&x0);
    printf("\nNow enter the error precision (less than 0.0005 is recommended) : ");
    scanf("%f",&error);
    
    if( choice == 1 )
    {    
         root = calculate(gx_eqn, degree);    
         printf("\n\nThe root is %f ",root);
    }
    else
    {
        root2 = calculate(user_gx_eqn, gx_degree);    
        printf("\n\nThe root is %f ",root2);
    }
         
                  
    getch();
    return 0;
}//end main

float calculate( float * arr, int n )
{
      while(1)
    {
            printf("\n\nIteration no %d",j++);
            printf("\n-------------------------------");
            
            x1 = fn_value(arr, n, x0);
            printf("\nx0\t = %f\nx1\t = %f",x0,x1);
            
            err_check = fabs((x1-x0)/x1);
            printf("\nRelative error = %f ",err_check);
            
            if( err_check <= error)
                break;
            else
            {
                x0 = x1;
            }
    }//end while
    return x1;
}//end calculate

float fn_value( float * arr, int n, float x)
{
      float value = 0;
      int i;
      for( i = n; i>=0; i--)
           value += (arr[i]*pow(x,i));
           
      return value;
}//end fn_value
void get_data()
{
     printf("Enter the maximum degree of equation: ");
    scanf("%d",&gx_degree);
    
    user_gx_eqn = (float*) malloc(gx_degree+1);
        
    for( i = gx_degree; i>=0; i--)
    {
         if ( i == 0)
         {
              printf("\nNow enter the constant term : ");
              scanf("%f",&user_gx_eqn[i]);
         }
         else
         {
             printf("\nEnter the coefficents of x^%d : ",i);
             scanf("%f",&user_gx_eqn[i]);
         }
    }//end for
}//end get_data
