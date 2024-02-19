#ifndef CMATRIX_H
#define CMATRIX_H


class CMatrix {
 public:
  /**
  * Default constructor
  * Parameters:
  *   row the number of rows in the matrix, default value is 1.
  *   col the number of columns in the matrix, default balue is 1.
  * Assert: Aborts the program if row and column are not positive integers.
  */
  CMatrix(unsigned int row = 1, unsigned int col = 1);

  /**
  * Default destructor
  */
  virtual ~CMatrix();

  /**
  * Access the number of rows.
  * Returns: the number of rows.
  */
  unsigned int getRowDimension();

  /**
  * Access the number of columns.
  * Returns: the number of columns.
  */
  unsigned int getColDimension();

  /**
  * Access the element at (i, j).
  * Return: element at (i, j).
  * Assert: Aborts the program if the indices are not within the valid range.
  */
  int getElementAt(unsigned int i, unsigned int j);

  /**
  * Set an element of the matrix to a new value.
  * Parameters:
  *   i the row of the element to change
  *   j the column of the element to change
  *   newint the value new element
  * Return: the value of the old element.
  * Assert: Aborts the program if the indices are not within the valid range.
  */
  int replaceElementAt(unsigned int i, unsigned int j, int newint);

  /**
  * Set an element of the matrix to 1.
  * Parameters:
  *   i the row of the element to change
  *   j the column of the element to change
  * Return: the old value of the element.
  * Assert: Aborts the program if the indices are not within the valid range.
  */
  int setElementAt(unsigned int i, unsigned int j);

  /**
  * Set an element of the matrix to 0.
  * Parameters:
  *   i the row of the element to change
  *   j the column of the element to change
  * Return: the value of the old element.
  * Assert: Aborts the program if the indices are not within the valid range.
  */
  int clearElementAt(unsigned int i, unsigned int j);

  /**
  * Swaps the values of two elements in the matrix.
  * Parameters:
  *   i1 the row of the first element
  *   j1 the column of the first element
  *   i2 the row of the first element
  *   j2 the column of the first element
  * Assert: Aborts the program if the indices are not within the valid range.
  */
  void swapElementsAt(int i1, int j1, int i2, int j2);

  /**
   * Resizes the matrix and clears all entries.
   * Parameters:
   *   newRow the new number of rows
   *   newCol the new number of cols
   */
  void resizeMatrix(unsigned int newRow, unsigned int newCol);

  /**
  * Reads n x n elements from standard input and saves them in the matrix.
  */
  void readMatrix();

  /**
  * Writes the matrix to standard output.
  */
  void printMatrix();

 private:
  /**
  * Creates a matrix by allocating memory for a 2 dimensional dynamic array.
  * Parameters:
  *   row the number of rows in the matrix.
  *   col the number of columns in the matrix.
  * Return : a 2 dimensional dynamic array
  */
  int** allocateMatrixMemory(unsigned int m, unsigned int n);

  /**
  * Destroys an 2 dimensional matrix by deallocating the memory used
  * to store it in a dynamic array.
  * Parameters:
  * Parameters:
  *   Matrix a two dimensional dynamic array
  *   row the number of rows in the matrix, default value is 1.
  *   col the number of columns in the matrix, default value is 1.
  */
  void deallocateMatrixMemory(int** M, unsigned int m, unsigned int n);

  int** _Matrix;
  unsigned int _row;
  unsigned int _col;
};

#endif // CMATRIX_H
