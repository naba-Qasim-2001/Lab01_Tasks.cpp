//Task 01: resizeArray
#include <iostream>
using namespace std;

// Returns a new array of double size:
// first half = original, second half = 2 x original
int* resizeArray(int inArray[], const int size) {
    int* newArray = new int[size * 2];
    for (int i = 0; i < size; i++) {
        newArray[i] = inArray[i];
        newArray[i + size] = inArray[i] * 2;
    }
    return newArray;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    int* resized = resizeArray(arr, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++) {
        cout << resized[i];
        if (i < size * 2 - 1) cout << ", ";
    }
    cout << endl;

    delete[] arr;      // avoid memory leaks
    delete[] resized;
    arr = resized = nullptr;  // avoid dangling pointers
    return 0;
}

Task 02: Diagonal Matrix
cpp
#include <iostream>
using namespace std;

// Returns true if all entries outside the main diagonal are zero
bool isDiagonal(int** m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && m[i][j] != 0)
                return false;
    return true;
}

int main() {
    int n;
    cout << "Enter size of the square matrix: ";
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) matrix[i] = new int[n];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    if (isDiagonal(matrix, n))
        cout << "The matrix is a diagonal matrix." << endl;
    else
        cout << "The matrix is NOT a diagonal matrix." << endl;

    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}
Task 03: Substring from Left
cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[30];
    int count;

    cout << "Enter a string: ";
    cin.getline(str, 30);

    int len = strlen(str);

    cout << "Enter count: ";
    cin >> count;

    if (count < 0 || count > len) {
        cout << "Error: count is out of range (0 - " << len << ")." << endl;
    } else {
        cout << "Substring: ";
        for (int i = 0; i < count; i++) cout << str[i];
        cout << endl;
    }
    return 0;
}
