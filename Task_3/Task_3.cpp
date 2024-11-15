#include <iostream>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 3. Вариант 7.\n";
    std::cout << "Память для массива выделить динамически.\n";
    std::cout << "Дана вещественная матрица размером N, все элементы которой различны.\n";
    std::cout << "Найти скалярное произведение строки, в которой находится\n";
    std::cout << "наибольший элемент матрицы, на столбец с наименьшим элементом.\n";
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

    std::cout << "Введите размерность матрицы: N = ";
    while (!(std::cin >> N) or std::cin.get() != '\n' or N <= 0)
    {
        std::cout << "Введите целое положительное число!" << std::endl;
        std::cout << "N = ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    double **arr = new double *[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new double [N]; 
    }

    std::cout << "Введите элементы массива (различные числа):" << std::endl;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            while (!(std::cin >> arr[i][j]) or std::cin.get() != '\n') {
            std::cout << "Введите целое положительное число!" << std::endl;
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin.clear();
            while (std::cin.get() != '\n');
            }

            for (int k = 0; k < i; k++) {
                for (int m = 0; m < N; m++) {
                    while (arr[i][j] == arr[k][m]) {
                        std::cout << "Такое число уже было введено, введите другое!" << std::endl;
                        std::cout << "a[" << i << "][" << j << "] = ";
                        while (!(std::cin >> arr[i][j]) or std::cin.get() != '\n') {
                            std::cout << "Введите целое положительное число!" << std::endl;
                            std::cout << "a[" << i << "][" << j << "] = ";
                            std::cin.clear();
                            while (std::cin.get() != '\n');
                        }
                    }
                }
            }    
            for (int m = 0; m < j; m++) {
                while (arr[i][j] == arr[i][m]) {
                    std::cout << "Такое число уже было введено, введите другое!" << std::endl;
                    std::cout << "a[" << i << "][" << j << "] = ";
                    while (!(std::cin >> arr[i][j]) or std::cin.get() != '\n') {
                        std::cout << "Введите целое положительное число!" << std::endl;
                        std::cout << "a[" << i << "][" << j << "] = ";
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                    }    
                }
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
    
    int r;
    int c;

    double max_value = arr[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (max_value <= arr[i][j]) {
                max_value = arr[i][j];
                r = i;
            }
        }
    }
    std::cout << "Максимальный элемент: " << max_value << " в " << r << " строке" << std::endl;

    double min_value = arr[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (min_value >= arr[i][j]) {
                min_value = arr[i][j];
                c = j;

            }
        }
    }
    std::cout << "Минимальный элемент: " << min_value << " в " << c << " столбце" << std::endl;

    double res = 0;
    for (int i = 0, j = 0;  i < N, j < N; i++, j++) {
            double term = arr[r][j] * arr[i][c];
            res += term;
    }

    std::cout << "Результат: " << res << std::endl;

    for (int i = 0; i < N; i++) {
        delete [] arr[i]; 
    }
    delete [] arr;
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