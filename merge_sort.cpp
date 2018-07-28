#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* arr;
int* temp_arr;

void Merge(int start, int end)
{
	register int first_S = start, first_E=(start+end)/2,second_S=first_E+1,second_E=end, k=start;

	if(start>=end)
		return;

	Merge(first_S,first_E);
	Merge(second_S,second_E);

	while(first_S<=first_E && second_S<=second_E){
		if(arr[first_S] > arr[second_S])
			temp_arr[k++] = arr[second_S++];
		else
			temp_arr[k++] = arr[first_S++];
	}
	while(first_S<=first_E)
		temp_arr[k++] = arr[first_S++];
	while(second_S<=second_E)
		temp_arr[k++] = arr[second_S++];
	
	for(int cp=start;cp<=end;cp++)
		arr[cp] = temp_arr[cp];
}

void print_arr(int count, int arr[])
{
	printf("arr [ ");
	for(int i=0;i<count-1;i++)
		printf("%d, ",arr[i]);
	printf("%d ]\n", arr[count-1]);
}
 
int main(int argc,char* argv[])
{
	int num=0;
	
	if(argc != 2)
	{
		printf("Usage : murge_sort [number] \n");
		return 0;
	}	
	int count = atoi(argv[1]);
	arr =(int *) malloc(sizeof(int)*count);
	temp_arr = (int *) malloc(sizeof(int)*count);

	srand(time(NULL));

	for(int i=0;i<count;i++)
	{
		bool check = false;
		num = rand() % count + 1;
		for(int j=0;j<count;j++)
		{
			if(arr[j] == num)
			{
				check=true;
			}
		}
		if(check == true)
		{
			i--;
			continue;
		}
		else
			arr[i] = num;
		check = false;
		
	}	
	print_arr(count,arr);
	Merge(0,count-1);
	print_arr(count,arr);
	return 0;
}

