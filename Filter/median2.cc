#include <iostream>
#include <algorithm> // To use the sort function

// Function to increase the size of the array and copy elements
int *resize(int *A, int n) {
    // Create a new array with one more slot
    int *newArray = new int[n + 1];

    // Copy elements from the old array to the new array
    for (int i = 0; i < n; ++i) {
        newArray[i] = A[i];
    }

    // Delete the old array (to avoid memory leaks)
    delete[] A;

    // Return the pointer to the new array
    return newArray;
}

// Function to find the median of an array
double calculateMedian(int *A, int n) {
    // Sort the array in ascending order
    std::sort(A, A + n);

    // If the number of elements is even, find the average of the middle two
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
    int *arr = nullptr; // Pointer to an array, initially set to nullptr (no memory allocated)
    int size = 0;       // The size of the array, initially set to 0

    while (true) {
        // Ask the user to enter a positive integer
        std::cout << "Enter a positive integer (< 1 to quit): ";
        int num;
        std::cin >> num;

        // Check if the entered number is less than or equal to 0 to exit
        if (num <= 0) {
            std::cout << "Exiting the program.\n";
            break;
        }

        // Resize the array and copy the elements
        arr = resize(arr, size + 1);
        arr[size] = num;
        size++;

        // Display the median so far
        std::cout << "The median so far is " << calculateMedian(arr, size) << ".\n";
    }

    // Free the allocated memory before exiting the program
    delete[] arr;

    return 0;
}
