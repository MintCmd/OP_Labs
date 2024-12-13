/*
Вариант 4.

3. 	В текстовом файле input.txt записан английский текст. Найти в тексте слова, содержащие две одинаковые буквы подряд, 
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, 
включая и знаки препинания.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// Функция для проверки, содержит ли слово две одинаковые буквы подряд
bool hasDoubleLetters(const std::string& word, char& doubleLetter) {
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (word[i] == word[i + 1]) {
            doubleLetter = word[i];
            return true;
        }
    }
    return false;
}

// Функция для обработки слова
std::string processWord(const std::string& word) {
    char doubleLetter;
    if (hasDoubleLetters(word, doubleLetter)) {
        std::string upperWord = word;
        for (char& c : upperWord) {
            c = toupper(c);
        }
        return upperWord + "(" + doubleLetter + doubleLetter + ")";
    }
    return word;
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
            if (!isspace(c)) {
                words[wordCount++] = std::string(1, c);
            }
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }
}

int main() {
    std::ifstream inputFile("../../input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "File error input.txt" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    const int maxWords = 1000; // Максимальное количество слов
    std::string words[maxWords];
    int wordCount = 0;

    // Разделение текста на слова
    splitString(text, words, wordCount);

    std::ofstream outputFile("../../output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "File error output.txt" << std::endl;
        return 1;
    }

    // Обработка каждого слова и запись результата в файл
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
