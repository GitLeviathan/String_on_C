#include "../s21_string.h"

// Функция для преобразования символа в верхний регистр (для английского алфавита)
char s21_char_to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        // Если символ является строчной буквой, преобразуем его в верхний регистр
        return ch - ('a' - 'A');
    } else {
        // Иначе возвращаем символ без изменений
        return ch;
    }
}

void *s21_to_upper(const char *str) {
    if (str == s21_NULL) {
        return s21_NULL; // Обработка случая с NULL
    }
    char *result = malloc(s21_strlen(str) + 1); // Выделение памяти для новой строки (плюс один байт для нуль-терминатора)
    if (result == s21_NULL) {
        return s21_NULL; // Обработка ошибки выделения памяти
    }
    char *result_ptr = result; // Указатель на результат (новую строку)
    while (*str != '\0') {
        *result_ptr = s21_char_to_upper(*str);
        str++;
        result_ptr++;
    }
    *result_ptr = '\0'; // Добавляем нуль-терминатор в конец строки
    return result;
}