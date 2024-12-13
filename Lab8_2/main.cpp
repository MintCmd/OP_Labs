/*
Вариант 4

2. 	Дана строка, содержащая английский текст. Вывести в алфавитном порядке слова текста, содержащие не более 3-х согласных, 
в остальных словах удалить гласные и продублировать согласные буквы.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.
*/

// Пример ввода и вывода:
//Ввод: Gottfried Leibniz is a German philosopher, engineer, and mathematician.
//Вывод: GGttttffrrdd LLbbnnzz GGrrmmnn pphhllsspphhrr nnggnnrr mmtthhmmttccnn a and is

#include "func.hpp"
#include <iostream>


int main() {
    std::string text;
    std::cout << "Input text: ";
    std::getline(std::cin, text);

    const int maxWords = 1000;
    std::string words[maxWords];
    int wordCount = 0;

    splitString(text, words, wordCount);

    std::string resultWords[maxWords];
    int resultCount = 0;

    std::cout << "Output text: ";

    for (int i = 0; i < wordCount; ++i) {
        int consonantCount = countConsonants(words[i]);
        if (consonantCount <= 3) {
            resultWords[resultCount++] = words[i];
        } else {
            std::cout << processWord(words[i]) << " ";
        }
    }

    sortWords(resultWords, resultCount);

    for (int i = 0; i < resultCount; ++i) {
        std::cout << resultWords[i] << " ";
    }

    return 0;
}