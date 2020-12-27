#include <iostream>
#include <cmath>
using namespace std;

int b[8] = {0}, count = 0;
int a[8][5] = {
    {-1 },
    {0, -1},
    {0, -1},
    {0, 1, 2, -1},
    {0, 1, 3, -1},
    {1, 4, -1},
    {2, 3, 4, -1},
    {3, 4, 5, 6, -1}};

void print() {
    count++;
    cout << "Solution Number:  " << count << endl;
    cout << " "  << b[0] << b[1] << "\n"
         << b[2] << b[3] << b[4] << b[5] <<"\n"
         << " "  << b[6] << b[7] << "\n\n";
}

bool validate(int c) {
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

void move(int c) {
    if (c == 8) {
        print();
        return;
    }
    for(int i = 0; i < 8; i++) {
        b[c] = i;
        if (validate(c))
            move(c+1);
    }
}

int main() {
    move(0);
}
