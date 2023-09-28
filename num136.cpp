///Тестовое изменение
    #include <iostream> 
    #include <fstream> 
    #include <ctime> 
    #include <cstdlib> 
    #include <math.h> 
    #include <cassert> 
	#include <cstring> 
	#include <vector>
///Подключение необходимых библиотек
    #include "array_add.h"///Подключение функций длля работы с массивами для номера 136. Заккоментированно для проверки стат.библиотеки     
    using namespace std; 
    namespace num136
	{
    unsigned long int array_size; // Длина массива 
    char load_check; // Символ для выбора вида заполнения 
    double lowest_value; // Наименьшее и наибольшее значение при автозаполнении
    double highest_value; 
    string file_output;//Имена текстового и бинарного файла соотвественно
    string file_output_bin; 
    string test_on_txt;
	}///Пространство имен для этой задачи
	
	using namespace num136;
///Удален лишний текст

    int main() {
    vector<double> array; // Массив 
{
    vector<double> t = {1, 1, 1}; // Проверка assert'ом
    assert(abs(calculate_abs_multi(t)) - 1 <= 10E-9);
}
{
    vector<double> t = {2, 2, 3};
    assert(abs(calculate_abs_multi(t)) - 12 <= 10E-9);
}
{
    vector<double> t = {1, 2, 3};
    assert(abs(calculate_abs_multi(t)) - 6 <= 10E-9);
}




    cout << "Please, input file name:" << endl; 
    cin >> file_output;
    if (file_output.length()<4)
    {
    	file_output = "save.txt";
    	cout << "File name is too low, file name set by default as 'save.txt'" << endl;
    }
    test_on_txt = file_output.substr(file_output.length() - 4);
    
    if (test_on_txt != ".txt")
    {
    	cout << "Your file not have .txt at the end of its name";
    	file_output.append(".txt");
    }
    file_output_bin = file_output;
    file_output_bin.replace(file_output_bin.length() - 3, 3, "bin");
    cout << "For load from file write Y or y:" << endl; 
    cin >> load_check; 
    if (load_check == 'Y' || load_check =='y') { // Загрузка из файла
        cout << "For load from BIN write B or b:" << endl; 
        cin >> load_check;
        if (load_check == 'B' || load_check =='b') {
            load_array_bin(array, file_output_bin);
        } else {      
            // array_size = file_size(file_output); 
            // array.resize(array_size); 
            load_array(array, file_output); 
        }
    } else { // Автозаполнение массива 
        cout << "Input array length:" << endl; 
        cin >> array_size; 
        array.resize(array_size);
        cout << "Input lowest value:" << endl;  
        cin >> lowest_value;
        cout << "Input highest value:" << endl;  
        cin >> highest_value; 
        fill_rand_array(array, highest_value, lowest_value); 
    } 
    cout << "Your array:" << endl; 
    print_array(array); 
    cout << endl;
    try {
        cout << "Abs array multiple: " << calculate_abs_multi(array) << endl;
    } catch (const char* error_message) {
        cout << error_message << endl;
    } 
    save_array(array, file_output); 
    save_array_bin(array, file_output_bin);
    // cout << "File length: " << file_size(file_output) << endl;
    return 0;
}