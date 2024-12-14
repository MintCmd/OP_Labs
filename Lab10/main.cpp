/*
Вариант 4
Ввести последовательность натуральных чисел. Если последовательность упорядочена по неубыванию первой или последней цифры, 
удалить из последовательности числа, в которые не входят цифры 2,4 и 6, и продублировать числа, содержащие цифры 6 и 9. 
В противном случае упорядочить последовательность по неубыванию. Последовательность хранить в односвязном списке.
*/

// Пример ввода и вывода:
//Ввод: 12 23 34 45 56 67 78 89 90 0
//Вывод: 12 23 34 45 56 56 67 67 

#include "func.hpp"
#include <iostream>

int main() {
    Node* head = nullptr;
    int number;

    std::cout << "Input numbers (end with 0 to stop):" << std::endl;
    while (true) {
        std::cin >> number;
        if (number == 0) {
            break;
        }
        addNode(head, number);
    }

    // Проверка упорядоченности и обработка списка
    if (isSorted(head)) {
        removeNumbers(head);
        duplicateNumbers(head);
    } else {
        sortList(head);
    }

    std::cout << "Result:" << std::endl;
    printList(head);

    // Освобождение памяти
    freeList(head);

    return 0;
}
