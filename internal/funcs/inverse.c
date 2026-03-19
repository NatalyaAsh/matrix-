#include "../../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double D;
  if (A->matrix == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;
  int flag = s21_determinant(A, &D);
  if (fabs(D) > EXP) {
    matrix_t C = {0}, Ct = {0}, A1 = {0};
    s21_calc_complements(A, &C);
    s21_transpose(&C, &Ct);
    double Dd = 1 / D;
    s21_mult_number(&Ct, Dd, &A1);
    *result = A1;
    s21_remove_matrix(&C);
    s21_remove_matrix(&Ct);
  } else {
    flag = 1;
  }
  return flag;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->matrix == NULL || result == NULL) return INCORRECT_MATRIX;
  int flag = s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
    flag = 1;
  }
  for (int i = 0; i < A->rows && !flag; i++) {
    for (int j = 0; j < A->columns && !flag; j++) {
      matrix_t dopMatrix;
      double res;
      int sign = ((i + j) % 2 == 0) ? 1 : -1;
      minor_matrix(A, i, j, &dopMatrix);
      s21_determinant(&dopMatrix, &res);
      result->matrix[i][j] = sign * res;
      s21_remove_matrix(&dopMatrix);
    }
  }
  return 0;
}
