#include <cassert>
#include <iostream>
#include <iomanip>

#include "myMatrix.h"

using namespace std;

CMatrix::CMatrix(unsigned int row, unsigned int col)
  :_row{row}, _col{col} {
  assert(_row > 0 && _col > 0);
  
  _Matrix = allocateMatrixMemory(_row, _col);

  for (unsigned int i = 0; i < _row; ++i) {
    for (unsigned int j = 0; j < _col; ++j) {
      _Matrix[i][j] = 0;
    }
  }
}

CMatrix::~CMatrix() {
  deallocateMatrixMemory(_Matrix, _row, _col);
}

unsigned int CMatrix::getRowDimension() {
  return _row;
}

unsigned int CMatrix::getColDimension() {
  return _col;
}

int CMatrix::getElementAt(unsigned int i, unsigned int j) {
  assert(0 < i);
  assert(i <= _row);
  assert(0 < j);
  assert(j <= _col);

  return _Matrix[i - 1][j - 1];
}

int CMatrix::replaceElementAt(unsigned int i, unsigned int j, int newValue) {
  int oldValue = getElementAt(i, j);
  _Matrix[i - 1][j - 1] = newValue;

  return oldValue;
}

int CMatrix::setElementAt(unsigned int i, unsigned int j) {
  return replaceElementAt(i, j, 1);
}

int CMatrix::clearElementAt(unsigned int i, unsigned int j) {
  return replaceElementAt(i, j, 0);
}

void CMatrix::swapElementsAt(int i1, int j1, int i2, int j2) {
  int tempInt = replaceElementAt(i1, j1, getElementAt(i2, j2));
  replaceElementAt(i2, j2, tempInt);
}

void CMatrix::resizeMatrix(unsigned int newRow, unsigned int newCol) {
  int** newMatrix = allocateMatrixMemory(newRow, newCol);

  for (unsigned int i = 0; i < newRow; ++i) {
     for (unsigned int j = 0; j < newCol; ++j) {
       newMatrix[i][j] = 0;
     }
  }

  deallocateMatrixMemory(_Matrix, _row, _col);

  _Matrix = newMatrix;
  _row = newRow;
  _col = newCol;
}

void CMatrix::readMatrix() {
  for (unsigned int i = 0; i < _row; ++i) {
    for (unsigned int j = 0; j < _col; ++j) {
      cout << "Input matrix element at ("
	   << i+1 << ", " << j+1 << "): ";
      cin >> _Matrix[i][j];
    }
  }
}

void CMatrix::printMatrix() {
  for (unsigned int i = 0; i < _row; ++i) {
    for (unsigned int j = 0; j < _col; ++j) {
      cout << setw(5) << right << _Matrix[i][j];
    }
    cout << endl;
  }
}

int** CMatrix::allocateMatrixMemory(unsigned int m, unsigned int n) {
  int** Matrix = new int*[m];

  for (unsigned int i = 0; i < m; ++i) {
    Matrix[i] = new int[n];
  }

  return Matrix;
}

void CMatrix::deallocateMatrixMemory(int** M, unsigned int m, unsigned n) {
  for (unsigned int i= 0; i < m; ++i) {
    delete[] M[i];
  }
  delete M;
}
