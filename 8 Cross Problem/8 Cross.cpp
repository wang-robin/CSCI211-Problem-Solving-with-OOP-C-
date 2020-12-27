#include <iostream>
#include <cmath>
using namespace std;

int b[8] = {0}, c = 0, count = 0;

int a[8][5] = {
    {-1 },
    {0, -1},
    {0, -1},
    {0, 1, 2, -1},
    {0, 1, 3, -1},
    {1, 4, -1},
    {2, 3, 4, -1},
    {3, 4, 5, 6, -1}};

void print(){
    cout << "Solution Number:  " << count << endl;
    cout << " "  << b[0] << b[1] << "\n"
         << b[2] << b[3] << b[4] << b[5] << "\n"
         << " "  << b[6] << b[7] << "\n\n";
}

bool validate() {
	for (int i = 0; i < c; i++) {
		if (b[c] == b[i])
	    	return false;
	}

	int i = 0;
	while (a[c][i] != -1) {
        if (abs(b[c] - b[a[c][i]]) == 1)
            return false;
        i++;
    }
	return true;
}

int main() {
	while (true) {

        c++;

        if (c == 8) {
            count++;
            print();
            c--;
        } else
            b[c] = -1;

        while (true) {

            b[c]++;

            if (b[c] == 8) {
                c--;
                if (c == -1)
                    return 0;
                continue;
            }

            if (validate())
                break;
        }
    }
}
