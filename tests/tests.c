#include "tests.h"

int main() {
  int failed = 0, res = 0;
  Suite *s21_matrix_test[] = {init_test(),   add_test(),     all_test(),
                              determ_test(), inverse_test(), NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = NULL;
    sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    // failed += srunner_ntests_failed(sr);
    res = srunner_ntests_failed(sr);
    failed += res;
    if (res == 0)
      printf("\033[32m✔\033[0m\n");
    else
      printf("\033[35m❌\033[0m\n");
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}