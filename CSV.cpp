//Задача CSV , Статистики-2 , Якименко
#include "CSV.h"
    void DinArr_Simple::CopyDinArr_Simple(DinArr_Simple& l) {
        //cout << "Copy constructor ...";
        size = l.size;
        separator = l.separator;
        arr = new string[size];
        for (int i = 0; i < size; i++) {
            arr[i] = l.arr[i];
        }

    };
    DinArr_Simple::DinArr_Simple(const DinArr_Simple& l) {
        //cout << "Copy constructor ...";
        size = l.size;
        separator = l.separator;
        arr = new string[size];
        for (int i = 0; i < size; i++) {
            arr[i] = l.arr[i];
        }

    };
    DinArr_Simple::DinArr_Simple() {
        separator = ';';
        arr = nullptr;
        size = 0;
        //cout << "Def constructor";
    };
    DinArr_Simple::DinArr_Simple(char separator) {
        this->separator = separator;
        arr = nullptr;
        size = 0;
        //cout << "Separator constructor ";
    };
    DinArr_Simple::DinArr_Simple(string  value) {
        separator = ';';
        parse_from_string(value);
        //size = 0;
        //cout << "String constructor";
    };
    void DinArr_Simple::print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << separator;
        }

    };
    void DinArr_Simple::input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];// 
            //cout<< separator;
        }
    };
    string& DinArr_Simple::operator[](int pos) { return arr[pos]; };
    string& DinArr_Simple::operator[](string val) {
        for (int i = 0; i < size; i++) {
            if (arr[i]== val)return arr[i];
        };
        return arr[0];


    };
    void DinArr_Simple::set_size(int n) {
        arr = new string[n];
        size = n;
    }
    bool DinArr_Simple::add(string value) {
        try {
            string* temp = new string[size + 1];
            // char* buff;
            for (int i = 0; i < size; i++) {

                // strcpy(buff, arr[i].c_str());
                temp[i] = arr[i];
                // = ;

            };
            delete[]arr;
            arr = temp;
            arr[size] = value;
            size++;
        }
        catch (...) {
            return 0;
        }
        return 1;
    };
    bool DinArr_Simple::del(int pos) {
        try {
            string* temp = new string[size - 1];

            for (int i = 0, j = 0; i < size; i++) {

                if (pos != i) { temp[j] = arr[i]; j++; };

            };
            delete[]arr;
            arr = temp;
            ///arr[size] = value;
            size--;
        }
        catch (...) {
            return 0;
        }
        return 1;
    };
    int DinArr_Simple::get_size() { return size; };
    bool DinArr_Simple::insert(string value, int pos) {
        try {
            string* temp = new string[size + 1];

            for (int i = 0, j = 0; i < size + 1; i++) {

                if (pos == i) {
                    temp[i] = value;
                    // j++;
                }
                else { temp[i] = arr[j]; j++; };
                //j++;
            };
            delete[]arr;
            arr = temp;
            ///arr[size] = value;
            size++;
        }
        catch (...) {
            return 0;
        }
        return 1;
    };
    bool DinArr_Simple::parse_from_string(string s) {
        //cout << "Parsing ...";
        //cout << s;
        try {
            int first_separator = 0;
            int second_separator = 0;
            for (int i = 0; i < s.length(); i++) {
                //cout << "*";
                if (s[i] == separator) {
                    second_separator = i;
                    if (first_separator)first_separator++;
                    //cout << s.substr(first_separator, second_separator - first_separator) << endl;
                    add(s.substr(first_separator, second_separator - first_separator));
                    first_separator = second_separator;
                }

            }
        }
        catch (...) {
            return 0;
        }
        return 1;
    };
    string DinArr_Simple::ToString() {
        string s;
        for (int i = 0, j = 0; i < size; i++) {

            s = s + arr[i] + separator;

        };
        return s;
    };
    DinArr_Simple::~DinArr_Simple() { delete[]arr; };



    //void CSV::BuildTitleArray() {};
    
    CSV::CSV() {
        Line = nullptr;
        size = 0;
    }

    bool CSV::add(string value) {
        try {
            DinArr_Simple* temp = new DinArr_Simple[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i].CopyDinArr_Simple(Line[i]);
            };
            delete[] Line;
            Line = temp;
            Line[size].parse_from_string(value);
            size++;
        }
        catch (...) {
            return 0;
        }
        return 1;
    };//Додаємо об'єкти 
    bool CSV::insert(string value, int pos) {
        try {
            DinArr_Simple* temp = new DinArr_Simple[size + 1];

            for (int i = 0, j = 0; i < size + 1; i++) {

                if (pos == i) {
                    //temp[i].CopyDinArr_Simple(Line[i]);
                    temp[i].parse_from_string(value);
                    // j++;
                }
                else { temp[i].CopyDinArr_Simple(Line[j]); j++; };
                //j++;
            };
            delete[] Line;
            //arr = temp;
            ///arr[size] = value;
            Line = temp;
            size++;
        }
        catch (...) {
            return 0;
        }
        return 1;
    };
    bool CSV::del(int pos) {
        try {
            DinArr_Simple* temp = new DinArr_Simple[size - 1];
            for (int i = 0, j = 0; i < size; i++) {
                if (pos != i) { temp[j].CopyDinArr_Simple(Line[i]); j++; };
            };
            delete[] Line;
            Line = temp;
            size--;
        }
        catch (...) {
            return 0;
        }
        return 1;

    };////Видаляємо лінію , вказавши номер лініЇ k
    DinArr_Simple& CSV::operator[](int pos) {
        return Line[pos];
    }
    string CSV::GetValueByTitleName(string title, int pos) {
        string s = "";
        for (int i = 0; i < Line[0].get_size(); i++) {
            if (Line[0][i] == title) {
                cout << "Good";
                s = Line[pos][i];
            };
        };
        return s;
    }//Повернення значення за заголовком і номером рядка
    void CSV::LoadFromFile(string filename) {
        ifstream file(filename, ios::in);
        if (!Line && file)delete[] Line;
        string s;
        while (file) {
            getline(file, s);
            add(s);
        }

    };//Завантаження з файлу
    void CSV::SaveToFile(string filename) {
        ofstream file(filename, ios::out);
        if (file) {
            for (int i = 0; i < size; i++) {
                file << Line[i].ToString() << endl;
            };
        };
        file.close();
    };//Збереження в файл
    void CSV::print() {
        // cout << "Printing ...";
        for (int i = 0; i < size; i++) {
            //      cout << "Line " << i << endl;
            Line[i].print();
            cout << endl;
        }
    };//Виведення результату 

    CSV::~CSV() {
        delete[] Line;
    };



