#include "header.cpp"

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
    int *input;
    std::cout << "Enter size of the array: ";
    std::cin >> size;
    input = new int[size];

    scrambleInputLinear(input, size);
	
    displayMergeSort(input, size, input, size);
    printState(input, size);
}