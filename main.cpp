#include <iostream>
using namespace std;

int* first(int size) {
    return new int[size];
}

void second(int* masiv, int size, int value = 1) {
    for (int i = 0; i < size; i++) {
        masiv[i] = value;
    }
}

void third(int* masiv, int size) {
    for (int i = 0; i < size; i++) {
        cout << masiv[i] << " ";
    }
    cout << endl;
}

void fourth(int* masiv) {
    delete[] masiv;
}

int* fifth(int* masiv, int& size, int new_el) {
    int* Nmasiv = new int[size + 1];
    for (int i = 0; i < size; i++) {
        Nmasiv[i] = masiv[i];
    }
    Nmasiv[size] = new_el;

    size++;
    delete[] masiv;

    return Nmasiv;
}

int* sixth(int* masiv, int& size, int index, int new_el) {
    int* Nmasiv = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        Nmasiv[i] = masiv[i];
    }
    Nmasiv[index] = new_el;

    for (int i = index; i < size; ++i) {
        Nmasiv[i + 1] = masiv[i];
    }

    ++size;
    delete[] masiv;

    return Nmasiv;
}

int* seventh(int* masiv, int& size, int index) {
    int* Nmasiv = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        Nmasiv[i] = masiv[i];
    }
    for (int i = index + 1; i < size; ++i) {
        Nmasiv[i - 1] = masiv[i];
    }
    --size;
    delete[] masiv;
    return Nmasiv;
}

int main() {
    int index;
    int new_el;
    int size;
    cout << "Enter size for array: ";
    cin >> size;

    int* masiv = first(size);
    second(masiv, size);

    cout << "Initial array: ";
    third(masiv, size);

    cout << "Enter element to append for end array: ";
    cin >> new_el;
    masiv = fifth(masiv, size, new_el);
    cout << "Array after appending: ";
    third(masiv, size);

    cout << "Enter index to insert at: ";
    cin >> index;
    cout << "Enter element to insert: ";
    cin >> new_el;
    masiv = sixth(masiv, size, index, new_el);
    cout << "Array after insertion: ";
    third(masiv, size);

    cout << "Enter index to delete element: ";
    cin >> index;
    masiv = seventh(masiv, size, index);
    cout << "Array after deletion: ";
    third(masiv, size);

    fourth(masiv);
}