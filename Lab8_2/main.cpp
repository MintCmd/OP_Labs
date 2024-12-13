/*
Вариант 4

2. 	Дана строка, содержащая английский текст. Вывести в алфавитном порядке слова текста, содержащие не более 3-х согласных, 
в остальных словах удалить гласные и продублировать согласные буквы.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

// Функция для проверки, является ли буква гласной
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Функция для подсчета количества согласных в слове
int countConsonants(const std::string& word) {
    int count = 0;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            count++;
        }
    }
    return count;
}

// Функция для удаления гласных и продублирования согласных
std::string processWord(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            result += c;
            result += c;
        }
    }
    return result;
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

// Функция для сортировки массива строк
void sortWords(std::string words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = 0; j < wordCount - i - 1; ++j) {
            if (words[j] > words[j + 1]) {
                std::swap(words[j], words[j + 1]);
            }
        }
    }
}

int main() {
    std::string text;
    std::cout << "Input text: ";
    std::getline(std::cin, text);

    const int maxWords = 1000; // Максимальное количество слов
    std::string words[maxWords];
    int wordCount = 0;

    // Разделяем текст на слова
    splitString(text, words, wordCount);

    std::string resultWords[maxWords];
    int resultCount = 0;

    // Обработка каждого слова
    for (int i = 0; i < wordCount; ++i) {
        int consonantCount = countConsonants(words[i]);
        if (consonantCount <= 3) {
            resultWords[resultCount++] = words[i];
        } else {
            std::cout << processWord(words[i]) << " ";
        }
    }

    // Сортировка слов, содержащих не более 3-х согласных
    sortWords(resultWords, resultCount);

    // Вывод отсортированных слов
    for (int i = 0; i < resultCount; ++i) {
        std::cout << resultWords[i] << " ";
    }

    return 0;
}