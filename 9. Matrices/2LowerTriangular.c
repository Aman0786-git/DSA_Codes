#include<stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};  
void setEl(struct Matrix *m,int i, int j,int x)
{
    if(i>=j) m->A[i*(i-1)/2 + j-1]= x; //ROW MAJOR
    /*
             COLUMN MAJOR
            if(i>=j) m->A[(m->n*(j-1) - ((j-1)*(j-2))/2) + (i-j) )]=x; 

    */
}

int getEl(struct Matrix m,int i,int j)
{
    if(i>=j)return m.A[i*(i-1)/2 + j-1]; //ROW MAJOR

     /*
                COLUMN MAJOR
            if(i>=j)return m.A[ (m.n*(j-1) - ((j-1)*(j-2))/2) + (i-j) )]; 

    */
    else
        return 0;
}

void display(struct Matrix m)
{   
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            if(i>=j)printf("%d ",m.A[ i*(i-1)/2 + j-1 ]); //ROW MAJOR 
          
          /*
                COLUMN MAJOR
            if(i>=j)printf("%d ",m.A[ (n*(j-1) - ((j-1)*(j-2))/2) + (i-j)) ]; 

        */

            else
                printf("0 ");
        }      
        printf("\n");
    }
   
}
int main()
{  
    struct Matrix m;
    int i,j,x;
    printf("Enter Dimension:");
    scanf("%d",&m.n);

    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int)); 

    printf("Enter All Elements: ");

    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            setEl(&m,i,j,x);
        }
    }
    printf("\n\n");
    display(m);
    return 0;
    
}