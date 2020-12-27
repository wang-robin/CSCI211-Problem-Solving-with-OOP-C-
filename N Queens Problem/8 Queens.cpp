#include <iostream>
#include <cmath>
using namespace std;

int b[8] = {0}, c = -1, count = 0;

void print() {
    int r = 0;

    cout << "Solution Number:  " << count << endl;

    while (r < 8) {
        for (int i = 0; i < 8; i++) {
            if (b[i] == r)
                cout << "Q ";
       	 	else
            	cout << "- ";
        }
	    cout << endl;
	    r++;
    }
    cout << endl;
}

bool validate() {
	for (int i = 0; i < c; i++) {
		if (b[c] == b[i] || (c-i) == abs(b[c] - b[i]))
	    	return false;
		}
	return true;
}

int main() {
	while (c >= -1) {

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
