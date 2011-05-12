#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int arr[8];
int index_odd; //index_odd之前(包括index_odd）为奇数，它之后为偶数，但一开始都未排序。

int main()
{
	int i, tmp;
	int k;
	int flag;//冒泡排序优化用

	//初始化随机数组
	srandom(time(NULL));
	for(i = 0; i < 8; i++)
	{
		arr[i] = random()%100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	//先交换奇偶数位置，保证前面都是奇数，后面都是偶数，但未排序。
	for(i = 0, index_odd = -1; i < 8; i++)
	{
		if(arr[i]%2 != 0) //从左到右找到奇数
		{
			//把找到的奇数放到index_odd之后的位置上，即(index_odd+1)
			//如果i == (index_odd+1)， 则不必交换
			if(i != index_odd+1)
			{
				tmp = arr[i];
				arr[i] = arr[index_odd+1];
				arr[index_odd+1] = tmp;
			}
			index_odd++; //index_odd指向下一个位置，准备放新的奇数
		}
	}

	//显示奇偶交换后的数组，还未排序
	printf("after swapping, arr[] is:\n");
	for(k = 0; k < 8; k++)
		printf("%d ", arr[k]);
	printf("\n");

	printf("index_odd=%d\n", index_odd);

	//开始冒泡排序,先排奇数部分，再排偶数部分
	for(i = 0; i < index_odd; i++)
	{
		flag = 1;
		for(k = 0; k < index_odd-i; k++)
		{
			if(arr[k] > arr[k+1])
			{
				tmp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = tmp;
				flag = 0;
			}
		}
		if(flag)
			break;
	}

	for(i = 0; i < 7-index_odd-1; i++)
	{
		flag = 1;
		for(k = index_odd+1; k < 7-i; k++)
		{
			if(arr[k] > arr[k+1])
			{
				tmp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = tmp;
				flag = 0;
			}
		}
		if(flag)
			break;
	}

	//显示最后的结果
	printf("after sort, arr[] is:\n");
	for(k = 0; k < 8; k++)
		printf("%d ", arr[k]);
	printf("\n");

	return 0;
}

