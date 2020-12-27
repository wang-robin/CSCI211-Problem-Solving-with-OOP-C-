#include <iostream>
#include <cstdlib>
using namespace std;

int b[8] = {0}, c = 0, count = 0,
  mp[3][3] = {0,2,1,0,2,1,1,2,0},
  wp[3][3] = {2,1,0,0,1,2,2,0,1};

void print() {
	cout << "Solution Number " << count << endl;
    for (int i = 0; i < 3; i++)
    	cout << "Male " << i << " and female " << b[i] << endl;
}

bool validate() {
	for (int i = 0; i < c; i++) {
        if (b[c] == b[i] ||
            mp[i][b[c]] < mp[i][b[i]] && wp[b[c]][i] < wp[b[c]][c] ||
            mp[c][b[i]] < mp[c][b[c]] && wp[b[i]][c] < wp[b[i]][i])
            return false;
    }
	return true;
}

int main() {
	while (c >= -1) {
        c++;
        if (c == 3) {
            count++;
            print();
            c--;
        } else
            b[c] = -1;
        while (true) {
            b[c]++;
            if (b[c] == 3) {
                c--;
                if (c == -1)
                    return false;
                continue;
            }
            if (validate())
                break;
        }
    }
}
