#include <iostream>
#include <algorithm>

void sort(int *A, int n) {
    // Using std::sort for sorting the array in ascending order
    std::sort(A, A + n);
}

double median(int *A, int n) {
    // If the number of elements is even, return the average of the middle two elements
    if (n % 2 == 0) {
        int mid1 = A[n / 2 - 1];
        int mid2 = A[n / 2];
        return (static_cast<double>(mid1 + mid2)) / 2.0;
    } else {
        // If the number of elements is odd, return the middle element
        return static_cast<double>(A[n / 2]);
    }
}

int main() {
    int n;

    while (true) {
        // Asking the user to enter the size of the list
        std::cout << "Enter the size of the list (< 1 to quit): ";
        std::cin >> n;

        // Check for the exit condition
        if (n < 1) {
            std::cout << "Exiting the program.\n";
            break;
        }

        // Dynamically allocate an array of n elements
        int *arr = new int[n];

        // Asking the user to enter elements
        for (int i = 0; i < n; ++i) {
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> arr[i];
        }

        // Sorting the array
        sort(arr, n);

        // Displaying the median
        std::cout << "The median is " << median(arr, n) << ".\n";

        // Freeing the allocated memory
        delete[] arr;
    }

    return 0;
}
