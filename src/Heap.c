#include "sort.h"

void siftDown(int *numbers, int root, int bottom) { // Функция "просеивания" через кучу - формирование кучи
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    while ((root * 2 <= bottom) && (!done)) { // Пока не дошли до последнего ряда
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
        else if (numbers[root * 2] > numbers[root * 2 + 1]) // иначе запоминаем больший потомок из двух
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild]) {// если элемент вершины меньше максимального потомка
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else
        done = 1; // пирамида сформирована  
    }
}
 
void HeapSort(int *numbers, int array_size) { // Функция сортировки на куче
    for (int i = (array_size / 2) - 1; i >= 0; i--) // Формируем нижний ряд пирамиды
        siftDown(numbers, i, array_size);

    for (int i = array_size - 1; i >= 1; i--) { // Просеиваем через пирамиду остальные элементы
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

