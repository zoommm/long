#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int arr[8];
int index_odd, index_even; //index_odd之前(不包括index_odd）为排好序的奇数，index_even（不包括index_even）之后为排好序的偶数，他们之间为乱序的数。
void insert_odd(int i)
{
	int k;
	int tmp;

	for(k = 0; k < index_odd; k++)
	{
		if(arr[i] < arr[k])
		{
			tmp = arr[i];
			memmove(&arr[k+1], &arr[k], (i-k)*4);
			arr[k] = tmp;
			index_odd++;
			break;
		}
	}

	//如果整个for循环遍历完，未找到符合条件的插入点，对于奇数来说，下标i对应的奇数保持当前位置不变，同时index_odd要自加1
	//，表示排好序的奇数多了一个
	if(k == index_odd)
		index_odd++;

	for(i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return;

}

void insert_even(int i)
{
	int j;
	int tmp;

	for(j = 7; j > index_even; j--)
	{
		if(arr[i] > arr[j])
		{
			tmp = arr[i];
			memmove(&arr[i], &arr[i+1], (j-i)*4);
			arr[j] = tmp;
			index_even--;
			break;
		}
	}

	//如果整个for循环遍历完，未找到符合条件的插入点，对于偶数来说，下标i对应的偶数应插入到index_even所对应的位置处，
	//然后index_even要自减1，表示排好序的偶数多了一个
	if(j == index_even)
	{
		tmp = arr[i];
		memmove(&arr[i], &arr[i+1], (j-i)*4);
		arr[j] = tmp;
		index_even--;
	}
	

	for(i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return;
}

int main()
{
	int i;

	//初始化随机数组
	srandom(time(NULL));
	for(i = 0; i < 8; i++)
	{
		arr[i] = random()%100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	

	//开始排序
	printf("now begin to sort:\n");
	index_odd = 0;
	index_even = 7;

	for( ; i = index_odd, index_odd <= index_even; )
	{
		if(arr[i]%2==0)
			insert_even(i);
		else
			insert_odd(i);
	}

	printf("after sort, arr[] is:\n");
	for(i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	printf("\n");
		
	return 0;
}

