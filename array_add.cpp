///Автор: Ошлаков Данил, ИВТ-22. Модули для программы для поиска ответа на все вопросы жизни, вселенной и всего такого
///Модуль, содержащий функции и процедуры, необходитмые для работы с заданием 136Г
// #include <iostream>
// #include <fstream>
// #include <ctime>
// #include <cstdlib>
// #include <math.h>
// #include <cstring>
// #include <string>

// #include "array_add.h"

// using namespace std;

// double *array;//Массив

// ///Функция вывода массива array размера size на экран
// void print_array(double *array, unsigned long int size)
// {
// for(unsigned long int i=0; i<size; i++)
// 	{
// 		cout << array[i] << " ";
// 	}
// }

// ///Сохраняет массив array размера size в файле с именем file_name
// void save_array(double *array, unsigned long int size, const string& file_name)
// {
// ofstream file(file_name);
// // if open
// for(unsigned long int i=0; i<size; i++)
// 	{
// 		file << array[i]  << endl;
// 	}
// }

// ///Заполнение массива array размера size случайными числами от lowest до highest
// void fill_rand_array(double *array, unsigned long int size, double highest, double lowest)
// {	
// 	double range = highest - lowest;
// 	for(unsigned long int i = 0; i < size; i ++)
// 	{
// 		array[i]=(double)rand()/RAND_MAX*range+lowest;
// 	}
// }

// ///Вычисляет произведение всех модулей массива array размера size 
// double calculate_abs_multi(double *array, unsigned long int size)
// {
// 	double result = abs(array[0]);
// 	for(unsigned long int i = 1; i < size; i ++)
// 	{
// 		if (array[i] == 0)
// 		{
// 				throw "Cause of zero element everything will turn into zero";	
// 		}
// 		result=result*abs(array[i]);
// 	}
// 	return result;
// }


//Ищет размер файла file_name в виде числа строк. На вход имя файла в кавычках
// unsigned file_size(const string& file_name)
// {
// 	string empty_line;
// 	unsigned long int result = 0;
// 	ifstream file(file_name);
// 	if (!file.is_open())
// 	{
// 		cout << "File not found:" << endl;
// 		return 0;
// 	}
// 	while (getline(file, empty_line))
// 	{
// 		result++;
// 	}
// 	file.close();
// 	return result;
// }


// ///Загружает массив array размера size из файла file_name. Выводит в уже созданный массив array размера size 
// void load_array(double *array, unsigned long int size, const string& file_name)
// {
// string load_line;
// unsigned long int result = 0;
// ifstream file(file_name);
// if (!file.is_open())
// {
// 	cout << "File not found:" << endl;

// }
// 	for(unsigned long int i = 0; i < size; i ++)
// 	{
// 		file >> array[i];
// 	}
// }
// ///Сохраняет массив array размера size из бинарного файла file_name
// void save_array_bin(const double* array,  unsigned long int size, const string& file_name) 
// {
//     ofstream file(file_name, ios::binary);
//     if (!file.is_open())
// {
// 	cout << "File opening error:" << endl;

// }
// else
// {
//     file.write(reinterpret_cast<const char*>(&size), sizeof(size));
//     file.write(reinterpret_cast<const char*>(array), sizeof(double) * size);
//     file.close();
// }
// }
// ///Создает и заполняет массив array размера size из бинарного файла file_name
// void load_array_bin(double*& array,  unsigned long int& size, const string& file_name) 
// {

//     ifstream file(file_name, ios::binary);
// if (!file.is_open())
// {
// 	cout << "File not found:" << endl;

// }
// else
// {
//     file.read(reinterpret_cast<char*>(&size), sizeof(size));
//     array = new double[size];
//     file.read(reinterpret_cast<char*>(array), sizeof(double) * size);
//     file.close();
// }
// }

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <string>
#include <vector>

#include "array_add.h"

using namespace std;

vector<double> array; // Вектор

/// Функция вывода массива array размера size на экран
void print_array(const vector<double>& array)
{
    for (unsigned long int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
}

/// Сохраняет массив array размера size в файле с именем file_name
void save_array(const vector<double>& array, const string& file_name)
{
    ofstream file(file_name);
    // Если файл открыт
    if (file.is_open())
    {
        for (unsigned long int i = 0; i < array.size(); i++)
        {
            file << array[i] << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

/// Заполнение массива array размера size случайными числами от lowest до highest
void fill_rand_array(vector<double>& array, double highest, double lowest)
{
    double range = highest - lowest;
    unsigned long int size = array.size();
    for (unsigned long int i = 0; i < size; i++)
    {	
    	cout << i << endl;
        array[i]=((double)rand() / RAND_MAX * range + lowest);
    }
}

/// Вычисляет произведение всех модулей массива array размера size
double calculate_abs_multi(const vector<double>& array)
{
     if (array.size() == 0)
        {
            throw "Cause of zero length, array doesnt exist";
        }
    double result = abs(array[0]);
    for (unsigned long int i = 1; i < array.size(); i++)
    {
        if (array[i] == 0)
        {
            throw "Cause of zero element everything will turn into zero";
        }
        result = result * abs(array[i]);
    }
    return result;
}

/// Ищет размер файла file_name в виде числа строк. На вход имя файла в кавычках
unsigned long int file_size(const string& file_name)
{
    string empty_line;
    unsigned long int result = 0;
    ifstream file(file_name);
    if (!file.is_open())
    {
        cout << "File not found:" << endl;
        return 0;
    }
    while (getline(file, empty_line))
    {
        result++;
    }
    file.close();
    return result;
}


/// Загружает массив array размера size из файла file_name. Выводит в уже созданный массив array размера size 
void load_array(vector<double>& array, const string& file_name)
{
    string load_line;
    ifstream file(file_name);
    if (!file.is_open())
    {
        cout << "File not found:" << endl;
    }
    else
    {
        while (getline(file, load_line))
        {
            array.push_back(stod(load_line));
        }
        file.close();
    }
}

/// Сохраняет массив array размера size из бинарного файла file_name
void save_array_bin(const vector<double>& array, const string& file_name)
{
    ofstream file(file_name, ios::binary);
    if (!file.is_open())
    {
        cout << "File opening error:" << endl;
    }
    else
    {
        unsigned long int size = array.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(reinterpret_cast<const char*>(array.data()), sizeof(double) * size);
        file.close();
    }
}

/// Создает и заполняет массив array размера size из бинарного файла file_name
void load_array_bin(vector<double>& array, const string& file_name)
{
    unsigned long int size = array.size();
    ifstream file(file_name, ios::binary);
    if (!file.is_open())
    {
        cout << "File not found:" << endl;
    }
    else
    {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        array.resize(size);
        file.read(reinterpret_cast<char*>(array.data()), sizeof(double) * size);
        file.close();
    }
}