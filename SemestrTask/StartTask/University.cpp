#include <iostream>
#include <tuple>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <chrono>

bool isNumber(int num) {
    if (!num) {
        std::cout << "Ошибка: это не число. Пожалуйста, введите число снова.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
        return 0;
    }
}

void Task1() {
    std::cout << "Решение задачи 1" << std::endl;
    int a = 1, b = 2, c = 3;
    std::tie(a, b, c) = std::make_tuple(b, c, a);
    std::cout << a << b << c << std::endl;
}

void Task2() {
    std::cout << "Решение задачи 2" << std::endl;

    int n;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int number;
        std::cout << "Введите число: ";
        std::cin >> number;
        if (isNumber(number)) {
            --i;
        }
        else {
            sum += number;
        };
    }
    std::cout << "Сумма введенных чисел: " << sum << std::endl;
}

void Task3() {
    std::cout << "Решение задачи 3" << std::endl;

    int result = 1;
    int x;
    std::cout << "Введите число: " << std::endl;
    std::cin >> x;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 5; i++) {
        result *= x;
    }
    std::cout << result << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Время выполнения: " << diff.count() << " секунд." << std::endl;

}

void Task4() {
    std::cout << "Решение задачи 4" << std::endl;

    int n;
    std::cout << "Введите число от 0 до 250: ";
    std::cin >> n;

    if (n < 0 || n > 250) {
        std::cout << "Число вне допустимого диапазона." << std::endl;
        Task4();
        return;
    }

    int a = 0;
    int b = 1;
    while (a < n) {
        int temp = a;
        a = b;
        b = temp + b;
    }

    if (a == n) {
        std::cout << "Число является числом Фибоначчи." << std::endl;
    }
    else {
        std::cout << "Число не является числом Фибоначчи." << std::endl;
    }

}

void Task5_1() {
    std::map<int, std::string> seasons{
    {12, "Зима"}, {1, "Зима"}, {2, "Зима"},
    {3, "Весна"}, {4, "Весна"}, {5, "Весна"},
    {6, "Лето"}, {7, "Лето"}, {8, "Лето"},
    {9, "Осень"}, {10, "Осень"}, {11, "Осень"}
    };

    int month;
    std::cout << "Введите номер месяца: ";
    std::cin >> month;

    if (seasons.count(month)) {
        std::cout << seasons[month] << std::endl;
    }
    else {
        std::cout << "Некорректный номер месяца" << std::endl;
    }
}
void Task5_2() {
    int month;
    std::cout << "Введите номер месяца: ";
    std::cin >> month;

    if (month == 12 || month == 1 || month == 2) {
        std::cout << "Зима" << std::endl;
    }
    else if (month >= 3 && month <= 5) {
        std::cout << "Весна" << std::endl;
    }
    else if (month >= 6 && month <= 8) {
        std::cout << "Лето" << std::endl;
    }
    else if (month >= 9 && month <= 11) {
        std::cout << "Осень" << std::endl;
    }
    else {
        std::cout << "Некорректный номер месяца" << std::endl;
    }
}

void Task5() {
    std::cout << "Решение задачи 5" << std::endl;
    std::cout << "Введите номер cпособа решения: " << std::endl;

    int taskNumber;
    std::cin >> taskNumber;

    switch (taskNumber) {
    case 1:
        Task5_1();
        break;
    case 2:
        Task5_2();
        break;
    default:
        std::cout << "Неверный номер задачи. Пожалуйста, попробуйте еще раз." << std::endl;
        Task5();
        return;
    }


}


void Task6() {
    int N;
    std::cout << "Введите число N: ";
    std::cin >> N;

    int sum = 0, even_count = 0, odd_count = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
        if (i % 2 == 0) {
            ++even_count;
        }
        else {
            ++odd_count;
        }
    }

    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Количество четных чисел: " << even_count << std::endl;
    std::cout << "Количество нечетных чисел: " << odd_count << std::endl;
}

void Task7() {
    int N;
    std::cout << "Введите число N: ";
    std::cin >> N;

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> divisors(N + 1, 2);
    divisors[1] = 1;
    for (int i = 2; i <= N / 2; ++i) {
        for (int j = 2 * i; j <= N; j += i) {
            ++divisors[j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        std::cout << i << " " << divisors[i] << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Время выполнения: " << diff.count() << " секунд." << std::endl;
}

//i need more coffee

void Task8() {
    int N, M;
    std::cout << "Введите числа N и M: ";
    std::cin >> N >> M;

    for (int a = N; a <= M; ++a) {
        for (int b = a; b <= M; ++b) {
            int c = sqrt(a * a + b * b);
            if (c <= M && c * c == a * a + b * b) {
                std::cout << a << " " << b << " " << c << std::endl;
            }
        }
    }
}

//pomogite ya ustal
void Task9() {
    int N, M;
    std::cout << "Введите числа N и M: ";
    std::cin >> N >> M;

    for (int i = N; i <= M; ++i) {
        int temp = abs(i);
        bool dividesDigits = true;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || i % digit != 0) {
                dividesDigits = false;
                break;
            }
            temp /= 10;
        }
        if (dividesDigits) {
           
            std::cout << i << std::endl;
        }
    }
}

void Task10() {
    int N;
    std::cout << "Введите число N: ";
    std::cin >> N;

    std::vector<int> perfect;
    for (int i = 2; perfect.size() < N; ++i) {
        int sum = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                sum += j;
                if (j * j != i) {
                    sum += i / j;
                }
            }
        }
        if (sum == i) {
            perfect.push_back(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << perfect[i] << std::endl;
    }

}

//help me

void Task11() {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };

    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << "Последний элемент массива (способ 1): " << arr[arr.size() - 1] << std::endl;
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Время выполнения способа 1: " << diff1.count() << " секунд." << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    std::cout << "Последний элемент массива (способ 2): " << arr.back() << std::endl;
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Время выполнения способа 2: " << diff2.count() << " секунд." << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    std::cout << "Последний элемент массива (способ 3): " << *(arr.end() - 1) << std::endl;
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    std::cout << "Время выполнения способа 3: " << diff3.count() << " секунд." << std::endl;
}

void Task12() {

    std::vector<int> arr = { 1, 2, 3, 4, 5 };

    std::reverse(arr.begin(), arr.end());

    std::cout << "Массив в обратном порядке: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int sum(const std::vector<int>& arr, int n) {
    if (n <= 0) {
        return 0;
    }
    else {
        return sum(arr, n - 1) + arr[n - 1];
    }
}

void Task13() {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::cout << "Сумма элементов массива: " << sum(arr, arr.size()) << std::endl;
}

//4:26 am 

void Task14() {
    std::cout << "Решение задачи 14" << std::endl;
    std::cout << "Введите номер cпособа решения:\n1 - рубли в доллары;  2 - доллары в рубли " << std::endl;


    int course;
    std::cin >> course;

    double rate;
    std::cout << "Введите курс обмена (рубли за 1 доллар): " << std::endl;
    std::cin >> rate;

    double dollars_to_convert;
    double rubles;
    double rubles_converted;
    double dollars;

    switch (course) {
    case 1:
        std::cout << "Введите сумму в рублях: ";
        std::cin >> rubles;

        dollars = rubles / rate;
        std::cout << "Сумма в долларах: " << dollars << std::endl;
        break;

    case 2:
        std::cout << "Введите сумму в долларах: ";
        std::cin >> dollars_to_convert;

        rubles_converted = dollars_to_convert * rate;
        std::cout << "Сумма в рублях: " << rubles_converted << std::endl;
        break;

    default:
        std::cout << "Некорректный ввод." << std::endl;
        return;
    }
}

//killme pls

void Task15() {
    int n, m;
    std::cout << "Введите размеры таблицы умножения (от 5 до 20): " << std::endl;
    std::cin >> n >> m;

    if (n < 5 || n > 20 || m < 5 || m > 20) {
        std::cout << "Размеры таблицы должны быть от 5 до 20." << std::endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int taskNumber;
    while (true) {

        std::cout << "Введите номер задачи:\n 0 - очистка\n ";
        std::cin >> taskNumber;

        switch (taskNumber) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        case 7:
            Task7();
            break;
        case 8:
            Task8();
            break;
        case 9:
            Task9();
            break;
        case 10:
            Task10();
            break;
        case 11:
            Task11();
            break;
        case 12:
            Task12();
            break;
        case 13:
            Task13();
            break;
        case 14:
            Task14();
            break;
        case 15:
            Task15();
            break;
        case 0:
            system("cls");

        default:
            std::cout << "Неверный номер задачи. Пожалуйста, попробуйте еще раз." << std::endl;
        }
    }
    return 0;
}
