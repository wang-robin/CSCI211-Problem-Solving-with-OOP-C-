#include <iostream>
using namespace std;

bool ok(int arr[], int c) {
    for(int i = 0; i < c; i++){
        if(arr[c] == arr[i])
            return false;
    }
    return true;
}

void print(int arr[], int size) {
    static int solCount = 1;
    cout << "Solution #" << solCount++ << ":\t";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, c = 0;

    cout << "Enter n: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;

	while (true){
        c++;
        if (c == n){
            print(arr,n);
            c--;
        } else
            arr[c] = -1;
        while (true){
            arr[c]++;
            if (arr[c] == n){
                c--;
                if (c == -1)
                    return 0;
                continue;
            }
            if (ok(arr,c))
            break;
        }
    }
}
