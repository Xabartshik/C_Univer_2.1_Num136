///Автор: Ошлаков Данил, ИВТ-22. Модули для программы для поиска ответа на все вопросы жизни, вселенной и всего такого
///Модуль, содержащий функции и процедуры, необходитмые для работы с заданием 136Г
#ifndef ARRAY_ADD_H
#define ARRAY_ADD_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

/// Функция вывода массива array на экран
void print_array(const vector<double>& array);

/// Сохраняет массив array в файле с именем file_name
void save_array(const vector<double>& array, const string& file_name);

/// Заполнение массива array случайными числами от lowest до highest
void fill_rand_array(vector<double>& array, double highest, double lowest);

/// Вычисляет произведение всех модулей массива array 
double calculate_abs_multi(const vector<double>& array);

// Ищет размер файла file_name в виде числа строк. На вход имя файла в кавычках
unsigned long int file_size(const string& file_name);

/// Загружает массив array размера size из файла file_name. Выводит в уже созданный массив array размера size 
void load_array(vector<double>& array, const string& file_name);

/// Создает и заполняет массив array размера size из бинарного файла file_name
void load_array_bin(vector<double>& array, const string& file_name);

/// Сохраняет массив array размера size в бинарный файл file_name
void save_array_bin(const vector<double>& array, const string& file_name);

#endif // ARRAY_ADD_H

