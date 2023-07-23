#include "s21_string.h"
#include <stdarg.h>

// Функция для копирования строки из src в dest
char *s21_strcpy(char *dest, const char *src) {
    char *dest_ptr = dest;
    while ((*dest_ptr++ = *src++)) {
        // Копируем символы из src в dest, пока не достигнем нуль-терминатора
    }
    return dest;
}

// Функция для преобразования целого числа в строку
char *s21_itoa(int num, char *buffer, int buffer_size) {
    int num_length = 0;
    int is_negative = 0;

    // Обработка отрицательных чисел
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    // Преобразуем число в строку (в обратном порядке)
    do {
        if (num_length < buffer_size - 1) {
            buffer[num_length++] = '0' + (num % 10);
        }
        num /= 10;
    } while (num > 0);

    // Добавляем знак минуса, если число было отрицательным
    if (is_negative && num_length < buffer_size - 1) {
        buffer[num_length++] = '-';
    }

    // Обратный порядок символов в строке
    for (int i = 0; i < num_length / 2; i++) {
        char tmp = buffer[i];
        buffer[i] = buffer[num_length - i - 1];
        buffer[num_length - i - 1] = tmp;
    }

    // Завершаем строку
    buffer[num_length] = '\0';

    return buffer;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int written = 0; // Количество символов, записанных в строку str

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Перейти к следующему символу после '%'

            // Обработка спецификатора %c
            if (*format == 'c') {
                char ch = (char)va_arg(args, int);
                str[written++] = ch;
            } else {
                // Неизвестный спецификатор, просто выводим его как есть
                str[written++] = '%';
                str[written++] = *format;
            }
        } else {
            str[written++] = *format;
        }

        format++;
    }

    str[written] = '\0'; // Завершаем строку

    va_end(args);
    return written;
}