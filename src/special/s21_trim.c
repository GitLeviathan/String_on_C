#include "../s21_string.h"
#include <stdlib.h>

void *s21_trim(const char *src, const char *trim_chars) {
       if (src == s21_NULL) {
        return s21_NULL; // Обработка случая с NULL
    }

    if (trim_chars == s21_NULL) {
        // Если trim_chars равен NULL, возвращаем копию исходной строки
        s21_size_t length = s21_strlen(src);
        char *result = malloc(length + 1); // Выделение памяти для новой строки (плюс один байт для нуль-терминатора)
        if (result == s21_NULL) {
            return s21_NULL; // Обработка ошибки выделения памяти
        }
        char *s = s21_strncpy(result, src);
        
        return result;
    }

    s21_size_t length = s21_strlen(src);
    const char *start = src;
    const char *end = src + length - 1;

    // Находим начало исходной строки без ведущих символов из trim_chars
    while (*start != '\0' && s21_strchr(trim_chars, *start) != NULL) {
        start++;
    }

    // Находим конец исходной строки без завершающих символов из trim_chars
    while (end >= start && s21_strchr(trim_chars, *end) != NULL) {
        end--;
    }

    // Вычисляем длину обрезанной строки
    size_t trimmed_length = end - start + 1;

    // Копируем обрезанную строку в новый буфер
    void *result = malloc(trimmed_length + 1);
    if (result == NULL) {
        return NULL; // Обработка ошибки выделения памяти
    }

    s21_memcpy(result, start, trimmed_length);
    ((char *)result)[trimmed_length] = '\0'; // Добавляем нуль-терминатор в конец обрезанной строки

    return result;
}