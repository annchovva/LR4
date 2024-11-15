#include <iostream>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 2. Вариант 7.\n";
    std::cout << "Инициализировать при объявлении статический двумерный массив целых чисел размером MxN.\n";
    std::cout << "Найти максимальный среди элементов, лежащих ниже побочной диагонали.\n";
    std::cout << "Вывести на экран исходные данные и полученный результат.\n";
    std::cout << "Выполнила Горбачёва Анна, гр.453504\n";
    std::cout << "1 - Результат\n";
    std::cout << "0 - Выход\n";
}

int get_input()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (input.length() == 1 && (input[0] == '0' || input[0] == '1'))
        {
            return input[0] - '0';
        }
        else
        {
            std::cout << "Введите 0 или 1: ";
        }
    }
}

void result() {
    int N;
    std::cout << "Введите размерность массива: N = ";
    while (!(std::cin >> N) or std::cin.get() != '\n' or N <= 0)
    {
        std::cout << "Введите целое положительное число!" << std::endl; 
        std::cout << "N = ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    int arr[N][N];

    std::cout << "Введите элементы массива (целые числа): " << std::endl; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            while (!(std::cin >> arr[i][j]) or std::cin.get() != '\n') {
            std::cout << "Введите целое число!" << std::endl;
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin.clear();
            while (std::cin.get() != '\n');
            }
        }
    }

    std::cout << "Исходный массив: " << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int max_value = arr[1][N - 1];

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > N - i - 1; j--) {
            if (max_value < arr[i][j]) {
                max_value = arr[i][j];
            }
        }
    }
    std::cout << "Максимальный элемент ниже побочной оси: " << max_value << std::endl;
}

int main()
{
    while (true)
    {
        menu();
        std::cout << "Выберите действие: ";
        int choice = get_input();
        if (choice == 1)
        {
            result();
        }
        else if (choice == 0)
        {
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << ".\n";
        std::cout << "Желаете повторить программу? (1 - да, 0 - нет): ";
        int retry = get_input();
        if (retry == 0)
        {
            std::cout << "Вы вышли из программы.\n";
            break;
        }
        else if (retry == 1)
        {
            continue;
        }
    }
    return 0;
}