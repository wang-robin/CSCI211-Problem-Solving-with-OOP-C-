#include <iostream>
using namespace std;

// file requires updating
// refactoring and update using the STL

void print(int *b, int count, int n) {
    cout << "Solution number " << count << endl;

    string a = "@";
    typedef string box[5][7];
    box bb, wb, *board[8][8],
	wq = {
      " "," "," "," "," "," "," ",
      " ",a,  " ",a,  " ",a,  " ",
      " ",a,  " ",a,  " ",a,  " ",
      " ",a,  a,  a,  a,  a,  " ",
      " "," "," "," "," "," "," "},
	bq = {
      a,  a,   a,  a,  a,  a, a,
      a," ",   a," ",  a," ", a,
      a," ",   a," ",  a," ", a,
      a," ", " "," "," "," ", a,
      a,  a,   a,  a,  a,  a, a};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            wb[i][j] = " ";
			bb[i][j] = a;
		}
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if ((i+j)%2 == 0) {
                if(b[j] == i)
                    board[i][j] = &wq;
                else
                    board[i][j] = &wb;
            } else {
                if (b[j] == i)
                    board[i][j] = &bq;
            else
                board[i][j] = &bb;
            }
        }
    }

    cout << " ";
	for (int i = 0; i < 7*n+2; i++)
        cout << '_';
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 5; k++) {
			cout << " " << a;
			for (int j = 0; j < n; j++) {
                for (int l = 0; l < 7; l++)
                    cout << (*board[i][j])[k][l];
			}
			cout << a << endl;
		}
	}
    cout << " ";
    for (int i = 0; i < 7*n+2; i++)
        cout << a;
    cout << endl;
}

bool validate(int b[], int c) {
	for (int i = 0; i < c; i++) {
		if (b[c] == b[i] || (c-i) == abs(b[c] - b[i]))
	    	return false;
    }
	return true;
}

bool unique(int **a, int* b, int count, int n) {
    for (int i = 0; i < count; i++) {
        bool r1 = 1, r2 = 1, r3 = 1, f1 = 1, f2 = 1, f3 = 1, f4 = 1;
        for (int j = 0; j < n; j++) {
            if (b[a[i][j]] != n-1-j)
                r1 = 0;
            if(b[n-1-j] != n-1-a[i][j])
                r2 = 0;
            if(b[n-1-a[i][j]] != j)
                r3 = 0;
            if(b[a[i][j]] != j)
                f1 = 0;
            if(b[j] != n-1-a[i][j])
                f2 = 0;
            if(b[n-1-a[i][j]] != n-1-j)
                f3 = 0;
            if(b[n-1-j] != a[i][j])
                f4 = 0;
        }
        if(r1||r2||r3||f1||f2||f3||f4) // could break early within the for loop
            return false;
    }
    return true;
}

int main() {
    int count = 1, c = 0, n = 8;
    int *b = new int[n];

    for (int i = 0; i < n; i++)
        b[i] = 0;

    int **a = new int*[1];
    a[0] = new int[n];

    for (int i = 0; i < n; i++)
        a[0][i] = 0;

    while(true) {
        c++;
        if (c == n) {
            if (unique(a,b,count,n)) {
                print(b,count,n);
                count++;

                int **d = new int*[count];
                for (int i = 0; i < count; i++)
                    d[i] = new int[n];

                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == count-1)
                            d[i][j] = b[j];
                        else
                            d[i][j] = a[i][j];
                    }
                }
                for (int i = 0; i < count-1; i++)
                    delete []a[i];
                delete []a;
                a = d;
            }
            c--;
        } else
            b[c] = -1;
        while(true) {
            b[c]++;
            if (b[c] == n) {
                c--;
                if (c == -1) {
                    for (int i = 0; i < count; i++)
                        delete []a[i];
                    delete []a;
                    delete []b;
                    return 0;
                }
                continue;
            }
            if (validate(b,c))
                break;
        }
    }
}
