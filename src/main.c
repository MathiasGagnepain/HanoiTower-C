#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "includes/main.h"

int main(int argc, char const *argv[])
{
    // towers init
    const int num_disks = 6;
    int towers[3][num_disks];
    for (int i = 0; i < num_disks; i++) {
        towers[0][i] = 0;
        towers[1][i] = 0;
        towers[2][i] = 0;
    }
    solver(num_disks, 'A', 'B', 'C', towers, num_disks);

    return 0;
}

void drawing(int num_disks, int towers[3][num_disks])
{
    for (int i = 0; i < num_disks; i++) {
        int T1 = towers[0][i];
        int T2 = towers[1][i];
        int T3 = towers[2][i];
    
        printf("%i    %i    %i\n", T1, T2, T3);
    }

}

void solver(int n, char source, char auxiliary, char destination, int towers[3][6], int num_disks){
    if (n == 1){
        printf("Move disk 1 from %c to %c \n", source, destination);
        towers[getTowerInInt(source)][n-1] = 0;
        towers[getTowerInInt(destination)][n-1] = 1;
        drawing(num_disks, towers);
    } else {
        solver(n - 1, source, destination, auxiliary, towers, num_disks);  // Move top n-1 disks to auxiliary;
        printf("Move disk %i from %c to %c \n", n, source, destination);  // Move remaining disk to destination;
        towers[getTowerInInt(source)][n-1] = 0;
        towers[getTowerInInt(destination)][n-1] = n;
        drawing(num_disks, towers);
        solver(n - 1, auxiliary, source, destination,  towers, num_disks);  // Move remaining disks to destination;
    }
}

int getTowerInInt(char tower){
    switch (tower) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        default:
            return -1;
    }
}