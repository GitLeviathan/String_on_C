#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int check = 0, res = 0;
  for (; str1[res] != '\0'; res++) {
    check = 0;
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[res] == str2[j]) check = 1;
    }
    if (check == 0) break;
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p = s21_NULL;
  int flag = 0;
  if (str) {
    p = str;
  }
  if (p) {
    str = p + s21_strspn(p, delim);
    p = str + s21_strcspn(str, delim);
    if (p == str) {
      p = s21_NULL;
      flag = 1;
    } else {
      p = *p ? *p = 0, p + 1 : 0;
    }
  }
  return flag == 1 ? s21_NULL : str;
}
