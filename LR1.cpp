#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функция для создания растущего динамического массива
std::vector<int> createGrowingArray(int size) {
    std::vector<int> result;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
;

    // Заполняем исходный массив случайными числами в диапазоне от -50 до 50 и выводим его
    for (int i = 0; i < size; i++) {
        int randomNum = std::rand() % 101 - 50;
        result.push_back(randomNum);
        std::cout << randomNum << " ";
    }
    std::cout << std::endl;

    // Вычисляем сумму и среднее арифметическое по абсолютной величине
    int sum = 0;
    double absAvg = 0.0;
    int min = result[0];
    int max = result[0];

    for (int num : result) {
        sum += num;
        absAvg += std::abs(num);

        if (num < min) {
            min = num;
        }

        if (num > max) {
            max = num;
        }
    }

    absAvg /= static_cast<double>(size);

    // Добавляем сумму и среднее арифметическое в результирующий массив
    result.push_back(sum);
    result.push_back(static_cast<int>(absAvg));

    // Деление на минимум и добавление максимума
    for (int i = 0; i < size; i++) {
        result[i] /= min;
        result.push_back(max);
    }

    return result;
}

int main() {
    int Size;
  
    std::cin >> Size;

    std::vector<int> growingArray = createGrowingArray(Size);

    for (int num : growingArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
