#include <iostream>
#include <iomanip>
using namespace std;

const int ROW = 6;
const int COLUMN = 5;

void board(int row, int column, char answerOfPlayer[6][5] = {}) {
    int width_of_one_column = 5;
    int width_of_row = row*width_of_one_column + row + 1;
    // cout << '+' << setfill('-') << setw(width_of_row - 1) << '+' << endl;

    for(int i = 0; i < 2*column + 1; i++) {
        if(i % 2 == 0) {
            cout << '+' << setfill('-') << setw(width_of_row - 1) << '+';
        } else {
            int row_index = (i+1)/2 - 1;
            if(i == 2*column) {
                continue;
            }
            for(int j = 0; j < width_of_row; j++) {
                if (j == 0 || j == width_of_row - 1) {
                    cout << "|";
                } else if(j % (width_of_one_column+1) == 0) {
                    cout << "|";
                } else if(j == (width_of_one_column + 1)/2) {
                    cout << answerOfPlayer[row_index][0];
                }
                else if((j - (width_of_one_column + 1)/2) % (width_of_one_column + 1) == 0) {
                    int index_of_letter = (j - (width_of_one_column + 1)/2) / (width_of_one_column + 1);
                    cout << answerOfPlayer[row_index][index_of_letter];
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{  

    char answer[6][5] = {
        {'5', ' ', '3', '5', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', '7', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };
    board(5, 6, answer);
    return 0;
}
