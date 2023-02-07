/*Задание 2. Сортировка
Что нужно сделать
Пользователь вводит в консоль 15 дробных чисел.
Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему.
По возможности используйте минимум дополнительной памяти и проходов по массиву.

Пример
Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251
Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11

Рекомендации по выполнению
Воспользуйтесь дополнительными материалами.*/

#include <iostream>
#include <math.h>
#include <ctime>

int counterHeap = 0;
int counterBubble = 0;

// функция вывода в виде кучи
void printHeap(float arr[], int height, int sizeArr)
{
    std::cout << arr[0] << std::endl;
    for (int i = 1; i < height; i++)
    {
        for (int j = pow(2, i) - 1; j <= pow(2, i + 1) - 2; j++)
        {
            if (j < sizeArr)
            {
                std::cout << arr[j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// функция вывода массива размером sizeArr
void printArray(float arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи
void heapify(float arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        counterHeap++;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(float arr[], int n)
{
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        counterHeap++;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Основная функция, выполняющая  сортировку пузырьком
void bubbleSort(float arr[], int n)
{
    // Двойной проход по массиву
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                counterBubble++;
            }
        }
    }
}

// Основная функция, выполняющая  сортировку слиянием
void mergeSort(float arr[], int n)
{
    int step = 2;
    int half = n;

    n--;

    for (int i = 0; i < n - 2; i += 2 )
    {
        if (arr[i] > arr[i + 1])
        {
            std::swap(arr[i], arr[i + 1]);
        }
    }
    printArray(arr, 9);

    for (int i = 0; i < n - 4; i += 4)
    {
        for (int j = i; j < 2; j++)
        {
            if (arr[j] > arr[j + 2])
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
    printArray(arr, 9);

}


int main()
{

    float arr[30];

    // задание начальных констант
    // размер массива
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    // высота кучи
    int heapHeight = log(sizeArr) / log(2) + 1;

    // генерация случайного массива

    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = (float(std::rand()) / RAND_MAX) * 100;
        // arr[i] = float(sizeArr - i);
    }

    printHeap(arr, heapHeight, sizeArr);

    printArray(arr, sizeArr);

    // Построение кучи (перегруппируем массив)
    for (int i = sizeArr / 2 - 1; i >= 0; i--)
    {
        heapify(arr, sizeArr, i);
    }

    printHeap(arr, heapHeight, sizeArr);

    std::cout << "Operation for conversion to heap: " << counterHeap << std::endl;

    heapSort(arr, sizeArr);

    printArray(arr, sizeArr);

    std::cout << "Operation for sort heap: " << counterHeap << std::endl;

    // генерация случайного массива

    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = (float(std::rand()) / RAND_MAX) * 100;
    }

    printArray(arr, sizeArr);

    bubbleSort(arr, sizeArr);

    printArray(arr, sizeArr);

    std::cout << "Operation for sort buble: " << counterBubble << std::endl;

    float arrM[] = {2, 5, 8, 3, 9, 1, 4, 7, 6};
    mergeSort(arrM, 9);


}