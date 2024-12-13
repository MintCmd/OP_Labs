/*
В подзадаче 1 не более 2000 слов.

Вариант 4
1. 	Дан файл, содержащий английский текст. Найти в тексте N<=2000 самых длинных слов, 
в которых согласные буквы упорядочены по алфавиту. Записать найденные слова в текстовый файл в порядке невозрастания длины. 
Все найденные слова должны быть разными!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

// Функция для проверки, является ли буква гласной
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Функция для проверки, упорядочены ли согласные буквы в слове по алфавиту
bool areConsonantsOrdered(const std::string& word) {
    std::string consonants;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            consonants += c;
        }
    }
    return std::is_sorted(consonants.begin(), consonants.end());
}

// Функция для разделения строки на слова
void splitString(const std::string& str, std::string words[], int& wordCount) {
    std::string word = "";
    wordCount = 0;
    for (char c : str) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                words[wordCount++] = word;
                word = "";
            }
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }
}

// Функция для сортировки массива строк по невозрастанию длины
void sortWordsByLength(std::string words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = 0; j < wordCount - i - 1; ++j) {
            if (words[j].length() < words[j + 1].length()) {
                std::swap(words[j], words[j + 1]);
            }
        }
    }
}

// Функция для удаления дубликатов из массива строк
int removeDuplicates(std::string words[], int wordCount) {
    int uniqueCount = 0;
    for (int i = 0; i < wordCount; ++i) {
        bool isUnique = true;
        for (int j = 0; j < uniqueCount; ++j) {
            if (words[i] == words[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            words[uniqueCount++] = words[i];
        }
    }
    return uniqueCount;
}

int main() {
    std::ifstream inputFile("../../input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: file input.txt didn't open." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    const int maxWords = 2000; // Максимальное количество слов
    std::string words[maxWords];
    int wordCount = 0;

    // Разделяем текст на слова
    splitString(text, words, wordCount);

    std::string orderedWords[maxWords];
    int orderedCount = 0;

    // Проверяем каждое слово на упорядоченность согласных букв
    for (int i = 0; i < wordCount; ++i) {
        if (areConsonantsOrdered(words[i])) {
            orderedWords[orderedCount++] = words[i];
        }
    }

    // Удаляем дубликаты
    orderedCount = removeDuplicates(orderedWords, orderedCount);

    // Сортируем слова по невозрастанию длины
    sortWordsByLength(orderedWords, orderedCount);

    std::ofstream outputFile("../../output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: file output.txt didn't open." << std::endl;
        return 1;
    }

    // Записываем результат в файл
    for (int i = 0; i < orderedCount; ++i) {
        outputFile << orderedWords[i] << std::endl;
    }

    outputFile.close();
    std::cout << "Text is written in output.txt" << std::endl;

    return 0;
}
