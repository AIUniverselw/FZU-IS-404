#include<stdio.h>
#include<math.h>
int main()
{
	int N,M,i=1;
	int ii=1;
	int a;
	int c=0; 
	scanf("%d %d",&N,&M);
	int b=N;
	while(N>=M)//���㻻���λ�� 
	{
		N=N/M;
		i=i+1;
	}
	while(ii<=i)//�������� 
	{
		int d;
		a=b%M;
		b=b/M;
		d=pow(10,(ii-1));
		c=c+a*d;
		ii=ii+1;
	}
	printf("%d",c);
	return 0;
}
