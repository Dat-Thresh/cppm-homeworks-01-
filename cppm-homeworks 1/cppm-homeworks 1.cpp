// cppm-homeworks 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

int* read_arr(int size, std::ifstream& reader);//читает массив из файла в динамический массив

int main()
{
    std::ifstream reader;
    reader.open("in.txt");
    if (!reader.is_open()) {
        std::cout << "File is not found\n";
        return 1;
    }
    int size_1, size_2; //размеры массивов из файла

    reader >> size_1; 
    //читаем первый массив
    int* arr_1 = read_arr(size_1, reader);
    if (arr_1 == NULL) {
        return 2;
    }


    //читаем второй массив
    reader >> size_2;
    int* arr_2 = read_arr(size_2, reader);
    if (arr_2 == NULL) {
        return 2;
    }
    reader.close();

    //создаем файл для записи
    std::ofstream writer;
    writer.open("out.txt");
    if (!writer.is_open()) {
        std::cout << "Could not open output file";
        return 3;
    }

    //пишем сначала размер второго массива и его содержимое согласно условию
    writer << size_2 << std::endl;
    writer << arr_2[size_2 - 1] << " ";
    for (int i = 0; i < size_2 - 1; i++) {
        writer << arr_2[i] << " ";
    }
    writer << std::endl;

    //пишем теперь размер первого массива и его содержимое по условиям
    writer << size_1 << std::endl;
    for (int i = 1; i < size_1; i++) {
        writer << arr_1[i] << " ";
    }
    writer << arr_1[0];

    writer.close();
    delete[] arr_1;
    delete[] arr_2;

    


    return 0;
}

int* read_arr(int size, std::ifstream& reader) {
    int* arr = new(std::nothrow) int[size];
    if (arr == NULL) {
        std::cout << "Not enough memory\n";
        abort;
        
    }
    for (int i = 0; i < size; i++) {
        reader >> arr[i];
    }
    return arr;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
