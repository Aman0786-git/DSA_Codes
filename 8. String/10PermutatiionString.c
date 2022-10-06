#include<stdio.h>
#include<string.h>

//Method - 1

/* void permu(char s[],int k)
{
    static int A[10]={0};
    static char res[10];
    int i;
    if(s[k]=='\0')
    {
        res[k]='\0';
        printf("%s\n",res);
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                permu(s,k+1);
                A[i]=0;
            }
        }
    }
} */


//Method -2 

void swap(char *x,char *y)
{
    char temp;
    temp = *x;
    *x=*y;
    *y= temp;
}
void permu(char s[],int l,int h)
{
    int i;
    if(l==h)printf("%s\n",s);
    else
    {
        for(i=0;i<h;i++)
        {
            
        }
    }
}

int main()
{
    char s[]="ABC";;
    int n = strlen(s); 
    permu(s,0,n-1);

    return 0 ;
}