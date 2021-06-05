#include <iostream>
#include <random>
#include <windows.h>

void scrambleInputLinear(int input[], int size) {
    std::default_random_engine eng;
    
    for(int i = 0; i < size; i++) {
        input[i] = i + 1;
    }

    for(int i = 0; i < size * 2; i++) {
        
        int random = eng() % size;
        int random2 = eng() % size;

        int temp = input[random];
        input[random] = input[random2];
        input[random2] = temp;
    }
}

void printState(int input[], int size) {
    system("cls");
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < input[i]; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void displayArray(int input[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
}

void displayMergeSort(int input[], int size, int fullInput[], int fullSize) {
	if(size <= 1) return;

	int pivot = size / 2;
    
    displayMergeSort(input, pivot, fullInput, fullSize);
    (size % 2 == 0) ? displayMergeSort(input + pivot, pivot, fullInput, fullSize) : displayMergeSort(input + pivot, pivot + 1, fullInput, fullSize);


	int output[size];
	int index{};

    for(int i = 0; i < size; i++) {
		output[i] = input[i];
	}

	for(int i = 0, j = pivot, k = size; k != 0; k--) {
		if((output[i] <= output[j] && i != pivot) || j >= size) {
			input[index] = output[i];
			i++;
		} else {
			input[index] = output[j];
			j++;
		}
		index++;
	}

    Sleep(100 * size);
    printState(fullInput, fullSize);
}

int main() {
    int size;
    std::cin >> size;

    int *input = new int[size];

    scrambleInputLinear(input, size);
    displayMergeSort(input, size, input, size);
    printState(input, size);
}