#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
using namespace std;

void leftToright(char* temp, char** arr) {
    srand(time(0));
    int random = rand() % 10;
    int length = strlen(temp);
    int i = 0;
    for (int i = 0; i < length && i < 10; i++) {
        if (arr[random][i] != '*') {

            return;
        }
    }
    // if (i > 9) {
    //     leftToright(temp, arr);
    //     return;
    // }

    for (int i = 0; i < length && i < 10; i++) {
        arr[random][i] = temp[i];
    }


}
void rightToleft(char* temp, char** arr) {
    srand(time(0));
    int random = rand() % 10;
    int length = strlen(temp);
    int j = 0;
    for (int i = 0, j = 9; i<length && j >-1; i++, j--) {
        if (arr[random][j] != '*') {

            return;
        }

    }
    // if (j < 0) {
    //     rightToleft(temp, arr);
    //     return ;
    // }
    for (int i = 0, j = 9; i<length && j > -1; i++, j--) {
        arr[random][j] = temp[i];
    }
}
void topTobottom(char* temp, char** arr) {
    srand(time(0));
    int random = rand() % 10;
    int length = strlen(temp);
    int i = 0;

    for (int i = 0; i < length && i < 10; i++) {
        if (arr[i][random] != '*') {

            return;
        }

    }
    // if (i > 9) {
    //     topTobottom(temp, arr);
    //     return;
    // }
    for (int i = 0; i < length && i < 10; i++) {
        arr[i][random] = temp[i];
    }

}
void bottomTotop(char* temp, char** arr) {
    srand(time(0));
    int random = rand() % 10;
    int length = strlen(temp);
    int j = 0;

    for (int i = 0, j = 9; i < length && j >= 0; i++, j--) {
        if (arr[j][random] != '*') {

            return;


        }

    }
    // if (j < 0) {
    //     bottomTotop(temp, arr);
    //     return;
    // }
    for (int i = 0, j = 9; i < length; i++, j--) {
        arr[j][random] = temp[i];
    }

}
void diognaltopleftToright(char* temp, char** arr) {
    srand(time(0));
    int random = rand() % 10;
    int length = strlen(temp);
    int j = 0;
    cout << length << " " << random << endl;
    for (int i = 0, j = random; i < length && j < 10; i++, j++) {
        if (arr[j][j] != '*') {

            return;
        }

    }

    for (int i = 0, j = random; i < length && j < 10; i++, j++) {
        arr[j][j] = temp[i];
    }


}
void diognaltoprightToleft(char* temp, char** arr) {
    srand(time(0));
    int random = (rand() % 5) + 5;
    int length = strlen(temp);
    int j = 0;
    for (int i = 0, j = random; i<length && j>-1; i++, j--) {
        if (arr[i][j] != '*') {

            return;
        }

    }

    for (int i = 0, j = random; i<length && j > -1; i++, j--) {
        arr[i][j] = temp[i];
    }



}
void diognalbottomleftToright(char* temp, char** arr) {
    srand(time(0));
    int random = (rand() % 5) + 5;
    int randcol = rand() % 5;
    int length = strlen(temp);
    cout << length << " " << random << "In fuction" << endl;
    for (int i = random, j = randcol; i < length; i--, j++) {
        if (arr[i][j] != '*') {
            diognalbottomleftToright(temp, arr);
            return;
        }

    }
    for (int i = random, j = randcol; i < length; i--, j++) {
        arr[i][j] = temp[i];
    }



}
void diognalbottomrightToleft(char* temp, char** arr) {
    srand(time(0));
    int random = (rand() % 5) + 5;
    int randcol = (rand() % 5) + 5;
    int length = strlen(temp);
    cout << length << " " << random << "In fuction  " << randcol << endl;
    for (int i = random, j = randcol; i < length; i--, j--) {
        if (arr[i][j] != '*') {
            diognalbottomrightToleft(temp, arr);
            return;
        }

    }
    for (int i = random, j = randcol; i < length; i--, j--) {
        arr[i][j] = temp[i];
    }


}



int main() {
    char** arr = 0;
    char temp[10];
    int length = 0;
    int random = 0;




    int rows = 10;

    int cols = 10;
    arr = new  char* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new char[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = '*';
        }
    }


    srand(time(0));
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    if (!fin.is_open()) {
        cout << "File couldnt be opened ";
    }
    else {
        while (!fin.eof()) {
            fin >> temp;
            length = strlen(temp);
            random = (rand() % 4) + 1;
            switch (random) {
            case 1:
                rightToleft(temp, arr);
                break;
            case 2:
                leftToright(temp, arr);
                break;
            case 3:
                topTobottom(temp, arr);
                break;
            case 4:
                bottomTotop(temp, arr);
                break;
                // case 5:
                //     diognaltopleftToright(temp, arr);
                //     break;
                // case 6:
                //     diognaltoprightToleft(temp, arr);
                //     break;
                    //case 7:
                    // diognalbottomleftToright(temp,arr);
                    // break;
                    // case 8:
                    // diognalbottomrightToleft(temp,arr);
                    // break;
            }

        }
    }
    int r = 0;
    char tempch = ' ';
    fin.close();
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         if (arr[i][j] == '*') {
    //             r = rand() % 26;
    //             tempch = 'a' + r;
    //             arr[i][j] = tempch;
    //         }
    //     }

    // }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    return 0;
}