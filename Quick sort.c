//.....Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
struct array
{
	int *arr; int num;
};
int Quick_sort(struct array *elements,int,int);
int Partition(struct array *elements,int,int);
int swap(struct array *elements,int,int);
int main()
{
	int i;
	struct array elements;
	printf("\n\t\t\t\t\t - : QUICK : -");
	printf("\n\n Enter the no of elements : ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements in the array : ");
	for(i=0;i<elements.num;i++)
		scanf("%d",elements.arr+i);
	Quick_sort(&elements,0,elements.num-1);
	printf("\n\n After sorting the elements are :\t");
	for(i=0;i<elements.num;i++)
		printf("%d\t",*(elements.arr+i));
	free(elements.arr);
return 0;
}

int Quick_sort(struct array *elements,int lb, int ub)
{
	int loc,i;
	if(lb < ub)
	{
		loc = Partition(elements, lb, ub);
		Quick_sort(elements, lb, loc-1);
		Quick_sort(elements, loc+1, ub);
	}
return 0;
}

int Partition(struct array *elements,int lb, int ub)
{
	int pivot,left,right;
	pivot = elements->arr[lb];
	left = lb;
	right = ub;
	while(left < right)
	{
		while(elements->arr[left] <= pivot && left < ub)
		{
			left++;
		}
		while(elements->arr[right]>pivot)
		{
			right--;
		}
		if(left<right)
			if(elements->arr[left] != elements->arr[right])
				swap(elements,left,right);
	}
	if(elements->arr[lb] != elements->arr[right])
		swap(elements,lb,right);
return right;
}

int swap(struct array *elements,int x,int y)
{
	elements->arr[x] = elements->arr[x] + elements->arr[y];
	elements->arr[y] = elements->arr[x] - elements->arr[y];
	elements->arr[x] = elements->arr[x] - elements->arr[y];
return 0;
}
