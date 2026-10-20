#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // не работает #include <locale.h>

int check_char_type(char c);
double calculate_expression(float x, char op, float y);
int get_day_of_week(int jan1, int k);

int main() {
    SetConsoleOutputCP(65001);
    char c, op;
    float a, b;
    int jan1, k;

    //  Задание 1 
    printf("ЗАДАНИЕ 1: Определение символа\nВведите символ: ");
    scanf(" %c", &c);
    int type = check_char_type(c);
    if (type == 1) {
        printf("Это цифра\n\n");
    }
    else if (type == 2) {
        printf("Это буква\n\n");
    }
    else {
        printf("Неизвестный символ\n\n");
    }

    //  Задание 2 
    printf("ЗАДАНИЕ 2: Калькулятор\nВведите выражение (например, 5+3 или 2^3): ");
    scanf("%f%c%f", &a, &op, &b);
    printf("= %f\n\n", calculate_expression(a, op, b));

    //  Задание 3 (Вариант 6) 
    printf("ЗАДАНИЕ 3: Определение дня недели\nВведите день недели 1 января (1-Пн, ..., 7-Вс): ");
    scanf("%d", &jan1);
    printf("Введите номер дня в году k (1-365): ");
    scanf("%d", &k);

    int result_day = get_day_of_week(jan1, k);
    if (result_day != -1) {
        printf("День недели для %d-го дня года: %d\n", k, result_day);
    }
    else {
        printf("Ошибка: некорректные данные!\n");
    }

    return 0;
}


//  Задание 1 
int check_char_type(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
        return 2;
    }
    return 0;
}

//  Задание 2 
double calculate_expression(float x, char op, float y) {
    double result = 0.0;

    switch (op) {
    case '+': result = x + y; break;
    case '-': result = x - y; break;
    case '*': result = x * y; break;
    case '/':
        if (y != 0) result = x / y;
        else printf("Ошибка: деление на ноль! ");
        break;
    case '^': {
        result = 1.0;
        int power = (int)y;
        if (power == 0) result = 1.0;
        else if (power > 0) {
            for (int i = 0; i < power; i++) result *= x;
        }
        else {
            for (int i = 0; i > power; i--) result /= x;
        }
        break;
    }
    default:
        printf("Неизвестная операция! ");
        break;
    }
    return result;
}

//  Задание 3 (Вариант 6) 
int get_day_of_week(int jan1, int k) {
    if (k < 1 || k > 365 || jan1 < 1 || jan1 > 7) {
        return -1;
    }
    return ((jan1 - 1 + (k - 1)) % 7) + 1;
}