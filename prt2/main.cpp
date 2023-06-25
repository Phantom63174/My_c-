#include <iostream>
#include <fstream>

using namespace std;

void enter_numbers(int n) {
    ofstream input_file("numbers.txt");

    if (!input_file) {
        cout << "Couldn't open file for recording!" << endl;
        return;
    }

int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number #" << i+1 << ": ";
        cin >> a[i];
        input_file << a[i] << endl;
    }

    input_file.close();
}

void choose_1(){
    ofstream output_file("numbers1.txt");

    if (!output_file) {
        cout << "Couldn't open file for recording!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        
    }
}



int main() {
    int n;
    cout << "Enter the number of numbers:" << endl;
    cin >> n;

    int i=0;
    cout << "Make your choice:(1 - choose even, 2 - choose odd, 3 - arithmetic mean)" << endl;
    cin >> i;

    enter_numbers(n);

    switch (i) {
        case 1:

        case 2:

        case 3
    }




    return 0;
}