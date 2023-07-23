#include "../s21_string.h"

// Функция для преобразования символа в нижний регистр (для английского алфавита)
char s21_char_to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        // Если символ является заглавной буквой, преобразуем его в строчную
        return ch + ('a' - 'A');
    } else {
        // Иначе возвращаем символ без изменений
        return ch;
    }
}

// Функция для преобразования строки в нижний регистр
void *s21_to_lower(const char *str) {
    if (str == s21_NULL) {
        return s21_NULL; // Обработка случая с NULL
    }

    s21_size_t length = s21_strlen(str);
    char *result = malloc(length + 1); // Выделение памяти для новой строки (плюс один байт для нуль-терминатора)
    if (result == s21_NULL) {
        return s21_NULL; // Обработка ошибки выделения памяти
    }

    char *result_ptr = result;

    while (*str != '\0') {
        *result_ptr = s21_char_to_lower(*str);
        str++;
        result_ptr++;
    }

    *result_ptr = '\0'; // Добавляем нуль-терминатор в конец новой строки

    return result;
}