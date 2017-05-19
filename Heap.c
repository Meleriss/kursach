#include "sort.h"

/*
void BuildHeap(int *array, int size, int RootIndex)
{
	int ramification, value;
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


void HeapSort(int *array, int size)
{
	int i;
	int buff;
	for(i = (size/2) - 1; i >= 0; i--)
		BuildHeap(array, size, i);
	while(size > 0)
	{
		buff = array[0];
		array[0] = array[size];
		array[size] = buff;
		BuildHeap(array, --size, 0);
	}
}
*/


// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void HeapSort(int *numbers, int array_size) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}

