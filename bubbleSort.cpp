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
    std::cin >> size;

    int *input = new int[size];

    scrambleInputLinear(input, size);
    displayBubbleSort(input, size);
}