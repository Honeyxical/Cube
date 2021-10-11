#include <iostream>
#include <ctime>

using namespace std;

int const rSIZE = 3;

bool searchByX(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z);

bool searchByY(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z);

bool searchByZ(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z);

void fillingCube(int array[rSIZE][rSIZE][rSIZE]);

int getTrueNum(int num);

int main() {
    srand(time(NULL));

    int light = 0;

    int array[rSIZE][rSIZE][rSIZE];

    fillingCube(array);

    for (int z = 0; z < rSIZE; ++z) {
        for (int y = 0; y < rSIZE; ++y) {
            for (int x = y; x <= y; ++x) {
                if (searchByX(array, x, y, z)) {
                    light++;
                }
                if (searchByY(array, x, y, z)) {
                    light++;
                }
                if (searchByZ(array, x, y, z)) {
                    light++;
                }
            }
        }
    }
    cout << "Count lights:" << light;
}

bool searchByX(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z) {
    if (array[x][y][z] == 0) {
        if (array[getTrueNum(x + 1)][y][z] == 0) {
            if (array[getTrueNum(x + 2)][y][z] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool searchByY(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z) {
    if (array[x][y][z] == 0) {
        if (array[x][getTrueNum(y + 1)][z] == 0) {
            if (array[x][getTrueNum(y + 2)][z] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool searchByZ(int array[rSIZE][rSIZE][rSIZE], int x, int y, int z) {
    if (array[x][y][z] == 0) {
        if (array[x][y][getTrueNum(z + 1)] == 0) {
            if (array[x][y][getTrueNum(z + 2)] == 0) {
                return true;
            }
        }
    }
    return false;
}

void fillingCube(int array[rSIZE][rSIZE][rSIZE]) {
    for (int x = 0; x < rSIZE; x++) {
        for (int y = 0; y < rSIZE; y++) {
            for (int z = 0; z < rSIZE; z++) {
                array[x][y][z] = rand() % 2;
                cout << array[x][y][z];
            }
            cout << endl;
        }
        cout << endl;
    }
}

int getTrueNum(int num) {
    if (num == 3) {
        return 0;
    } else if (num == 4) {
        return 1;
    }
    return num;
}