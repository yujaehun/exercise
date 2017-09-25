void mergeSort(int *data, int first, int last){
	int middle = 0;

	if(first < last){
		
		middle = (int)(first+last)/2;

		mergeSort(data, first, middle);
		mergeSort(data, middle+1, last);
		merge(data, first, middle, last);
	}
}

void merge(int *data, int first, int middle, int last){

	int lfst = first;
	int lfend = middle;
	int rtst = middle + 1;
	int rtend = last;
	int i = 0;

	int *sorted_data = (int *)malloc(sizeof(int)*(last+1));
	int sorted_data_index = first;

	while(lfst <= lfend && rtst <= rtend)
	{
		if(data[lfst] > data[rtst])
		{
			sorted_data[sorted_data_index] = data[rtst++];
		}
		else
		{
			sorted_data[sorted_data_index] = data[lfst++];
		}
		sorted_data_index++;
	}

	if(lfst > lfend)
	{
		for(i = rtst; i <= rtend; i++)
		{
			sorted_data[sorted_data_index++] = data[index];
		}
	}

	else
	{
		for(i = lfst; i <= lfend; i++)
		{
			sorted_data[sorted_data_index++] = data[index];
		}
	}

	for(i = first; i <= last; i++)
	{
		data[index] = sorted_data[index];
	}

	free(sorted_data);
}
