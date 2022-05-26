//Задача CSV , Статистики-2 , Якименко
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DinArr_Simple {
    string* arr;
    int size;
    char separator;
public:
    void CopyDinArr_Simple(DinArr_Simple& l);
    DinArr_Simple(const DinArr_Simple& l);
    DinArr_Simple();
    DinArr_Simple(char separator);
    DinArr_Simple(string  value);
    void print();//Введення результату;
    void input();
    string& operator[](int pos);
    string& operator[](string val);
    void set_size(int n);
    bool add(string value);//Додаємо об'єкти
    bool del(int pos); ////Видаляємо лінію , вказавши номер лініЇ k
    int get_size();
    bool insert(string value, int pos);
    bool parse_from_string(string s);
    string ToString();
    ~DinArr_Simple();
};
class CSV {
    DinArr_Simple* Line;
    int size;

public:
    void BuildTitleArray();
    CSV();//клас CSV
    bool add(string value);//Додаємо об'єкти 
    bool insert(string value, int pos);//Введення;
    bool del(int pos);               ////Видаляємо лінію , вказавши номер лініЇ k
    DinArr_Simple& operator[](int pos);
    string GetValueByTitleName(string title, int pos);    //Повернення значення за заголовком і номером рядка
    void LoadFromFile(string filename);    //Завантаження з файлу
    void SaveToFile(string filename);      //Збереження в файл
    void print();                 //Виведення результату 

    ~CSV();
};


