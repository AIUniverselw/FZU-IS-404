#include<stdio.h>  
int main()
{
	int  shu,i,factor,j=0;
	scanf("%d",&shu);
	for(i=0;i<shu;i++)//���������ж��Ƿ��ܸ�7���� 
	{
		scanf("%d",&factor);
		if(factor%7==0)
		j++;//��¼��7�����ĸ��� 
	}
	printf("%d",j);
	return 0;
 }

