#include "tests.h"

START_TEST(test_add_1) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 2;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_add_2) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_add_3) {
  matrix_t A, B, C = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_sub_4) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 2;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  ck_assert_int_eq(s21_sub_matrix(&B, &A, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_sub_5) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_sub_6) {
  matrix_t A, B, C = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_eq_7) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_8) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_9) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 2;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transponse_10) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &B), FAILURE);
  ck_assert_int_eq(A.matrix[0][2], B.matrix[2][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *add_test() {
  Suite *s = suite_create(
      "\033[32mS21_ADD, S21_SUB, S21_TRANSPOSE, S21_EQ_MATRIX\033[0m");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_add_1);
  tcase_add_test(tc, test_add_2);
  tcase_add_test(tc, test_add_3);
  tcase_add_test(tc, test_sub_4);
  tcase_add_test(tc, test_sub_5);
  tcase_add_test(tc, test_sub_6);
  tcase_add_test(tc, test_eq_7);
  tcase_add_test(tc, test_eq_8);
  tcase_add_test(tc, test_eq_9);
  tcase_add_test(tc, test_transponse_10);

  suite_add_tcase(s, tc);
  return s;
}