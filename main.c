/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result);
void sub(int *buff1, int len1, int *buff2, int len2, int *result);
void print_result(int *result, int len);
int compare(int *buff1, int len1, int *buff2, int len2);
int input_number(int *buff, int max_len);

int main() {
    int num1[LEN], num2[LEN], result[LEN + 1];
    int len1, len2;

    // Ввод первого числа
    len1 = input_number(num1, LEN);
    if (len1 == -1) {
        printf("n/a\n");
        return 1;
    }

    // Ввод второго числа
    len2 = input_number(num2, LEN);
    if (len2 == -1) {
        printf("n/a\n");
        return 1;
    }

    // Сложение
    sum(num1, len1, num2, len2, result);
    print_result(result, len1 > len2 ? len1 : len2);

    // Вычитание
    if (compare(num1, len1, num2, len2) >= 0) {
        sub(num1, len1, num2, len2, result);
        print_result(result, len1);
    } else {
        printf("n/a\n");
    }

    return 0;
}

// Функция для ввода массива числа через пробелы
int input_number(int *buff, int max_len) {
    int len = 0;
    int num;
    char ch;

    while (1) {
        if (scanf("%d%c", &num, &ch) != 2 || num < 0 || num > 9) {
            return -1; // Ошибка ввода
        }
        if (len < max_len) {
            buff[len++] = num;
        } else {
            return -1; // Переполнение
        }
        if (ch == '\n' || ch == EOF) {
            break; // Конец ввода
        }
    }
    return len;
}

// Функция для сложения двух чисел, представленных в виде массивов цифр
void sum(int *buff1, int len1, int *buff2, int len2, int *result) {
    int carry = 0; // Переменная для хранения переноса
    int i = len1 - 1; // Индекс для обхода первого массива с конца
    int j = len2 - 1; // Индекс для обхода второго массива с конца
    int k = (len1 > len2 ? len1 : len2); // Индекс для записи результата

    result[k] = 0; // Начальная позиция для возможного переноса

    // Проходим по обоим массивам, начиная с последнего элемента
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; // Начинаем с переноса от предыдущей операции

        if (i >= 0) sum += buff1[i--]; // Добавляем текущую цифру из первого массива
        if (j >= 0) sum += buff2[j--]; // Добавляем текущую цифру из второго массива

        result[k--] = sum % 10; // Записываем последнюю цифру суммы в результат
        carry = sum / 10; // Обновляем перенос для следующей операции
    }

    // Если был перенос на последнюю позицию, сдвигаем результат
    if (carry) {
        result[k] = carry;
    } else {
        // Если переноса нет, то перемещаем результат влево на 1 позицию
        for (int m = 0; m < (len1 > len2 ? len1 : len2); m++) {
            result[m] = result[m + 1];
        }
    }
}

// Функция для вычитания
void sub(int *buff1, int len1, int *buff2, int len2, int *result) {
    int borrow = 0;
    int i = len1 - 1, j = len2 - 1, k = len1 - 1;

    while (i >= 0) {
        int diff = buff1[i] - borrow - (j >= 0 ? buff2[j] : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k--] = diff;
        i--; j--;
    }
}

// Сравнение двух чисел (для определения порядка при вычитании)
int compare(int *buff1, int len1, int *buff2, int len2) {
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    for (int i = 0; i < len1; i++) {
        if (buff1[i] > buff2[i]) return 1;
        if (buff1[i] < buff2[i]) return -1;
    }
    return 0;
}

// Функция для печати результата через пробел
void print_result(int *result, int len) {
    int start = 0;
    while (start < len && result[start] == 0) start++; // Пропуск ведущих нулей

    if (start == len) {
        printf("0\n");
    } else {
        for (int i = start; i < len; i++) {
            if (i > start) printf(" "); // Добавляем пробел между цифрами
            printf("%d", result[i]);
        }
        printf("\n");
    }
}
