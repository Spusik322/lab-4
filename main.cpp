#include <iostream>
#include <cstring>
using namespace std;
bool esli (const char* stroka1, const char* stroka2){
    for (; (*stroka1 != '\0') || (*stroka2 != '\0'); stroka1++, stroka2++){
        if(*stroka1 != *stroka2){
            return false;
        }
    }
    return true;
}
const char* str (const char* stroka1, const char* podstroka){
    while(*stroka1 != '\0'){
        if(esli (stroka1, podstroka)){
        return stroka1;
        }
        stroka1++;
    }
    return nullptr;
}
bool islatin(char* word){
    if (!*word)
        return false;
    while (*word) {
        char ch = *word;
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))){
            return false;
        }
        word++;
    }
    return true;
}
bool countglasnyasoglasnya (const char* word){
    int glasnya = 0;
    int soglasnya = 0;
    while (*word) {
        char ch = *word;
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            glasnya++;
        } 
        else{
            soglasnya++;
        }
        word++;
    }
    return ((glasnya == soglasnya) && (glasnya != 0));
}
char* slovo (char* input, char* word){
    while(*input == ' ')
        input++;
    for(; (*input != ' ') && (*input != '\0'); input++, word++){
        *word = *input;
    }
    *word = '\0';
    return input;
}
int main(){
    //Часть а
    const int MAX_LENGTH = 1000;
    char stroka[MAX_LENGTH];
    char strCharSet[MAX_LENGTH];
    cout << "Введите первую строку: ";
    cin.getline(stroka, MAX_LENGTH);
    cout << "Введите подстроку: ";
    cin.getline(strCharSet, MAX_LENGTH);
    const char* result = str(stroka, strCharSet);
    if (result != nullptr){
        cout << "Найдено: " << result << endl;
    }
    else{
        cout << "Подстрока не найдена." << endl;
    }
    //Часть б
    const int MA_LENGTH = 300;
    char input[MA_LENGTH];
    cout << "Введите строку: ";
    cin.getline(input, MA_LENGTH);
    int totalwords = 0;
    int equalwords = 0;
    char word[MA_LENGTH];
    char* res = input;
    *word = '\0';
    do{
        res = slovo (res, word);
        if(islatin(word)){
            totalwords ++; 
            if (countglasnyasoglasnya(word))
                equalwords ++;
        }    
    }
    while (*res);  
    cout << "Количество слов с латинскими символами: " << totalwords << endl;
    cout << "Количество слов с равным числом гласных и согласных: " << equalwords << endl;
    return 0;
}