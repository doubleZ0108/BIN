#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAXSIZE 8

/* 方向向量 */
typedef struct
{
    int x_offset;
    int y_offset;
}DIRECTION;

vector<DIRECTION> direction_8 = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1},{0, -1}, {-1, -1} }; 		//8联通时的方向
vector<DIRECTION> direction_4 = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; 		//4联通时的方向


int main() {
    int count = 0;

    //初始化棋盘
    vector<vector<int> > map(MAXSIZE, vector<int>(MAXSIZE));
    for (int i = 0; i < MAXSIZE; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            map[i][j] = count;
            ++count;
        }
    }
    for(const auto& row: map){
        for(auto item: row){
            cout << setw(2) << item << ' ';
        }
        cout << endl;
    }


    int x = 2, y = 3;

    /* 原始遍历周围一圈的代码(四方向) */
    cout << map[x-1][y] << ' ' << map[x][y+1] << ' ' << map[x+1][y] << ' ' << map[x][y-1] << endl;

    /* 使用方向向量遍历周围一圈(四方向) */
    for (int i = 0; i < direction_4.size(); ++i) {
        cout << map[x + direction_4[i].x_offset][y + direction_4[i].y_offset] << ' ';
    }
    cout << endl;

    /* 使用方向向量遍历周围一圈(八方向) */
    for (int i = 0; i < direction_8.size(); ++i) {
        cout << map[x + direction_8[i].x_offset][y + direction_8[i].y_offset] << ' ';
    }
    cout << endl;

    return 0;
}
