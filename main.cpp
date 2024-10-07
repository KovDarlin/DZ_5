#include <iostream>
using namespace std;

bool skladne(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int* delete_skladne(int* masiv, int size, int& without_s) {
    without_s = 0;
    for (int i = 0; i < size; ++i) {
        if (!skladne(masiv[i])) {
            without_s++;
        }
    }

    int* rev_masiv = new int[without_s];
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (!skladne(masiv[i])) {
            rev_masiv[index++] = masiv[i];
        }
    }

    return rev_masiv;
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

    int without_s;
    int* rev_masiv = delete_skladne(masiv, size, without_s); 

    cout << "Your new array: ";
    for (int i = 0; i < without_s; i++) {
        cout << rev_masiv[i] << " ";
    }
    cout << endl;

    delete[] masiv;
    delete[] rev_masiv;

    return 0;
}