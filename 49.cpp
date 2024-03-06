#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<string>> students(12); // Создаем вектор векторов для каждого класса
    int klass;
    string surname;

    while (cin >> klass >> surname) {
        if (klass >= 9 && klass <= 11) { // Проверяем, что класс от 9 до 11
            students[klass].push_back(surname); // Добавляем фамилию в соответствующий вектор класса
        }
    }

    for (int i = 9; i <= 11; i++) { // Выводим студентов по классам
        for (const string& surname : students[i]) {
            cout << i << " " << surname << endl;
        }
    }

    return 0;
}
