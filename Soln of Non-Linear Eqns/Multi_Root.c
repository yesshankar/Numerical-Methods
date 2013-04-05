#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void poly( int * arr, int n, float x0 );
float newton( int * arr, float x0 );
int * derivative( int * arr, int n);
float fn_value( int * arr, int n, float x);

float fx, f_x, x0, x1,error, err_check,root;
int degree,i,j=1;
int * eqn;
int * deriv_eqn;

int main (void)
{
    int rcount = 1;
        
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
             printf("\nEnter the coefficient of x^%d : ",i);
             scanf("%d",&eqn[i]);
         }
    } //end for
        
    printf("\nEnter the initial guess value for x0 :");
    scanf("%f",&x0);
    printf("\nNow enter the error precision (less than 0.0005 is recommended) : ");
    scanf("%f",&error);
    while (degree > 1)
    {
          root = newton( eqn, x0 );
          printf("\n\nRoot %d = %f\n\n",rcount++,root);
          poly( eqn, degree, root );
          x0 = root;
          degree--;          
    } //end while
    root = -(eqn[0]/eqn[1]);
    printf("\n\nRoot %d = %f\n",rcount,root);
                  
    getch();
    return 0;
} //end main
float newton( int * eqn, float x0 )
{
      deriv_eqn = (int*) malloc(degree);
      deriv_eqn = derivative(eqn, degree);
      while(1)
      {
            fx = fn_value(eqn, degree, x0);
            f_x = fn_value (deriv_eqn, degree-1, x0);
            
            x1 = (x0-(fx/f_x));
            
            err_check = fabs((x1-x0)/x1);
            
            if( err_check <= error)
                break;
            else
                x0 = x1;
    } //end while
    return x1;
} //end newton function

void poly( int * arr, int n, float x0 ) //synthetic divisoin by root
{
     int *temptr;
     int i;
     temptr = (int*)malloc(n+1);
     for( i = 0; i <= n; i++ )
          temptr[i] = 0;
     
     for( i = n; i > 0; i-- )
         temptr[i-1] = (x0*temptr[i]) + arr[i];
         
     printf("\nCoefficients of reduced polynomials are:\n");
     for( i = n-1; i >=0; i-- )
         printf("x^%d = %d ",i,temptr[i]);
     for( i = n; i >=0; i-- )
         arr[i] = temptr[i];    
} //end poly

int* derivative( int * arr, int n)
{
     int i;
     int * deriv = (int*)malloc(n);
     
     for( i = n; i > 0; i--)
     {
          deriv[i-1] = arr[i]*i;
          
     }      
     return deriv;
} //end derivative

float fn_value( int * arr, int n, float x)
{
      float value = 0;
      int i;
      for( i = n; i>=0; i--)
           value += (arr[i]*pow(x,i));
           
      return value;
} //end fn_value
