////Задача CSV , Статистики-2 , Якименко.
#include "CSV.h"
void displaymenu()
{
    cout << "===================================================== \n";
    cout << " \t\tMENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.exit\n";
    cout << " 2.add\n";
    cout << " 3.delete\n";
    cout << " 4.print\n";
    cout << " 5.GetValueByTitleName\n";
    cout << " 6.LoadFromFile\n";
    cout << " 7.SaveToFile\n";
};//Опис меню
void exit()
{
    system("exit");

};//Закриває меню

void add(CSV& t) {
    string s;// = "128;12;33;321;356;";
    cout << "Enter line:";
    cin >> s;
    // DinArr_Simple ar;
    t.add(s);

};//Додаємо об'єкти 
void SaveToFile(CSV& t) {
    string s;
    cout << "Name file:";
    cin >> s;
    t.SaveToFile(s);


};//Збереження в файл

void LoadFromFile(CSV& t) {
    string s;
    cout << "Name file:";
    cin >> s;
    t.LoadFromFile(s);


};
void GetValueByTitleName(CSV& t) {
    string s;
    cout << "Enter line";
    cin >> s;
    int k;
    cout << "Enter position";
    cin >> k;
    t.GetValueByTitleName(s, k);



};

void print(CSV& t) {

    //DinArr_Simple ar;
    t.print();


};//Виведення результату 
void del(CSV& t) {
    int k;
    cout << "Please enter line to del:";
    cin >> k;
    //DinArr_Simple ar;
    t.del(k);

};//Видаляємо лінію , вказавши номер лініЇ k
    int main()
    {
        
        CSV table ;
        displaymenu(); 
        int yourchoice; 
       // string confirm;
        do
        {
            cout << "Enter your choice(1-7):";
            cin >> yourchoice;                  //Вводимо номер який нам потрібен
            switch (yourchoice)
            {
            case 1: exit(); break;
            case 2: add(table); break;
            case 3: del(table); break;
            case 4: print(table); break;
            case 5: GetValueByTitleName(table); break;
            case 6: LoadFromFile(table); break;
            case 7: SaveToFile(table); break;

                
            }
            //cout << "Press next:";
           // cin >> confirm;

        } while (yourchoice != 1);// == "next" );
         return 0;
        
    }