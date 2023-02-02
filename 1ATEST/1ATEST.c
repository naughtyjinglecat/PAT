#include <stdio.h>
#include<stdlib.h>

int main()
{
   unsigned long long maxSize = 0;
   unsigned int a = sizeof(char)*1024*1024;
   while (malloc(a)){
      maxSize++;
      if(maxSize >= 1000000){
         break;
      }
   }
   printf("每次申请了%lu字节空间\n", sizeof(char)*1024*1024);
   printf("总共申请了%lldMB内存空间。\n", maxSize);
   return(0);
}