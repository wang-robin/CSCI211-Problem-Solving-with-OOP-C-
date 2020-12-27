#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int cost(int i, int j) {
    static int weight[rows][cols] =
	   {{3, 4, 1, 2, 8, 6},
		{6, 1, 8, 2, 7, 4},
		{5, 9, 3, 9, 9, 5},
		{8, 4, 1, 3, 2, 6},
		{3, 7, 2, 8, 6, 4}};

	if (j == 0)
        return weight[i][0];

	int left = weight[i][j] + cost(i, j-1);
	int up = weight[i][j] + cost((i-1+rows)%rows, j-1);
	int down = weight[i][j] + cost((i+1)%rows, j-1);

	return min(left, min(up, down));
}

int main() {
	int ex[rows];

	for (int i = 0; i < rows; i++)
        ex[i] = cost(i, cols-1);

	int minimum = ex[0];

    for (int i = 1; i < rows; i++) {
        if (ex[i] < minimum)
            minimum = ex[i];
    }

	cout << "The shortest path is of length " << minimum << endl;
}
