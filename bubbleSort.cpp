#include "header.cpp"

void displayBubbleSort(int *array, int num) {
    for(int i = 0; i < num - 1; i++) {
        for(int j = 0; j < num - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(array, j + 1, j);
                printState(array, num);
                Sleep(1000/num);
            }
        }
    }
}

int main() {
    int size;
    int *input;
    
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    input = new int[size];

    scrambleInputLinear(input, size);
    displayBubbleSort(input, size);
}