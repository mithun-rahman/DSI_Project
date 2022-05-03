#include<bits/stdc++.h>

using namespace std;

#include "InstructionFactory.cpp"

int main()
{
    string line;
    vector<string> goodInstruction;

    ifstream file("input.txt");

    while(getline(file, line)) {
        line = InstructionFactory::createInstruction(line);
        if(line != "0") {
            goodInstruction.push_back(line);
        }
    }
    file.close();

    for(int i = 0; i < goodInstruction.size(); i++) {
        cout << goodInstruction[i] << endl;
    }
    return 0;
}
