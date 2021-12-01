#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int sum_array(int array[]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += array[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int i;
    string line;
    int prevSum;
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
            win[0] = win[1];
            win[1] = win[2];
            win[2] = stoi(line);

            if (win[0]){
                int currentSum = sum_array(win);
                if (prevSum && currentSum > prevSum){
                    numIncreases += 1;
                }
                prevSum = currentSum;
            }
        }
    }
    reader.close();
    cout << numIncreases << endl;

    return 0;
}