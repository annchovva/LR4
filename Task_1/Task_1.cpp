#include <iostream>
#include <string>

void menu()
{
    int choice;
    std::cout << "-Главное меню-\n";
    std::cout << "Задание 1. Вариант 7.\n";
    std::cout << "Ввести одномерный статический массив из k чисел.\n";
    std::cout << "Сдвинуть элементы массива циклически на n позиций вправо.\n";
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

//Функция для переворота
void reverse(double *a, int i, int j) {
    while (i < j) {
        int rev = a[i]; 
        a[i] = a[j];
        a[j] = rev;
        i++;
        j--;
    }
}

void result() {

    int k;

    std::cout << "Введите количество элементов массива: k = ";
    while (!(std::cin >> k) or std::cin.get() != '\n' or k <= 0)
    {
        std::cout << "Введите целое положительное число!" << std::endl;
        std::cout << "k = ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    double arr[k]; 

    std::cout << "Введите элементы массива (числа): " << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << "a[" << i << "] = ";  
        while (!(std::cin >> arr[i]) or std::cin.get() != '\n')
        {
        std::cout << "Введите число!" << std::endl;
        std::cout << "a[" << i << "] = ";  
        std::cin.clear();
        while (std::cin.get() != '\n');
        }
    }

    std::cout << "Исходный массив: " << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << arr[i] << "\t";
    }

    std::cout << std::endl;
    
    int n;
    std::cout << "Введите на сколько элементов вправо сдвинуть массив: n = ";
    while (!(std::cin >> n) or std::cin.get() != '\n' or n <= 0)
    {
        std::cout << "Введите целое положительное число!" << std::endl;
        std::cout << "n = ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    
    reverse (arr, 0, k-1);
    reverse (arr, 0, n-1);
    reverse (arr, n, k-1);

    std::cout << "Полученный массив: " << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << arr[i] << "\t";
    }
    
    std::cout << std::endl;
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