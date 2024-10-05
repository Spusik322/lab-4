#include <iostream>
#include <cstring>
using namespace std;
char* str(const char* stroka, const char* strCharSet) {
    if (*strCharSet == '\0'){
        return const_cast<char*>(stroka);
    }
    while (*stroka){
        const char* start = stroka;
        const char* pattern = strCharSet;
        while (*stroka && *pattern && (*stroka == *pattern)) {
            stroka++;
            pattern++;
        }
        if (*pattern == '\0'){
            return const_cast<char*>(start);
        }
        stroka = start + 1;
    }
    return nullptr;
}
bool islatin(char ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
void countglasnyasoglasnya(const char* word, int& glasnya, int& soglasnya){
    glasnya = 0;
    soglasnya = 0;
    while (*word) {
        char ch = *word;
        if (islatin(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                glasnya++;
            } 
            else{
                soglasnya++;
            }
        }
        word++;
    }
}
int main(){
    //Часть а
    char* stroka;
    char* strCharSet;
    cout << "Часть а)"<< endl << "Введите первую строку: ";
    cin >> stroka;
    cout << "Введите подстроку: ";
    cin >> strCharSet;
    char* result = str(stroka, strCharSet);
    if (result != nullptr){
        cout << "Найдено: " << result << endl;
    }
    else{
        cout << "Подстрока не найдена." << endl;
    }
    //Часть б
    const int MAX_LENGTH = 300;
    char input[MAX_LENGTH];
    cout << "Введите строку: ";
    cin.getline(input, MAX_LENGTH);
    int totalwords = 0;
    int equalwords = 0;
    char word[MAX_LENGTH];
    int index = 0;
    for (int i = 0; ; i++){
        if (input[i] == ' ' || input[i] == '\0'){
            if (index > 0){
                word[index] = '\0';
                index = 0;
                bool isLatin = true;
                for (char* ptr = word; *ptr; ptr++){
                    if (islatin(*ptr) == 0){
                        isLatin = false;
                        break;
                    }
                }
                if (isLatin){
                    totalwords++;
                    int glasnya, soglasnya;
                    countglasnyasoglasnya(word, glasnya, soglasnya);
                    if (glasnya == soglasnya){
                        equalwords++;
                    }
                }
            }
            if (input[i] == '\0') 
                break;
        } 
        else{
            word[index++] = input[i];
        }
    }
    cout << "Количество слов с латинскими символами: " << totalwords << endl;
    cout << "Количество слов с равным числом гласных и согласных: " << equalwords << endl;
    return 0;
}