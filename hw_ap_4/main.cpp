#include <iostream>
#include <fstream>
#define N 100
using namespace std;

int main() {
    char *data1 = new char[N];
    ofstream A("A.txt");
    cout << "Enter the text in file:" << endl;
    cin.getline(data1,N);

    A << data1 << endl;

    A.close();

    ifstream inputFile("A.txt");
    ofstream outputFile("B.txt");
    string line;
    cout << "Result:" << endl;

    while (getline(inputFile, line)) {
        for (char& c : line) {
            if (c == ' ')
                c = ',';
        }
        cout << line << endl;
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    delete[] data1;
    return 0;
}
