#include <iostream>
#include <fstream>

using namespace std;

const int N = 10;

int main() {
    int numbers[N];

    ofstream input_file("input.txt");

    if (!input_file) {
        cout << "Couldn't open file for recording!" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        cout << "Enter the number #" << i+1 << ": ";
        cin >> numbers[i];
        input_file << numbers[i];
    }

    input_file.close();

    ofstream output_file("output.txt");

    if (!output_file) {
        cout << "Couldn't open file for recording!" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        output_file << numbers[i] * 2;
        cout << numbers[i] * 2 << endl;
    }

    output_file.close();

    return 0;
}
