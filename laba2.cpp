//Программа, работающая со строками: Исходные данные представляют собой две строки символов.
//Написать программу, включающую две процедуры, выполняющие следующие действия:
//1. Печать всех слов строки, в которых все буквы различны.
//2. Объединение символов двух строк в выходную строку, в которой символы исходных строк чередуются через два.
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Тесты
//Неверное название 1
//const char* Fname1 = ".txt";
//const char* Fname2 = "ТестМ2.txt";
//Неверное название 2
//const char* Fname1 = "ТестМ1.txt";
//const char* Fname2 = ".txt";
//Пустой 1
//const char* Fname1 = "T.txt";
//const char* Fname2 = "ТестМ2.txt";
//Пустой 2
//const char* Fname1 = "ТестМ1.txt";
//const char* Fname2 = "T.txt";
//Больше строк 1
//const char* Fname1 = "Текст3.txt";
//const char* Fname2 = "ТестМ2.txt";
//Больше строк 2
//const char* Fname1 = "ТестМ1.txt";
//const char* Fname2 = "Текст3.txt";
//1 файл > 2 файла(нечётное)
//const char* Fname1 = "ТестМ1.txt";
//const char* Fname2 = "ТестМ2.txt";
//2 файл > 1 файла(нечётное)
//const char* Fname1 = "ТестМ2.txt";
//const char* Fname2 = "ТестМ1.txt";
//сплошные
const char* Fname1 = "Текст1.txt";
const char* Fname2 = "Текст2.txt";

int main()
{
    setlocale(LC_ALL, "RUSSIAN");//ввод Русского языка
    int word_begin, word_end;//Начало и конец слова
    int max_len;//максимальное из длин строк
    int quantity;//Количество символов
    string line1, line2;//Строки
    bool copare;//флаг

    cout << "Первый файл (" << Fname1 << "):\n";
    ifstream file1(Fname1);//открытие файла 1

    if (!file1.is_open()) {//файл не открылся
        cout << "Ошибка открытия.\n";
        system("PAUSE");
        return 1;
    }//if

    if (file1.peek() == EOF) {//файл пуст
        cout << "Ошибка, файл пуст.\n";
        system("PAUSE");
        return 2;
    }//if

    getline(file1, line1);//ввод всей строки

    if (!file1.eof()) {//перебор данных
        cout << "Ошибка, в файле больше 1 строки.\n";
        system("PAUSE");
        return 3;
    }//if

    file1.close();//закрытие файла
    cout << line1 << endl;//эхо-печать строки

    quantity = 0;
    while (line1[quantity]) {
        quantity++;
    }
    const int max_line1 = quantity;
    cout << "Длина строки: " << max_line1 << endl;//вывод длины строки
    cout << endl;//для красоты

    cout << "Второй файл (" << Fname2 << "):\n";
    ifstream file2(Fname2);//открытие файла 2

    if (!file2.is_open()) {//файл не открылся
        cout << "Ошибка открытия.\n";
        system("PAUSE");
        return 1;
    }//if

    if (file2.peek() == EOF) {//файл пуст
        cout << "Ошибка, файл пуст.\n";
        system("PAUSE");
        return 2;
    }//if

    getline(file2, line2);//ввод всей строки

    if (!file2.eof()) {//перебор данных
        cout << "Ошибка, в файле больше 1 строки.\n";
        system("PAUSE");
        return 3;
    }//if

    file2.close();//закрытие файла
    cout << line2 << endl;//эхо-печать строки

    quantity = 0;
    while (line2[quantity]) {
        quantity++;
    }
    const int max_line2 = quantity;
    cout << "Длина строки: " << max_line2 << endl;//вывод длины строки
    cout << endl;//для красоты

//Работа с первым файлом
    cout << "Все слова 1 строки, в которых все буквы различны: ";
    word_begin = 0;
    while (word_begin != max_line1) {//поиск слов
        while (line1[word_begin] == ' ' && word_begin != max_line1) {//поиск начала слова
            word_begin++;
        }//while
        word_end = word_begin;//
        while (line1[word_end] != ' ' && word_end != max_line1) {//поиск конца слова
            word_end++;
        }//while
        copare = true;//флаг
        for (int i = word_begin; i < word_end; i++) {//проверка на повторные элементы слова
            for (int z = i + 1; z < word_end; z++) {//все элементы после i-го
                if (line1[i] == line1[z]) {//если повторяются
                    copare = false;
                }//if
            }//for
        }//for
        if (copare) {//не повторились
            for (int i = word_begin; i < word_end; i++) {//вывод слова
                cout << line1[i];
            }//for
            cout << " ";
        }//if
        word_begin = word_end;//начало нового = конец старого
    }//while
    cout << endl;

    //Работа со вторым файлом
    cout << "Все слова 2 строки, в которых все буквы различны: ";
    word_begin = 0;
    while (word_begin != max_line2) {//поиск слов
        while (line2[word_begin] == ' ' && word_begin != max_line2) {//поиск начала слова
            word_begin++;
        }//while
        word_end = word_begin;//сдвиг предварительног конца
        while (line2[word_end] != ' ' && word_end != max_line2) {//поиск конца слова
            word_end++;
        }//while
        copare = true;//флаг
        for (int i = word_begin; i < word_end; i++) {//проверка на повторные элементы слова
            for (int z = i + 1; z < word_end; z++) {//все элементы после i-го
                if (line2[i] == line2[z]) {//если повторяются
                    copare = false;
                }//if
            }//for
        }//for
        if (copare) {//не повторились
            for (int i = word_begin; i < word_end; i++) {//вывод слова
                cout << line2[i];
            }//for
            cout << " ";
        }//if
        word_begin = word_end;//сдвиг предварительног конца
    }//while
    cout << endl;

    max_len = max_line1;//поиск максимального среди длин строк
    if (max_len < max_line2) {
        max_len = max_line2;
    }

    cout << "\nОбъединение символов двух строк чередуя их через 2 символа:\n";
    cout << "<";
    for (int i = 0; i < max_len; i += 2) {//пока не кончится наибольшая строка
        if (i < max_line1) {//первый элемент из пары первой строки
            cout << line1[i];
            if (i + 1 == max_line1 && i + 1 < max_line2) {//если нечётное
                cout << " ";
            }
        }
        if (i + 1 < max_line1) {//второй элемент из пары первой строки
            cout << line1[i + 1];
        }

        if (i < max_line2) {//первый элемент из пары второй строки
            cout << line2[i];
            if (i + 1 == max_line2 && i + 1 < max_line1) {//если нечётное
                cout << " ";
            }
        }
        if (i + 1 < max_line2) {//второй элемент из пары второй строки
            cout << line2[i + 1];
        }
    }
    cout << ">\n";

    system("PAUSE");
    return 0;
}//main
