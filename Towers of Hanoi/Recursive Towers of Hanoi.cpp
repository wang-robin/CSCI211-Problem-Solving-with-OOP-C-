#include <iostream>
using namespace std;

void print(int n, int from, int to) {
    static int move = 1;
    cout << "Move #" << move++ << ":\tMoving ring " << n << " from " << (char) (65+from) << " to " << (char) (65+to) << endl;
}

int getOther(int a, int b) {
    return 3 - a - b;
}

void move(int n, int from, int to) {
    if (n == 1) {
        print(n, from, to);
        return;
    }

    int other = getOther(from, to);

    move(n-1, from, other);
    print(n, from, to);
    move(n-1, other, to);
}

int main() {
    int n;
    cout << "Enter number of rings: ";
    cin >> n;
    move(n, 0, 1);
}
