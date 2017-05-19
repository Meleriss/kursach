#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sort.h"

//void SelectionSort(int *a, int n);
//void HeapSort(uint32_t *array, uint32_t size);

// Отсчет времени
double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

// Рандомайзер
int getrand(int min, int max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

// Вывод массива
int viewMass(int *p, int n) {
    printf("\nP = (");
    for(int i=1; i<n; i++)
        printf("%d,", p[i-1]);
        printf("%d)\n", p[n-1]);
    return 1;
}

int main() {
    int n, *p; //Размер массива и указатель на него
    printf("Введите размерность массива: ");
    scanf("%d", &n);
    p = (int*)malloc(n * sizeof(int));
    int sort;
    printf("Выберите ввод ([1]- Ручной, [2]- Рандом):\n");
    scanf("%d", &sort);
    switch(sort) {
    case 1:
        printf("Введите элементы массива: \n"); 
        for(int i=1; i<n+1; i++) {
            printf("p[%d]= ", i);
            scanf("%d", &p[i-1]);
        }
        break;
    case 2:
        for(int i=0; i<n; i++) {
            p[i] = getrand(1, 1000)*getrand(1, 1000);
        }
        printf("\nСоздан случайный массив из %d элементов\n", n);
        break;
    default:
        printf("Неверный ввод данных!\n");
        break;
    }

    printf("Каким методом отсортировать массив ([1] - Вставками, [2] - Пирамидкой): \n");
    scanf("%d", &sort);
    double t;
    switch(sort) {
    case 1:
        t = wtime();	// Начало отсчета   
        SelectionSort(p,n);
        t = wtime() - t;	// Конец отсчета
        printf("\nВремя выполнения: %.6f секунд\n\n", t);
        printf("Сортировка вставками:");
        viewMass(p,n);
        break;

    case 2:
        t = wtime();	// Начало отсчета
        HeapSort(p,n);
        t = wtime() - t;	// Конец отсчета
        printf("\nВремя выполнения: %.6f секунд\n\n", t);
        printf("Сортировка пирамидкой:");
        viewMass(p,n);
        break;
 	
    default:
        printf("Неверный ввод данных!\n");
        break;
    }
    free(p);
    return 0;
}
