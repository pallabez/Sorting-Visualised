#include "header.cpp"

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
 
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
        printState(arr, n);
        Sleep(100);
    }
}
 

int main() {
    int size;
    int *input;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    input = new int[size];

    scrambleInputLinear(input, size);
	
    insertionSort(input, size);
    printState(input, size);
}