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

void swap(int input[], int index1, int index2) {
    int temp = input[index2];
    input[index2] = input[index1];
    input[index1] = temp;
}

