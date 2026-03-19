#include "tests.h"

START_TEST(test_init_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_init_2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(7, 4, &A), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_free_3) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(test_free_4) {
  matrix_t A = {0};
  s21_remove_matrix(&A);
}
END_TEST

Suite *init_test() {
  Suite *s = suite_create("\033[32mS21_CREATE, S21_Remove\033[0m");
  TCase *tc = tcase_create("init_tc");

  tcase_add_test(tc, test_init_1);
  tcase_add_test(tc, test_init_2);
  tcase_add_test(tc, test_free_3);
  tcase_add_test(tc, test_free_4);

  suite_add_tcase(s, tc);
  return s;
}