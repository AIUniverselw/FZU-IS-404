#include <stdio.h>
int main()
{
    int a,b,c,t;    /*����4���������ͱ���a��b��c��t*/
    scanf("%d %d %d",&a,&b,&c);    /*��������3����*/
    if(a>b)    /*���a����b,�����м����tʵ��a��bֵ�Ļ���*/
    {
        t = a;
        a = b;
        b = t;
    }
    if(a>c)    /*���a����c,�����м�侰tʵ��a��cֵ�Ļ���*/
    {
        t = a;
        a = c;
        c = t;
    }
    if(b>c)    /*���b����c,�����м����tʵ��b��cֵ�Ļ���*/
    {
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d",a,b,c);    /*�������˳�����a��b��c��ֵ*/
    return 0;
}

