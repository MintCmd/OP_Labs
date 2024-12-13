/*
Вариант 4.

3. 	В текстовом файле input.txt записан английский текст. Найти в тексте слова, содержащие две одинаковые буквы подряд, 
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, 
включая и знаки препинания.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.
*/

#include "func.hpp"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("../../input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "File error input.txt" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    const int maxWords = 1000;
    std::string words[maxWords];
    int wordCount = 0;

    splitString(text, words, wordCount);

    std::ofstream outputFile("../../output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "File error output.txt" << std::endl;
        return 1;
    }

    for (int i = 0; i < wordCount; ++i) {
        outputFile << processWord(words[i]);
        if (i < wordCount - 1 && isalpha(words[i + 1][0])) {
            outputFile << " ";
        }
    }

    outputFile.close();
    std::cout << "Text is saved in output.txt" << std::endl;

    return 0;
}
