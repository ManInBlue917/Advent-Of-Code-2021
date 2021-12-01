#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    string line;
    int prevNum;
    int numIncreases = 0;
    int win[3] = {NULL, NULL, NULL};

    ifstream reader("PuzzleInputDay1.txt");

    if (!reader.is_open()){
        cout << "Error opening input file" << endl;
        return -1;
    }
    else{
        cout << "Input File Opened Successfully" << endl;
        while (getline(reader, line)){
            int currentNum = stoi(line);
            if (prevNum && currentNum > prevNum){
                numIncreases += 1;
            }
            prevNum = currentNum;
        }
    }
    reader.close();
    cout << numIncreases << endl;

    return 0;
}