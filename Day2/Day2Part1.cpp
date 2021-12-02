#include <fstream>
#include <iostream>
#include <string>
#include "../Utilities/ctoi.hpp"
using namespace std;
using namespace utilities;

int main(int argc, char const *argv[])
{
    int depth = 0;
    int pos = 0;
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
            int x = ctoi(line[index]);
            cout << x << endl;

            if (line[0] == 'f'){
                pos += x;
            }
            if (line[0] == 'd'){
                depth += x;
            }
            if (line[0] == 'u'){
                depth -= x;
            }
        }
    }

    cout << "Final Depth Is: " << depth << endl;
    cout << "Final Position Is: " << pos << endl;

    cout << "Multiplied You Get: " << depth * pos << endl;

    return 0;
}
