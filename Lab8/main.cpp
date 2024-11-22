/*
В подзадаче 1 не более 2000 слов.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.


Вариант 4
1. 	Дан файл, содержащий английский текст. Найти в тексте N<=2000 самых длинных слов, 
в которых согласные буквы упорядочены по алфавиту. Записать найденные слова в текстовый файл в порядке невозрастания длины. 
Все найденные слова должны быть разными!

2. 	Дана строка, содержащая английский текст. Вывести в алфавитном порядке слова текста, содержащие не более 3-х согласных, 
в остальных словах удалить гласные и продублировать согласные буквы.
 
3. 	В текстовом файле input.txt записан английский текст. Найти в тексте слова, содержащие две одинаковые буквы подряд, 
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, 
включая и знаки препинания.
*/

#include <iostream>
#include <string>
#include <fstream>

const int N_Max = 2000;

bool Read(int& n, int& cnt, std::string words[N_Max]) {
    std::ifstream in("input1.txt");
        if (!in.is_open()) {
            std::cerr << "File error." << std::endl;
            return false;
        }
        in >> n;
        cnt = 0;
        while(!in.eof()) {
            in >> words[cnt];
            cnt++;
        }
    return true;
}

std::string toLowerCase(std::string& s) {
    for(int i=0;i<s.length();i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    return s;
}

bool isLetter(char c) {
    if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
        return true;
    }
    else {
        return false;
    }
}

void FormatWords(int cnt, std::string words[N_Max]) {
    for(int i=0;i<cnt;i++) {
        toLowerCase(words[i]);
        for(int j=0;j<words[i].length();j++) {
            if(!isLetter(words[i][j])) {
                words[i].erase(j, 1);
                j--;
            }
        }
    }
}

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void RemoveVowels(int cnt, std::string cons[N_Max]) {
    for(int i=0;i<cnt;i++) {
        for(int j=0;j<cons[i].length();j++) {
            if(isVowel(cons[i][j])) {
                cons[i].erase(j, 1);
                j--;
            }
        }
    }
}

void Checker(int& cnt, std::string words[N_Max], std::string cons[N_Max]) {
    for(int i=0;i<cnt;i++) {
        for(int j=0;j<cons[i].length()-1;j++) {
            if(cons[i][j]>cons[i][j+1]) {
                cons[i].clear();
                words[i].clear();
                cnt--;
                break;
            }
        }
    }
}

void DeleteEmptyString(int& cnt, std::string words[N_Max], std::string notempty[N_Max]) {
    int index = 0;
    for(int i=0; i<cnt; i++) {
        if(!words[i].empty()) {
            notempty[index++] = words[i];
        }
    }
    cnt=index;
}

void SortByLength(int cnt, std::string words[N_Max]) {
    for(int i=0;i<cnt-1;i++) {
        if((words[i].length() < words[i+1].length()) || (words[i].length() == words[i+1].length() && words[i] > words[i+1])) {
            std::swap(words[i], words[i+1]);
        }
    }
}

void DebugWrite(int cnt, std::string words[N_Max], std::string cons[N_Max]) {
    for(int i=0;i<cnt;i++) {
        std::cout << "<" << words[i] << ">" << " " << "<" << cons[i] << ">" << std::endl;
    }
}


void Write(int cnt, std::string words[N_Max], std::string notempty[N_Max]) {
    for(int i=0;i<cnt;i++) {
        std::cout << "<" << words[i] << ">" << std::endl;
    }
}

int main() {
    //Task 1
    int n;
    int cnt;
    std::string words[N_Max];
    if(!Read(n, cnt, words)) {
        return -1;
    }
    FormatWords(cnt, words);
    std::string cons[N_Max];
    for (int i = 0; i < cnt; i++) {
        cons[i] = words[i];
    }
    RemoveVowels(cnt, cons);
    Checker(cnt, words, cons);
    std::string notempty[N_Max];
    DeleteEmptyString(cnt, words, notempty);
//    SortByLength(cnt, words);
    //DebugWrite(cnt, words, cons);
    Write(cnt, words, notempty);
    return 0;
}
