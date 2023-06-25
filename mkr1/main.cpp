#include <iostream>
#include <fstream>

using namespace std;

void size_of_array(int &N);

void fill_array(float *arr, int N);

void change_array(float *arr, int N);

void data_to_file(float *arr, int N);

int main() {
    int N = 0;
    size_of_array(N);
    auto *arr = new float[N];
    fill_array(arr, N);
    change_array(arr,N);
    data_to_file(arr,N);
    delete[] arr;
    return 0;
}

void size_of_array(int &N){
    do {
        cout << "Enter the size of array (must be even):" << endl;
        cin >> N;
    } while(N%2>0);
}

void fill_array(float *arr, int N){
    cout << "Enter the array:" << endl;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void change_array(float *arr, int N){
    cout << "Changed array:" << endl;
    for(int i=0; i<N/2; i++){
        if ((i+1) % 2 == 0) {
            int j = i+N/2;
            arr[i] = arr[j]*2;
        }
    }
    for(int i=0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void data_to_file(float *arr, int N){
  ofstream My_file("arr.txt");
    for(int i=0; i<N; i++){
        My_file << arr[i];
        My_file << " ";
    }
    My_file.close();
}



