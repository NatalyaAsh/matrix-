#include "tests.h"

START_TEST(test_comp_1) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &B), 0);
  ck_assert_int_eq(B.matrix[0][0], 4);
  ck_assert_int_eq(B.matrix[0][1], -3);
  ck_assert_int_eq(B.matrix[1][0], -2);
  ck_assert_int_eq(B.matrix[1][1], 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_comp_2) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  A.matrix[0][0] = 6;
  ck_assert_int_eq(s21_calc_complements(&A, &B), 0);
  ck_assert_int_eq(B.matrix[0][0], 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_comp_3) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;
  s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], -24);
  ck_assert_int_eq(B.matrix[0][1], 20);
  ck_assert_int_eq(B.matrix[0][2], -5);
  ck_assert_int_eq(B.matrix[1][0], 18);
  ck_assert_int_eq(B.matrix[1][1], -15);
  ck_assert_int_eq(B.matrix[1][2], 4);
  ck_assert_int_eq(B.matrix[2][0], 5);
  ck_assert_int_eq(B.matrix[2][1], -4);
  ck_assert_int_eq(B.matrix[2][2], 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_comp_4) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = -1;
  s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], -1);
  ck_assert_int_eq(B.matrix[0][1], 5);
  ck_assert_int_eq(B.matrix[0][2], -1);
  ck_assert_int_eq(B.matrix[1][0], -1);
  ck_assert_int_eq(B.matrix[1][1], -2);
  ck_assert_int_eq(B.matrix[1][2], -1);
  ck_assert_int_eq(B.matrix[2][0], -2);
  ck_assert_int_eq(B.matrix[2][1], -4);
  ck_assert_int_eq(B.matrix[2][2], 5);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_comp_5) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 5;
  s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], 17);
  ck_assert_int_eq(B.matrix[0][1], -11);
  ck_assert_int_eq(B.matrix[0][2], 1);
  ck_assert_int_eq(B.matrix[1][0], 2);
  ck_assert_int_eq(B.matrix[1][1], 19);
  ck_assert_int_eq(B.matrix[1][2], -8);
  ck_assert_int_eq(B.matrix[2][0], -3);
  ck_assert_int_eq(B.matrix[2][1], 6);
  ck_assert_int_eq(B.matrix[2][2], 12);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_comp_6) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = -1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;
  A.matrix[3][0] = 2;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 1;
  s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], -6);
  ck_assert_int_eq(B.matrix[0][1], 9);
  ck_assert_int_eq(B.matrix[0][2], 3);
  ck_assert_int_eq(B.matrix[0][3], 3);
  ck_assert_int_eq(B.matrix[1][0], 7);
  ck_assert_int_eq(B.matrix[1][1], -3);
  ck_assert_int_eq(B.matrix[1][2], -5);
  ck_assert_int_eq(B.matrix[1][3], 1);
  ck_assert_int_eq(B.matrix[2][0], -5);
  ck_assert_int_eq(B.matrix[2][1], 6);
  ck_assert_int_eq(B.matrix[2][2], 1);
  ck_assert_int_eq(B.matrix[2][3], 7);
  ck_assert_int_eq(B.matrix[3][0], -3);
  ck_assert_int_eq(B.matrix[3][1], 0);
  ck_assert_int_eq(B.matrix[3][2], 6);
  ck_assert_int_eq(B.matrix[3][3], -3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_inverse_7) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 0);
  ck_assert_int_eq(B.matrix[0][0], -1.5);
  ck_assert_int_eq(B.matrix[0][1], 0.5);
  ck_assert_int_eq(B.matrix[1][0], 1.25);
  ck_assert_int_eq(B.matrix[1][1], -0.25);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_inverse_8) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_inverse_9) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 4;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 0);
  ck_assert_int_eq(B.matrix[0][0], -2);
  ck_assert_int_eq(B.matrix[0][1], -1);
  ck_assert_int_eq(B.matrix[0][2], 2);
  ck_assert_int_eq(B.matrix[1][0], 2);
  ck_assert_int_eq(B.matrix[1][1], -1);
  ck_assert_int_eq(B.matrix[1][2], -1);
  ck_assert_int_eq(B.matrix[2][0], 1);
  ck_assert_int_eq(B.matrix[2][1], 1);
  ck_assert_int_eq(B.matrix[2][2], -1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_inverse_10) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[1][1] = 5;
  A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 0);
  ck_assert_int_eq(B.matrix[0][0], 1);
  ck_assert_int_eq(B.matrix[0][1], 0);
  ck_assert_int_eq(B.matrix[0][2], 0);
  ck_assert_int_eq(B.matrix[1][0], 0);
  ck_assert_int_eq(B.matrix[1][1], 0.2);
  ck_assert_int_eq(B.matrix[1][2], 0);
  ck_assert_int_eq(B.matrix[2][0], 0);
  ck_assert_int_eq(B.matrix[2][1], 0);
  ck_assert_int_eq(B.matrix[2][2], 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *inverse_test() {
  Suite *s =
      suite_create("\033[32mS21_CALC_COPLEMENTS, S21_INVERSE_MATRIX\033[0m");
  TCase *tc = tcase_create("inverse_tc");

  tcase_add_test(tc, test_comp_1);
  tcase_add_test(tc, test_comp_2);
  tcase_add_test(tc, test_comp_3);
  tcase_add_test(tc, test_comp_4);
  tcase_add_test(tc, test_comp_5);
  tcase_add_test(tc, test_comp_6);
  tcase_add_test(tc, test_inverse_7);
  tcase_add_test(tc, test_inverse_8);
  tcase_add_test(tc, test_inverse_9);
  tcase_add_test(tc, test_inverse_10);

  suite_add_tcase(s, tc);
  return s;
}