#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int depth = 0;
    int pos = 0;
    int aim = 0;
    string line;

    ifstream reader("PuzzleInputDay2.txt");
    if (!reader.is_open()){
        cout << "Error opening input file" << endl;
        return -1;
    }
    else{
        cout << "File opened successfully" << endl;
        while (getline(reader, line)){
            int index = line.length() - 1;
            int x = line[index] - '0';
            cout << x << endl;

            if (line[0] == 'f'){
                pos += x;
                depth += aim * x;
            }
            if (line[0] == 'd'){
                aim += x;
            }
            if (line[0] == 'u'){
                aim -= x;
            }
        }
    }

    cout << "Final Depth Is: " << depth << endl;
    cout << "Final Position Is: " << pos << endl;

    cout << "Multiplied You Get: " << depth * pos << endl;

    return 0;
}
