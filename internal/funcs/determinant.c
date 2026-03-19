#include "../../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A->matrix == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;
  int flag = OK;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    double sum = 0;
    for (int i = 0; i < A->columns; i++) {
      int sign = (i % 2 == 0) ? 1 : -1;
      matrix_t dopMatrix;

      flag = minor_matrix(A, 0, i, &dopMatrix);
      double res;
      if (!flag) {
        flag = s21_determinant(&dopMatrix, &res);
        sum += A->matrix[0][i] * sign * res;
        s21_remove_matrix(&dopMatrix);
      }
    }
    *result = sum;
  }
  return flag;
}

int minor_matrix(matrix_t *A, int row, int column, matrix_t *result) {
  if (A->matrix == NULL || result == NULL) return INCORRECT_MATRIX;
  if (row < 0 || row >= A->rows || column < 0 || column >= A->columns)
    return CALC_ERROR;
  int flag = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  int m = 0;
  for (int i = 0; i < A->rows && !flag; i++) {
    if (i != row) {
      int n = 0;
      for (int j = 0; j < A->columns && !flag; j++) {
        if (j != column) {
          result->matrix[m][n] = A->matrix[i][j];
          n++;
        }
      }
      m++;
    }
  }
  return OK;
}
