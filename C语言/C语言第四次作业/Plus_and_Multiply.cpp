#include<stdio.h>  
int main()
{
  int hang,i,j;
  char a;
  scanf("%d %c",&hang,&a);
  if(a=='+')
  {
  		for(i=1;i<=hang;i++)//���ӷ��� 
	 {
	   for(j=1;j<=i;j++)
  		printf("%d + %d = %d  ",j,i,j+i);
	    printf("\n");
	}
  }
 else if(a=='*')
 {
 		for(i=1;i<=hang;i++)//���˷��� 
	 {
	   for(j=1;j<=i;j++)
  		printf("%d * %d = %d  ",j,i,j*i);
	    printf("\n");
	}
 }
  else
  printf("GG");
  
	return 0;
 }
