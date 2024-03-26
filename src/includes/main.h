/*
* Function to draw the tower
* @return void
* @param int towers[3][6], int num_disks
* towers: towers to draw
* num_disks: number of disks to draw
*/
void draw_tower(int towers[3][6], int num_disks);

/*
* Function to solve the hanoi tower
* @return void
* @param int n, char source, char auxiliary, char destination
* n: number of disks
* source: source tower
* auxiliary: auxiliary tower
* destination: destination tower
*/
void solver(int n, char source, char auxiliary, char destination, int towers[3][6], int num_disks);

/*
* Function to get the tower in integer
* @return int
* @param char tower
* tower: tower to get in integer
*/
int getTowerInInt(char tower);