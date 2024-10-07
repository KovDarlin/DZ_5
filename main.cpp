#include <iostream>
using namespace std;

void makeArrays(int* masiv, int size, int*& pos, int& pos_size, int*& neg, int& neg_size, int*& nul, int& nul_size) {
    pos_size = 0;
    neg_size = 0;
    nul_size = 0;

    for (int i = 0; i < size; i++) {
        if (masiv[i] > 0) {
            pos_size++;
        }
        else if (masiv[i] < 0) {
            neg_size++;
        }
        else {
            nul_size++;
        }
    }

    pos = new int[pos_size];
    neg = new int[neg_size];
    nul = new int[nul_size];

    int pos_i = 0, neg_i = 0, nul_i = 0;

    for (int i = 0; i < size; i++) {
        if (masiv[i] > 0) {
            pos[pos_i++] = masiv[i];
        }
        else if (masiv[i] < 0) {
            neg[neg_i++] = masiv[i];
        }
        else {
            nul[nul_i++] = masiv[i];
        }
    }
}

int main() {
    int size;
    cout << "Enter size for array: ";
    cin >> size;

    int* masiv = new int[size];

    cout << "Enter elements for array: ";
    for (int i = 0; i < size; i++) {
        cin >> masiv[i];
    }

    int pos_size = 0, neg_size = 0, nul_size = 0;
    int* pos = nullptr;
    int* neg = nullptr;
    int* nul = nullptr;

    makeArrays(masiv, size, pos, pos_size, neg, neg_size, nul, nul_size);

    cout << "Positive: ";
    for (int i = 0; i < pos_size; i++) {
        cout << pos[i] << " ";
    }
    cout << endl;

    cout << "Negative: ";
    for (int i = 0; i < neg_size; i++) {
        cout << neg[i] << " ";
    }
    cout << endl;

    cout << "Zero: ";
    for (int i = 0; i < nul_size; i++) {
        cout << nul[i] << " ";
    }
    cout << endl;

    delete[] pos;
    delete[] neg;
    delete[] nul;
    delete[] masiv;

    return 0;
}