//������� ����� #include <string.h>
//std::string str1; //��������
//std::string str2 = "Something"; //�������������
//������������ ��� ������ ��������� ���� char

//strlen(str) - ����� �����
//char *strcat (str2, �words words�) -  ������������� str2 � ����� "Something words words"
//��������� �� ������� �words words� � ������� � str2

//int strcmp(const char *str1, const char*str2)
//str1, str2 � ��������� �� ������������ ������, � ������ ��������� ��������� 0,
//� ���� �� ������������� ��� ������������� �����

//char *strtok(char *str, const char *sep) - ������� �������� ������
//sep - ����� ����� ������� ����� ��������� ������

//char *strchr (const char *str, int ch), ��� ch - ������, �-�� ����� ������ � ������


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

    while (s != NULL) //���� ���������� ����� ��������� �� �����
        {kolvo_words++; s = strtok (NULL, " ,.-;:!?");}

        cout  << kolvo_words << endl;
}




