#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <random>

using namespace std;

// Функция для генерации случайного имени студента
string generateRandomName()
{
    vector<std::string> names = { "Максим", "Тахмина", "Насиба", "Миразим", "Ноа", "Лука", "Манижа", "Георгий", "Матвей", "Азиза" };

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, names.size() - 1);

    int randomIndex = distribution(generator);

    return names[randomIndex];
}
// Функция вывода содержимого вектора с использованием Range-based for-loop
void printVectorRange(const vector<string>& vec) {
    for (const auto& name : vec) {
        cout << name << " ";
    }
    cout << endl;
}

// Функция вывода содержимого вектора с использованием итератора
void printVectorIterator(const vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// Функция вывода содержимого вектора с использованием индексного цикла
void printVectorIndex(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Функция расчета среднего значения оценок
double calculateMean(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// Функция расчета медианы оценок
double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    if (grades.size() % 2 == 0) {
        int midIndex1 = grades.size() / 2 - 1;
        int midIndex2 = grades.size() / 2;
        return static_cast<double>(sortedGrades[midIndex1] + sortedGrades[midIndex2]) / 2;
    }
    else {
        int midIndex = grades.size() / 2;
        return sortedGrades[midIndex];
    }
}

// Функция расчета моды оценок
vector<int> calculateMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

// Функция расчета моды оценок для многомодального распределения (Multimodal Mode)
vector<int> calculateMultimodalMode(const vector<int>& grades) {
    map<int, int> counts;
    for (int grade : grades) {
        counts[grade]++;
    }

    int maxCount = 0;
    for (const auto& pair : counts) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modeGrades;
    for (const auto& pair : counts) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    // Если список оценок является многомодальным, проверяем, есть ли оценки, которые
    // встречаются реже всего. Если такие оценки есть, добавляем их в список мод
    for (const auto& pair : counts) {
        if (pair.second == maxCount - 1) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

int main() {
    system("chcp 1251 > nul");
    vector<string> names;
    vector<int> grades;

    int option;
    cout << "Выберите вариант инициализации векторов:" << endl;
    cout << "1. Демонстрационный анализ на дефолтных входных значениях" << endl;
    cout << "2. Анализ на случайных входных значениях" << endl;
    cout << "3. Анализ на входных значениях от пользователя" << endl;
    cout << "Выбор: ";
    cin >> option;

    if (option == 1) {
        // Инициализация векторов с дефолтными значениями
        names = { "Максим", "Тахмина", "Насиба", "Миразим", "Ноа", "Лука", "Манижа", "Георгий", "Матвей", "Азиза" };
        grades = { 77, 80, 95, 50, 65, 72, 88, 99, 57, 63 };
    }
    else if (option == 2) {
        // Инициализация векторов со случайными значениями
        int n;
        cout << "Введите размер выборки: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            names.push_back(generateRandomName());
            grades.push_back(rand() % 101); // Генерация случайной оценки от 0 до 100
        }
    }
    else if (option == 3) {
        // Инициализация векторов значениями, введенными пользователем
        int n;
        cout << "Введите количество оценок: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string name;
            int grade;
            cout << "Введите имя для оценки № " << i + 1 << ": ";
            cin >> name;
            cout << "Введите оценку для " << name << ": ";
            cin >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }
    else {
        cout << "Ошибка: неправильный выбор." << endl;
        return 0;
    }

    cout << endl << "Имена студентов:" << endl;
    printVectorRange(names); // Вывод имен с использованием Range-based for-loop

    cout << endl << "Оценки студентов:" << endl;
    printVectorIterator(grades); // Вывод оценок с использованием итератора

    cout << endl << "Среднее значение оценок: " << calculateMean(grades) << endl;
    cout << "Медиана оценок: " << calculateMedian(grades) << endl;

    cout << "Мода оценок: ";
    vector<int> modeGrades = calculateMode(grades);
    printVectorIndex(modeGrades); // Вывод моды с использованием индексного цикла

    cout << endl << "Мода оценок (для многомодального распределения): ";
    vector<int> multimodalModeGrades = calculateMultimodalMode(grades);
    printVectorIndex(multimodalModeGrades); // Вывод моды для многомодального распределения

    return 0;
}