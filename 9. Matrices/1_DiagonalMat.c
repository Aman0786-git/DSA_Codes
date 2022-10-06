#include<stdio.h>

struct Matrix
{
    int A[10];
    int n;
};  
void setEl(struct Matrix *m,int i, int j,int x)
{
    if(i==j) m->A[i-1]=x;
}

int getEl(struct Matrix m,int i,int j)
{
    if(i==j)return m.A[i-1];
    else
        return 0;
}

void display(struct Matrix m)
{
    int i,j;
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            if(i==j)printf("%d ",m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{  
    struct Matrix m;

    setEl(&m,1,1,5);
    setEl(&m,2,2,3);
    setEl(&m,3,3,2);
    setEl(&m,4,4,1);

    printf("%d \n",getEl(m,2,2));
    display(m); 



    return 0;
}