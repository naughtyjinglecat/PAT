#include <stdio.h>

int main()
{
   char str[50];

   printf("请输入一个字符串：");
   gets(str);

   printf("您输入的字符串是：%s", str);

   return(0);
}