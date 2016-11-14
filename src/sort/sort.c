/*
 * sort.c
 *
 *  Created on: 2016年11月7日
 *      Author: Dabao
 */
#include <stdio.h>
#include "sort.h"

//桶排序
void bucketsort() {
	int a[1001],i,j,t,n;
	for (i = 0; i <= 1000; i++) {
		a[i] = 0; // 初始化“桶”
	}
	scanf("%d",&n); //接收一个输入，表示接下来要排序几个数，存放在n中
	for (i = 1; i <= n; i++) {
		scanf("%d",&t); //接收需要排序的数字
		a[t]++; //对应的桶里个数+1
	}
	for(i=1000;i>=0;i--){  //依次判断编号1000~0的桶
		 for(j=1;j<=a[i];j++){  //出现了几次就将桶的编号打印几次
			 printf("%d ",i);
		 }
	}
}

//冒泡排序
void bubblesort(){
	int a[100],i,j,t,n;
	scanf("%d",&n); //接收排序数组长度
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);// 将待排序数字存入数组当中
	}
	for (i = 0; i < n-1; i++) { //排序n个数字，只需冒泡n-1次
		for (j = 0; j < n-i-1; j++) { //除第一次冒泡时，数组中存在已经排序完成的部分，所以冒泡时不需要向已经排序好的部分进行
			if(a[j] < a[j+1]){ //判断是否满足条件，是否交换值
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
}

//快速排序
int arr_quicksort[101];//定义全局变量，这两个变量需要在子函数中使用
void quicksort(){

	int i,n;
	//读入数据
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&arr_quicksort[i]);
	}
	quicksortimple(1,n); //快速排序调用
	//输出排序后的结果
	for(i=1;i<=n;i++) {
		printf("%d ",arr_quicksort[i]);
	}
}

void quicksortimple(int left,int right){
	int i,j,t,temp;
	if(left>right){
		return;
	}
	temp=arr_quicksort[left]; //temp中存的就是基准数
	i=left;
	j=right;
	while(i!=j)
	{
		//顺序很重要，要先从右往左找
		while(arr_quicksort[j]>=temp && i<j){
			j--;//再从左往右找
		}
		while(arr_quicksort[i]<=temp && i<j){
			i++;
		}
		//交换两个数在数组中的位置
		if(i<j)
		{
			t=arr_quicksort[i];
			arr_quicksort[i]=arr_quicksort[j];
			arr_quicksort[j]=t;
		}
	}
	//终将基准数归位
	arr_quicksort[left]=arr_quicksort[i];
	arr_quicksort[i]=temp;
	quicksortimple(left,i-1);//继续处理左边的，这里是一个递归的过程
	quicksortimple(i+1,right);//继续处理右边的，这里是一个递归的过程
}
