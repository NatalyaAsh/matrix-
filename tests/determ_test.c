#include "tests.h"

START_TEST(test_minor_1) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  minor_matrix(&A, 1, 1, &B);
  ck_assert_int_eq(B.matrix[0][0], A.matrix[0][0]);
  ck_assert_int_eq(B.matrix[0][1], A.matrix[0][2]);
  ck_assert_int_eq(B.matrix[1][0], A.matrix[2][0]);
  ck_assert_int_eq(B.matrix[1][1], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_minor_2) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  minor_matrix(&A, 2, 2, &B);
  ck_assert_int_eq(B.matrix[0][0], A.matrix[0][0]);
  ck_assert_int_eq(B.matrix[0][1], A.matrix[0][1]);
  ck_assert_int_eq(B.matrix[1][0], A.matrix[1][0]);
  ck_assert_int_eq(B.matrix[1][1], A.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_minor_3) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  minor_matrix(&A, 0, 0, &B);
  ck_assert_int_eq(B.matrix[0][0], A.matrix[1][1]);
  ck_assert_int_eq(B.matrix[0][1], A.matrix[1][2]);
  ck_assert_int_eq(B.matrix[1][0], A.matrix[2][1]);
  ck_assert_int_eq(B.matrix[1][1], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_minor_4) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  minor_matrix(&A, 0, 1, &B);
  ck_assert_int_eq(B.matrix[0][0], A.matrix[1][0]);
  ck_assert_int_eq(B.matrix[0][1], A.matrix[1][2]);
  ck_assert_int_eq(B.matrix[1][0], A.matrix[2][0]);
  ck_assert_int_eq(B.matrix[1][1], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_5) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  A.matrix[0][0] = 6;
  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_6) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, -3);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_7) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  double res;
  s21_determinant(&A, &res);
  printf("determ: %f\n", res);
  // print_matrix(&A);
  // minor(&A, 0, 0, &B);
  // ck_assert_int_eq(s21_sum_matrix(&A, &B, &C),0);
  // printf("minor:\n");
  // print_matrix(&B);
  // ck_assert_int_eq(B.matrix[0][0], A.matrix[1][1]);
  // ck_assert_int_eq(B.matrix[0][1], A.matrix[1][2]);
  // ck_assert_int_eq(B.matrix[1][0], A.matrix[2][1]);
  // ck_assert_int_eq(B.matrix[1][1], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_8) {
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
  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_9) {
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
  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, -7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_10) {
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
  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 69);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_11) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = -1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = -1;
  A.matrix[2][3] = 2;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 1;
  A.matrix[3][3] = 1;

  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, -20);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_determ_12) {
  matrix_t A, B = {0};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), 0);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = -2;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = -2;
  A.matrix[1][2] = 5;
  A.matrix[1][3] = 1;
  A.matrix[1][4] = 3;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = -1;
  A.matrix[2][4] = 2;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = -1;
  A.matrix[3][4] = -5;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = 0;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 2;

  double res;
  s21_determinant(&A, &res);
  ck_assert_int_eq(res, 48);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *determ_test() {
  Suite *s = suite_create("\033[3mS21_DETERMINANT\033[0m");
  TCase *tc = tcase_create("determ_tc");

  tcase_add_test(tc, test_minor_1);
  tcase_add_test(tc, test_minor_2);
  tcase_add_test(tc, test_minor_3);
  tcase_add_test(tc, test_minor_4);
  tcase_add_test(tc, test_determ_5);
  tcase_add_test(tc, test_determ_6);
  tcase_add_test(tc, test_determ_7);
  tcase_add_test(tc, test_determ_8);
  tcase_add_test(tc, test_determ_9);
  tcase_add_test(tc, test_determ_10);
  tcase_add_test(tc, test_determ_11);
  tcase_add_test(tc, test_determ_12);

  suite_add_tcase(s, tc);
  return s;
}