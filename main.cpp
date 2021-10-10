#include <iostream>
#include <ctime>

using namespace std;

int const rSIZE = 3;

void searchByX(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light);

void searchByY(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light);

void searchByZ(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light);

void fillingCube(int array[rSIZE][rSIZE][rSIZE]);

int getTrueNum(int num);

int main() {
    srand(time(NULL));

    int particleLight = 0;
    int light = 0;

    int array[rSIZE][rSIZE][rSIZE];

    fillingCube(array);
    searchByX(array, particleLight, light);
    searchByY(array, particleLight, light);
    searchByZ(array, particleLight, light);


}

void searchByX(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light) {
    for (int x = 0; x < rSIZE; x++) {
        for (int y = 0; y < rSIZE; y++) {
            for (int z = 0; z < rSIZE; z++) {
                if (x == y && y == z && z == x && array[x][y][z] == 0) {
                    particleLight++;
                    if (array[getTrueNum(x + 1)][y][z] == 0) {
                        particleLight++;
                        if (array[getTrueNum(x + 2)][y][z] == 0) {
                            particleLight++;
                            if (particleLight == rSIZE) {
                                light++;
                                cout << "Count lights X:" << light << " [x][y][z]" << x << y << z << " "
                                     << getTrueNum(x + 1) << y << z << " " << getTrueNum(x + 2) << y << z << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void searchByY(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light) {
    for (int x = 0; x < rSIZE; x++) {
        for (int y = 0; y < rSIZE; y++) {
            for (int z = 0; z < rSIZE; z++) {
                if (x == y && y == z && z == x && array[x][y][z] == 0) {
                    particleLight++;
                    if (array[x][getTrueNum(y + 1)][z] == 0) {
                        particleLight++;
                        if (array[x][getTrueNum(y + 2)][z] == 0) {
                            particleLight++;
                            if (particleLight == rSIZE) {
                                light++;
                                cout << "Count lights Y:" << light << " [x][y][z]" << x << y << z << " " << x
                                     << getTrueNum(y + 1)
                                     << z << " " << x << getTrueNum(y + 2) << z << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void searchByZ(int array[rSIZE][rSIZE][rSIZE], int particleLight, int light) {
    for (int x = 0; x < rSIZE; x++) {
        for (int y = 0; y < rSIZE; y++) {
            for (int z = 0; z < rSIZE; z++) {
                if (x == y && y == z && z == x && array[x][y][z] == 0) {
                    particleLight++;
                    if (array[x][y][getTrueNum(z + 1)] == 0) {
                        particleLight++;
                        if (array[x][y][getTrueNum(z + 2)] == 0) {
                            particleLight++;
                            if (particleLight == rSIZE) {
                                light++;
                                cout << "Count lights Z:" << light << " [x][y][z]" << x << y << z << " " << x
                                     << y << getTrueNum(z + 1) << " " << x << y << getTrueNum(z + 2) << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void fillingCube(int array[rSIZE][rSIZE][rSIZE]) {
    for (int x = 0; x < rSIZE; x++) {
        for (int y = 0; y < rSIZE; y++) {
            for (int z = 0; z < rSIZE; z++) {
                array[x][y][z] = rand() % 2;
            }
        }
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