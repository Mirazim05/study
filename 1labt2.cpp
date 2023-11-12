#include <iostream>

/*
1) int ptr = (int)malloc(sizeof(int)) -в C++ можно использовать новый оператор для выделения памяти;

2) int ptrArr = (int)malloc(sizeof(int)*N) - в C++ также можно использовать новый оператор для выделения массива памяти;

3) free(ptr) - в C++ для освобождения памяти необходимо использовать оператор удаления;

4) free(ptrArr) - в C++ оператор delete[] используется для освобождения памяти выделенного массива;

В C++ необходимо освобождать динамическую память с помощью операторов delete и delete[], в зависимости от
от того, был ли выделен один объект или массив. Двойное освобождение памяти может привести к
неопределенное поведение программы. Вы не можете освободить нераспределенную память.
*/

int main() {
    int numRows;
    std::cout << "Enter the number of rows of the Fibonacci triangle: ";
    std::cin >> numRows;

    // Выделение памяти для треугольника Фибоначчи
    int** triangle = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        triangle[i] = new int[i + 1];
    }

    // Заполнение треугольника Фибоначчи
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0 || j == i) {
                // Значения на границах треугольника всегда равны 1
                *(*(triangle + i) + j) = 1;
            }
            else {
                // Значение внутри треугольника представляет собой сумму двух предыдущих значений
                *(*(triangle + i) + j) = *(*(triangle + i - 1) + j - 1) + *(*(triangle + i - 1) + j);
            }
        }
    }

    // Вывод треугольника Фибоначчи
    std::cout << "THe Fibonacci Triangle:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << *(*(triangle + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < numRows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}