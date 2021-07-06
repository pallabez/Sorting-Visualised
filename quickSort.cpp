#include "header.cpp"

void displayQuickSort(int input[], int size, int fullInput[], int fullSize) {
    if(size <= 1) return;

    int pivot = input[0];
    int pivotIndex{};

    for(int i = 1; i < size; i++) {
        if(input[i] < pivot) pivotIndex++;
    }

    if(pivotIndex != 0) {
        swap(input, pivotIndex, 0);
        Sleep(1000);
        printState(fullInput, fullSize);
    }

    for(int i = 0, j = pivotIndex + 1; i < pivotIndex && j < size;) {
        if(input[i] >= pivot && input[j] < pivot) {
            swap(input, i, j);
            Sleep(1000);
            printState(fullInput, fullSize);
        }
        else {
            if(input[i] < pivot) i++;
            if(input[j] > pivot) j++;
        }
    }

    displayQuickSort(input, pivotIndex, fullInput, fullSize);
    displayQuickSort(input + pivotIndex + 1, size - pivotIndex - 1, fullInput, fullSize);
}

int main() {
    int size;
    int *input;

    std::cout << "Enter size of the array: ";
    std::cin >> size;
    
    input = new int[size];
    scrambleInputLinear(input, size);

    displayQuickSort(input, size, input, size);    
    printState(input, size);
}