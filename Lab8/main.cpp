/*
В подзадаче 1 не более 2000 слов.

Вариант 4
1. 	Дан файл, содержащий английский текст. Найти в тексте N<=2000 самых длинных слов, 
в которых согласные буквы упорядочены по алфавиту. Записать найденные слова в текстовый файл в порядке невозрастания длины. 
Все найденные слова должны быть разными!
*/

#include "func.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("../../input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: file input.txt didn't open." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    const int maxWords = 2000;
    std::string words[maxWords];
    int wordCount = 0;

    splitString(text, words, wordCount);

    std::string orderedWords[maxWords];
    int orderedCount = 0;

    for (int i = 0; i < wordCount; ++i) {
        if (areConsonantsOrdered(words[i])) {
            orderedWords[orderedCount++] = words[i];
        }
    }

    orderedCount = removeDuplicates(orderedWords, orderedCount);

    sortWords(orderedWords, orderedCount);

    std::ofstream outputFile("../../output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: file output.txt didn't open." << std::endl;
        return 1;
    }

    for (int i = 0; i < orderedCount; ++i) {
        outputFile << orderedWords[i] << std::endl;
    }

    outputFile.close();
    std::cout << "Text is written in output.txt" << std::endl;

    return 0;
}
