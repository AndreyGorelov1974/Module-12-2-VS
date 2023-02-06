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

void heapify(int arr[], int n, int i)
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

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

int main()
{

    float arr[20];

    // задание начальных констант
    // размер массива
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    // высота кучи
    int heapHeight = log(sizeArr) / log(2) + 1;

    // генерация случайного массива

    std::srand(std::time(NULL));
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = (std::rand() / RAND_MAX) * 100;
    }

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;


    // вывод кучи
    std::cout << arr[0] << std::endl;
    for (int i = 1; i < heapHeight; i++)
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
}