/*
Вариант 4
Ввести последовательность натуральных чисел. Если последовательность упорядочена по неубыванию первой или последней цифры, 
удалить из последовательности числа, в которые не входят цифры 2,4 и 6, и продублировать числа, содержащие цифры 6 и 9. 
В противном случае упорядочить последовательность по неубыванию. Последовательность хранить в односвязном списке.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int data;
    Node* next;
};

// Функция для добавления узла в конец списка
void addNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для получения первой цифры числа
int getFirstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

// Функция для получения последней цифры числа
int getLastDigit(int number) {
    return number % 10;
}

// Функция для проверки, содержит ли число цифры 2, 4 или 6
bool contains246(int number) {
    while (number > 0) {
        int digit = number % 10;
        if (digit == 2 || digit == 4 || digit == 6) {
            return true;
        }
        number /= 10;
    }
    return false;
}

// Функция для проверки, содержит ли число цифры 6 или 9
bool contains69(int number) {
    while (number > 0) {
        int digit = number % 10;
        if (digit == 6 || digit == 9) {
            return true;
        }
        number /= 10;
    }
    return false;
}

// Функция для проверки упорядоченности списка по первой или последней цифре
bool isSorted(Node* head) {
    Node* current = head;
    bool sortedByFirst = true;
    bool sortedByLast = true;

    while (current != nullptr && current->next != nullptr) {
        if (getFirstDigit(current->data) > getFirstDigit(current->next->data)) {
            sortedByFirst = false;
        }
        if (getLastDigit(current->data) > getLastDigit(current->next->data)) {
            sortedByLast = false;
        }
        current = current->next;
    }

    return sortedByFirst || sortedByLast;
}

// Функция для удаления чисел, не содержащих цифры 2, 4 и 6
void removeNumbers(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (!contains246(current->data)) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Функция для дублирования чисел, содержащих цифры 6 и 9
void duplicateNumbers(Node*& head) {
    Node* current = head;

    while (current != nullptr) {
        if (contains69(current->data)) {
            Node* newNode = new Node{current->data, current->next};
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
    }
}

// Функция для сортировки списка по неубыванию
void sortList(Node*& head) {
    std::vector<int> values;
    Node* current = head;

    // Сбор значений в вектор
    while (current != nullptr) {
        values.push_back(current->data);
        current = current->next;
    }

    // Сортировка вектора
    std::sort(values.begin(), values.end());

    // Создание нового списка из отсортированного вектора
    Node* newHead = nullptr;
    for (int value : values) {
        addNode(newHead, value);
    }

    // Освобождение памяти старого списка
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Присваивание нового списка
    head = newHead;
}

// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    int n;
    std::cout << "Input number of values: ";
    std::cin >> n;

    std::cout << "Input values: ";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        addNode(head, value);
    }

    if (isSorted(head)) {
        removeNumbers(head);
        duplicateNumbers(head);
    } else {
        sortList(head);
    }

    std::cout << "Result: ";
    printList(head);

    // Освобождение памяти
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
