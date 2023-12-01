#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {
        int* indices = new int[size + 1]; 
        int* endPtr = indices;  
        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                *endPtr++ = static_cast<int>(i);  
            }
        }
        *endPtr = -1;  
        return indices;  
    }

    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int indices[]) {
        cout << title << endl;
        if (indices && indices[0] != -1) {
            for (int i = 0; indices[i] != -1; ++i) {
                    cout << array[indices[i]];
                if (indices[i + 1] != -1) {
                        cout << ", ";
                }
            }
        }
        else {
            cout << "Empty Selection";
        }
        cout << endl;
    }
}

#endif 