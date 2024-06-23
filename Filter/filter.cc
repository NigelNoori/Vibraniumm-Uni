#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Allocates an m x n two-dimensional array of integers
int **allocate(int m, int n) {
    int **arr = new int *[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
    }
    return arr;
}

// Deallocates a two-dimensional array of integers with m rows
void deallocate(int **A, int m) {
    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;
}

// Reads a PGM image from the given file name and returns the dimensions
// and the image in a two-dimensional array.
bool read_image(const char *filename, int &m, int &n, int **&img) {
    ifstream is(filename, ios::binary);
    if (!is) {
        return false;
    }

    string s;

    is >> s;
    is >> n >> m >> s;
    is.ignore(1024, '\n');
    img = allocate(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j] = is.get();
        }
    }
    return true;
}

// Writes a PGM image to the given file name and prefix
bool write_image(const char *filename, int m, int n, int **img, const char *prefix) {
    string s = prefix;
    s += "-";
    s += filename;

    ofstream os(s.c_str(), ios::binary);
    if (!os) {
        return false;
    }
    os << "P5" << endl;
    os << n << " " << m << endl;
    os << 255 << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            os.put(static_cast<unsigned char>(img[i][j]));
        }
    }
    return true;
}

// Process the image with the appropriate filter
void process(int **img, int m, int n, int **output, int (*filter)(int A[5][5])) {
    int A[5][5];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < 2 || i >= m - 2 || j < 2 || j >= n - 2) {
                output[i][j] = 0;
            } else {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        A[k][l] = img[i - 2 + k][j - 2 + l];
                        output[i][j] = filter(A);
                    }
                }
            }
        }
    }
}

// Computes the average (rounded to the nearest integer) of the array
int average(int A[5][5]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            sum += A[i][j];
        }
    }
    return (sum + 12) / 25; // Round to the nearest integer
}

// Computes the median of the array
int median(int A[5][5]) {
    int flattened[25];
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            flattened[index++] = A[i][j];
        }
    }

    // Using std::sort for simplicity
    sort(flattened, flattened + 25);

    return flattened[12]; // Middle element of the sorted array
}

// Computes the strange function as given in the assignment
int strange(int A[5][5]) {
    return 255.0 * (2040 * (-A[1][1] - 2 * A[2][1] - A[3][1] + A[1][3] + 2 * A[2][3] + A[3][3] + 1020) + 0.5);
}
