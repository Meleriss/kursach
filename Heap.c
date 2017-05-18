#include "sort.h"

void BuildHeap(uint32_t *array, uint32_t size, uint32_t RootIndex)
{
	uint32_t ramification, value;
	value = array[RootIndex];

	while(RootIndex <= size/2)
	{
		ramification = 2 * RootIndex;
		if(ramification < size && array[ramification] < array[ramification + 1])
			ramification++;
		if(value >= array[ramification])
			break;
		array[RootIndex] = array[ramification];
		RootIndex = ramification;
	}
	array[RootIndex] = value;
}

void HeapSort(uint32_t *array, uint32_t size)
{
	int i;
	uint32_t buff;
	for(i = size/2; i >= 0; i--)
		BuildHeap(array, size, i);
	while(size > 0)
	{
		buff = array[0];
		array[0] = array[size];
		array[size] = buff;
		BuildHeap(array, --size, 0);
	}
}
