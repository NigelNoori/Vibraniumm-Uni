#include <iostream>

#include "myMatrix.h"

using namespace std;

int main() {
  CMatrix matrix(4, 3);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  matrix.readMatrix();

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Element at (1, 1) is " << matrix.getElementAt(1, 1) << '\n';

  cout << "Replace element at (2, 3), which is " << matrix.replaceElementAt(2, 3, 44) << ", with 44." << endl;

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Set element at (1, 3), which is " << matrix.setElementAt(1, 3) << ", to 1." << endl;

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Clear element at (2, 3), which is " << matrix.clearElementAt(2, 3) << ", x making it 0." << endl;

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Swap elements at (3, 1) and (4, 3)." << endl;
  matrix.swapElementsAt(3, 1, 4, 3);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Resize the matrix to be 6 x 5." << endl;
  matrix.resizeMatrix(6, 5);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Change the elements at (1, 1), (1, 2), and (6, 5), which are "
       << matrix.replaceElementAt(1, 1, 2) << ", " << matrix.replaceElementAt(1, 2, 3)
       << ", and " << matrix.replaceElementAt(6, 5, 11)
       << " to be 2, 3, and 11, respectively.";


  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Resize the matrix to be 4 x 7." << endl;
  matrix.resizeMatrix(4, 7);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Change the elements at (2, 2), (2, 1), and (4, 7), which are "
       << matrix.replaceElementAt(2, 2, 4) << ", " << matrix.replaceElementAt(2, 1, 3)
       << ", and " << matrix.replaceElementAt(4, 7, 11)
       << " to be 4, 3, and 11, respectively.";


  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Resize the matrix to be 3 x 3." << endl;
  matrix.resizeMatrix(3, 3);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Resize the matrix to be 2 x 3." << endl;
  matrix.resizeMatrix(2, 3);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  cout << "Resize the matrix to be 1 x 1." << endl;
  matrix.resizeMatrix(1, 1);

  cout << "Matrix size = "
       << matrix.getRowDimension() << " x "
       << matrix.getColDimension() << '\n';
  matrix.printMatrix();
  cout << endl;

  return 0;
}
