#include<bits/stdc++.h>

using namespace std;

#include "Instruction.cpp"

class InstructionFactory
{
    public:
        static string createInstruction(string line)
        {
            Instruction *instruction = new makeInstruction;

            string temp = line;
            line = instruction->readLine(line);

            if(instruction->isValid(line) == 0) {

                line = "0";
            }
            else {
                line = instruction->findInstruction(temp);
            }

            return line;
        }
};
