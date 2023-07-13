#include <iostream>

using namespace std;

void inv(int *arr)
{
    int temp[10]={};
    for (int i=0; i<10 ;i++) {
        *(temp+i) = *(arr+9-i);
    }
    for (int i=0; i<10 ;i++) {
        *(arr+i) = *(temp+i);
    }
}

int main() {
    cout << "Task 2" << endl;

    int arr[10]={};

    for (int i=0; i<10; i++){
            *(arr+i)+=i+1;
            cout << *(arr+i) << " ";
        } cout << endl;

    inv(arr);

    for (int i=0; i<10; i++) {
        cout << *(arr+i) << " ";
    }
}
