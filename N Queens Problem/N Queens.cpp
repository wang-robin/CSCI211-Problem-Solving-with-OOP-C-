#include <iostream>
using namespace std;

bool validate(int b[], int c) {
    for (int i = 0; i < c; i++) {
        if (b[c] == b[i] || (c-i) == abs(b[c] - b[i]))
            return false;
    }
	return true;
}

int main() {
    int n;
    int *b;

    cout << "Enter n: ";
    cin >> n;

    for (int j = 1; j <= n; j++) {
        int c = 0, count = 0;

        b = new int[j];
        for (int i = 0; i < j; i++)
            b[i] = 0;

        bool toggle = 0;
        while(true) {

            c++;

            if (c == j) {
                count++;
                c--;
            }
            else
                b[c] = -1;
            while (true) {
                b[c]++;
                if (b[c] == j) {
                    c--;
                    if (c == -1) {
                        delete []b;
                        toggle = 1;
                        if (count == 1)
                            cout << "There is 1 solution to the " << j << "queens problem.\n";
                        else
                            cout << "There are " << count << " solutions to the " << j << "queens problem.\n";
                        break;
                    }
                    continue;
                }
                if (validate(b,c))
                    break;
            }
            if (toggle)
                break;
        }
    }
}
