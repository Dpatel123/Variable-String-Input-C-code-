/*
Author: Dharmesh Patel, 18.06.2021
Description: Variable sting input and separate character a,b,c from the sting
Version: V0.0
*/

#include<stdio.h>
#include<string.h>

char * inputstring()
{
    char ch,*q,*p;
    int len=1,i;

    p=(char *)malloc(len);
    ch=getche();
    *p=ch;
    do
    {
        q=(char *)malloc(len+1);
        for(i=0;i<len;i++)
            *(q+i)=*(p+i);
        *(q+i)='\0';
        free(p);
        len++;
        p=(char *)malloc(len);
        for(i=0;i<len;i++)
           *(p+i)=*(q+i);
        free(q);
        ch=getche();
        *(p+len-1)=ch;
    }while(ch!=13);
    q=(char *)malloc(len);
    for(i=0;i<len;i++)
        *(q+i)=*(p+i);
    *(q+i-1)='\0';

    return q;
}

void splitstr(char *STR)
{
    int i=0,la=0,lb=0,lc=0;
    char *a,*b,*c;

    while(*(STR+i)!= NULL)
      {
        if(*(STR+i)=='a')
        {
            ++la;
        }
        else if(*(STR+i)=='b')
        {
            ++lb;
        }
        else if(*(STR+i)=='c')
        {
            ++lc;
        }

        i++;
      }

      a=(char *)malloc(la+1);
      for(i=0;i<la;i++)
        *(a+i)='a';
      *(a+la)='\0';

      b=(char *)malloc(lb+1);
      for(i=0;i<lb;i++)
        *(b+i)='b';
      *(b+lb)='\0';

      c=(char *)malloc(lc+1);
      for(i=0;i<lc;i++)
        *(c+i)='c';
      *(c+lc)='\0';

    printf("separated strings are \n%s\n%s\n%s\n",a,b,c);

}

int main()
{
    char *str;
    str = inputstring();
    printf("you have entered: %s\n",str);
    splitstr(str);
    return 0;
}

