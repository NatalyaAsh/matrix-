#include <check.h>

#include "../s21_matrix.h"

START_TEST(test_create_matrix_success) {
  matrix_t m;
  int code = s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(code, 0);
  ck_assert_ptr_ne(m.matrix, NULL);
  ck_assert_int_eq(m.rows, 3);
  ck_assert_int_eq(m.columns, 3);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_matrix_invalid) {
  matrix_t m = {0};
  int code = s21_create_matrix(-5, 2, &m);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_matrix_invalid_2) {
  int code = s21_create_matrix(2, 2, NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid_3) {
  matrix_t m = {0};
  int code = s21_create_matrix(2, -2, &m);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_eq_matrix_equal) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000001;
  A.matrix[1][0] = 3.0000001;
  A.matrix[1][1] = 4.0000001;

  B.matrix[0][0] = 1.0000002;
  B.matrix[0][1] = 2.0000002;
  B.matrix[1][0] = 3.0000002;
  B.matrix[1][1] = 4.0000002;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_not_equal_1) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.000001;
  A.matrix[0][1] = 2.000001;
  A.matrix[1][0] = 3.000001;
  A.matrix[1][1] = 4.000001;

  B.matrix[0][0] = 1.000002;
  B.matrix[0][1] = 2.000002;
  B.matrix[1][0] = 3.000002;
  B.matrix[1][1] = 4.000002;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_not_equal) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_diff_size) {
  matrix_t A, B;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_diff_size_2) {
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix) {
  matrix_t A, B, C, res = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[1][0] = 6;
  C.matrix[1][1] = 8;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 0);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_matrix_error) {
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(test_sum_matrix_error_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_sum_matrix_error_3) {
  matrix_t A, B, res = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_matrix_error_4) {
  matrix_t A, B, res = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_matrix_error_5) {
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_6) {
  matrix_t A, B, res = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_matrix) {
  matrix_t A, B, C, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0;
  C.matrix[1][0] = 0;
  C.matrix[1][1] = 0;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 0);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_matrix_error) {
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(test_sub_matrix_error_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_sub_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_sub_matrix_error_3) {
  matrix_t A, B, res = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_matrix_error_4) {
  matrix_t A, B, res = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_matrix_error_5) {
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_error_6) {
  matrix_t A, B, res = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 5, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number) {
  matrix_t A, C, res = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[1][0] = 6;
  C.matrix[1][1] = 8;

  ck_assert_int_eq(s21_mult_number(&A, 2, &res), 0);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number_error) {
  ck_assert_int_eq(s21_mult_number(NULL, 2, NULL), 1);
}
END_TEST

START_TEST(test_mult_number_error_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_mult_number(&A, 2, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_matrix) {
  matrix_t A, B, C, res = {0};

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 9;
  C.matrix[0][1] = 11;
  C.matrix[0][2] = 17;
  C.matrix[1][0] = 12;
  C.matrix[1][1] = 13;
  C.matrix[1][2] = 22;
  C.matrix[2][0] = 15;
  C.matrix[2][1] = 15;
  C.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_matrix_2) {
  matrix_t A, B, C, res = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;

  s21_create_matrix(2, 1, &C);
  C.matrix[0][0] = 21;
  C.matrix[1][0] = 48;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_error) {
  matrix_t A, B, res = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;
  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;
  ck_assert_int_eq(s21_mult_matrix(&B, &A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_error_2) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;
  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;
  ck_assert_int_eq(s21_mult_matrix(&B, &A, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_error_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_error_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;
  ck_assert_int_eq(s21_mult_matrix(NULL, &A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_matrix) {
  matrix_t A, C, res = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 2;
  C.matrix[0][2] = 3;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose_matrix_2) {
  matrix_t A, C, res = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 2;
  C.matrix[0][2] = 3;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&C, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &A), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose_error) {
  matrix_t A;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_error_2) {
  matrix_t res;
  ck_assert_int_eq(s21_transpose(NULL, &res), 1);
}
END_TEST

START_TEST(test_determinant_1) {
  matrix_t A;
  double res = 0, original = -2;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_int_eq(res, original);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2) {
  matrix_t A;
  double res = 0, original = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_int_eq(res, original);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t A;
  double res = 0, original = 3;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_int_eq(res, original);
  s21_remove_matrix(&A);
}
END_TEST

Suite *all_test() {
  Suite *s = suite_create("\033[32mS21_MULT, ALL\033[0m");
  TCase *tc = tcase_create("all_tc");

  tcase_add_test(tc, test_create_matrix_success);
  tcase_add_test(tc, test_create_matrix_invalid);
  tcase_add_test(tc, test_create_matrix_invalid_2);
  tcase_add_test(tc, test_create_matrix_invalid_3);

  tcase_add_test(tc, test_eq_matrix_equal);
  tcase_add_test(tc, test_eq_matrix_not_equal_1);
  tcase_add_test(tc, test_eq_matrix_not_equal);
  tcase_add_test(tc, test_eq_matrix_diff_size);
  tcase_add_test(tc, test_eq_matrix_diff_size_2);

  tcase_add_test(tc, test_sum_matrix);
  tcase_add_test(tc, test_sum_matrix_error);
  tcase_add_test(tc, test_sum_matrix_error_2);
  tcase_add_test(tc, test_sum_matrix_error_3);
  tcase_add_test(tc, test_sum_matrix_error_4);
  tcase_add_test(tc, test_sum_matrix_error_5);
  tcase_add_test(tc, test_sum_matrix_error_6);

  tcase_add_test(tc, test_sub_matrix);
  tcase_add_test(tc, test_sub_matrix_error);
  tcase_add_test(tc, test_sub_matrix_error_2);
  tcase_add_test(tc, test_sub_matrix_error_3);
  tcase_add_test(tc, test_sub_matrix_error_4);
  tcase_add_test(tc, test_sub_matrix_error_5);
  tcase_add_test(tc, test_sub_matrix_error_6);

  tcase_add_test(tc, test_mult_number);
  tcase_add_test(tc, test_mult_number_error);
  tcase_add_test(tc, test_mult_number_error_2);
  tcase_add_test(tc, test_mult_matrix);
  tcase_add_test(tc, test_mult_matrix_2);
  tcase_add_test(tc, test_mult_error);
  tcase_add_test(tc, test_mult_error_2);
  tcase_add_test(tc, test_mult_error_3);
  tcase_add_test(tc, test_mult_error_4);

  tcase_add_test(tc, test_transpose_matrix);
  tcase_add_test(tc, test_transpose_matrix_2);
  tcase_add_test(tc, test_transpose_error);
  tcase_add_test(tc, test_transpose_error_2);

  tcase_add_test(tc, test_determinant_1);
  tcase_add_test(tc, test_determinant_2);
  tcase_add_test(tc, test_determinant_3);

  suite_add_tcase(s, tc);
  return s;
}
