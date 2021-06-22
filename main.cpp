#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Fox hunting! There are 8 foxes on the map. Find all. \n \n" << endl;
    char field_display[12][22] =
    {
        "  0 1 2 3 4 5 6 7 8 9",
        "0 * * * * * * * * * *",
        "1 * * * * * * * * * *",
        "2 * * * * * * * * * *",
        "3 * * * * * * * * * *",
        "4 * * * * * * * * * *",
        "5 * * * * * * * * * *",
        "6 * * * * * * * * * *",
        "7 * * * * * * * * * *",
        "8 * * * * * * * * * *",
        "9 * * * * * * * * * *"
    };
    int foxes_location[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            foxes_location[i][j] = 0;
        }
    }
    int foxes_left = 8;
    for(int i = 0; i < 11; i++) {
        printf("%s\n", field_display[i]);
    }

    int random_x, random_y;
    srand(time(NULL));
    for(int i = 0; i < foxes_left; i++) {
        random_x = rand() % 10;
        random_y = rand() % 10;
        foxes_location[random_y][random_x]++;
    }

    int x, y;
    int horizontal, vertical, diagonals;
    while(foxes_left != 0) {
        cout << "\nFoxes left " << foxes_left;
        horizontal = 0;
        vertical = 0;
        diagonals = 0;
        cout << "\nSet position: " << endl;
        cin >> x >> y;
        for(int i = 0; i < 10; i++) {
            if(foxes_location[i][x]>0) {
                vertical += foxes_location[i][x];
            }
            if(foxes_location[y][i]>0) {
                horizontal += foxes_location[y][i];
            }
            if((foxes_location[y+i][x+i]>0)&&(foxes_location[y+i][x+i]<9)){
                diagonals += foxes_location[y+i][x+i];
            }
            if((foxes_location[y-i][x-i]>0)&&(foxes_location[y-i][x-i]<9)){
                diagonals += foxes_location[y-i][x-i];
            }
            if((foxes_location[y+i][x-i]>0)&&(foxes_location[y+i][x-i]<9)){
                diagonals += foxes_location[y+i][x-i];
            }
            if((foxes_location[y-i][x+i]>0)&&(foxes_location[y-i][x+i]<9)){
                diagonals += foxes_location[y-i][x+i];
            }
        }
        cout << "There are: \n" << horizontal << " horizontally, \n" << vertical << " vertically, \n" << diagonals << " diagonally, \nOn " << x << " " << y << " position " << foxes_location[x][y] << " foxes" << endl;
        foxes_left -= foxes_location[x][y];
        foxes_location[x][y] = 0;
    }
    cout << "Great! All foxes found" << endl;
    return 0;
}
