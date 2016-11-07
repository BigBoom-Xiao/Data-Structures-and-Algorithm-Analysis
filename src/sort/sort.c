/*
 * sort.c
 *
 *  Created on: 2016年11月7日
 *      Author: Dabao
 */
#include "sort.h"
//桶排序
void bucketsort() {
	int book[1001],i,j,t,n;
	for (i = 0; i <= 1000; i++) {
		book[i] = 0; // 初始化“桶”
	}
	scanf("%d",&n); //接收一个输入，表示接下来要排序几个数，存放在n中
	for (i = 1; i <= n; i++) {
		scanf("%d",&t); //接收需要排序的数字
		book[t]++; //对应的桶里个数+1
	}
	for(i=1000;i>=0;i--){  //依次判断编号1000~0的桶
		 for(j=1;j<=book[i];j++){  //出现了几次就将桶的编号打印几次
			 printf("%d ",i);
		 }
	}
}
