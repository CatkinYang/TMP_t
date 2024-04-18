#include <fstream>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> bram = {5,  11, 23,  29,  37,  48,  66, 77,
                           88, 99, 110, 118, 124, 136, 142};
unordered_set<int> dsp = {14, 20, 26, 34, 40,  45,  51,  63,  69,  74,
                          80, 85, 91, 96, 102, 107, 113, 121, 127, 133};

unordered_set<int> clb = {
    1,   2,   3,   4,   6,   7,   8,   9,   10,  12,  13,  15,  16,  17,
    18,  19,  21,  22,  24,  25,  27,  28,  30,  31,  32,  33,  35,  36,
    38,  39,  41,  42,  43,  44,  46,  47,  49,  50,  52,  53,  54,  55,
    56,  57,  58,  59,  60,  61,  62,  64,  65,  67,  68,  70,  71,  72,
    73,  75,  76,  78,  79,  81,  82,  83,  84,  86,  87,  89,  90,  92,
    93,  94,  95,  97,  98,  100, 101, 103, 104, 105, 106, 108, 109, 111,
    112, 114, 115, 116, 117, 119, 120, 122, 123, 125, 126, 128, 129, 130,
    131, 132, 134, 135, 137, 138, 139, 140, 141, 143, 144, 145, 146};
int main() {
    ofstream outputFile("graph.txt"); // 打开输出文件

    if (outputFile.is_open()) { // 检查文件是否成功打开
        for (int i = 1; i <= 350; i++) {
            for (int j = 1; j <= 146; j++) {
                if ((j >= 5 && j <= 8 && i >= 75 && i <= 100) ||
                    (j >= 139 && j <= 142 && i >= 75 && i <= 100) ||
                    (j >= 5 && j <= 8 && i >= 225 && i <= 250) ||
                    (j >= 139 && j <= 142 && i >= 225 && i <= 250)) {
                    outputFile << "B"
                               << " ";
                    continue;
                }
                if ((j >= 54 && j <= 59) && (i >= 201 && i <= 300)) {
                    outputFile << "B"
                               << " ";
                    continue;
                }
                if (bram.find(j) != bram.end()) {
                    outputFile << "b"
                               << " ";
                } else if (dsp.find(j) != dsp.end()) {
                    outputFile << "d"
                               << " ";
                } else if (clb.find(j) != clb.end()) {
                    outputFile << "c"
                               << " ";
                }
            }
            if (i % 50 == 0)
                outputFile << endl;
            outputFile << endl;
        }
    }

    return 0;
}
