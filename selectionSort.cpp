#include "header.cpp"

void displaySelectionSort(int input[], int size) {
    

    for(int i = 0; i < size; i++) {
        int min{i};
        for(int j = i; j < size; j++) {
            if(input[j] < input[min]) min = j;
        }
        if(i != min) {
            swap(input, i, min);
            printState(input, size);
            Sleep(300);
        }
    }


}

int main() {
    int size;
    int *input;
    setUp(size, input);
    displaySelectionSort(input, size);
}