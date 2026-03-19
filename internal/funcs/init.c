#include "../../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int init = OK;
  if (rows <= 0 || columns <= 0)
    init = CALC_ERROR;
  else if (result == NULL)
    init = INCORRECT_MATRIX;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      init = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows && !init; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) init = 1;
      }
    }
  }
  if (init == 1) s21_remove_matrix(result);
  return init;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) free(A->matrix[i]);
    }
    free(A->matrix);
  }
}
