#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_strlen(), test_memcpy(), test_memchr(), test_memcmp(), test_memset(), test_strncat(),
                             test_strchr(), test_strncmp(), test_strncpy(), test_strcspn(), test_strpbrk(), test_strrchr(),
                             test_strstr(), test_strtok(), test_to_upper(), test_to_lower(), test_trim(), test_insert(), 
                             test_sprintf_c(), test_sprintf_signed(), test_sprintf_e(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}