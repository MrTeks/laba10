#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int N;
    ifstream inputFile("input.txt"); // Открываем файл input.txt для чтения

    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл input.txt!" << endl;
        return 1;
    }

    inputFile >> N;

    int* arr = new int[N];

    // Считываем числа из файла и сохраняем их в массиве
    for (int i = 0; i < N; i++) {
        inputFile >> arr[i];
    }

    // Закрываем файл input.txt
    inputFile.close();

    // Открываем файл output.txt для записи
    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл output.txt!" << endl;
        return 1;
    }

    // Выводим четные числа в порядке возрастания индексов
    outputFile << "Чётные числа: ";
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            outputFile << arr[i] << " ";
        }
    }
    outputFile << endl;

    // Выводим нечетные числа в порядке убывания индексов
    outputFile << "Нечётные числа: ";
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] % 2 != 0) {
            outputFile << arr[i] << " ";
        }
    }

    // Закрываем файл output.txt
    outputFile.close();

    delete[] arr;
}