//вначале пишем #include <string.h>
//std::string str1; //—оздание
//std::string str2 = "Something"; //»нициализаци€
//используетс€ как массив элементов типа char

//strlen(str) - длина р€дка
//char *strcat (str2, Ђwords wordsї) -  переформирует str2 в р€док "Something words words"
//скопирует из массива Ђwords wordsї и добавит к str2

//int strcmp(const char *str1, const char*str2)
//str1, str2 Ц указатели на сравниваемые строки, в случае равенства возвратит 0,
//в ином сл положительное или отрицательное число

//char *strtok(char *str, const char *sep) - функци€ разбити€ строки
//sep - штуки после которых нужно разделить строку

//char *strchr (const char *str, int ch), где ch - символ, к-ый будут искать в строке


#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
    int kolvo_words;
    const int n = 100;
    char str[n];
    gets(str);
    char *s = strtok (str," ,.-;:!?");

    while (s != NULL) //пока невозможно будеи разделить на части
        {kolvo_words++; s = strtok (NULL, " ,.-;:!?");}

        cout  << kolvo_words << endl;
}




