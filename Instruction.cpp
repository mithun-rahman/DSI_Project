#include<bits/stdc++.h>

using namespace std;

#include "CodeFactory.cpp"

class Instruction
{
    public:
        virtual string readLine(string line)       = 0;
        virtual bool isValid(string st)            = 0;
        virtual string findInstruction(string st)  = 0;
};

class makeInstruction:public Instruction
{
    public:
        string readLine(string line)
        {
            string temp, res;
            res = temp = "";
            for(int i = 0; i < line.size(); i++) {
                if(line[i] == '#') {            // if find # sign then ignore rest of the line.
                    break;
                }
                if(line[i] == ' ') {
                    if(temp.size()) {
                      //  res += makeCode(temp);  // keyword or number or register.
                        temp = CodeFactory::createCode(temp);
                        res += temp;
                        temp = "";
                    }
                }
                else if(line[i] == ',') {
                    if(temp.size()) {
                      //  res += makeCode(temp);  // keyword or number or register.
                        temp = CodeFactory::createCode(temp);
                        res += temp;
                        temp = "";
                    }
                    res += line[i];
                }
                else {
                    temp += line[i];
                }
            }

            if(temp.size()) {
                string xx = "";
                for(int i = 0; i < temp.size(); i++) {
                    if(temp[i] == '\n') break;
                    xx += temp[i];
                }
                if(xx.size()) {
                  //  res += makeCode(xx);   // keyword or number or register.
                    temp = CodeFactory::createCode(temp);
                    res += temp;
                }
            }
            res += '\n';
            return res;
        }

        bool isValid(string st)
        {
            vector<string> valid = {"addx1,x1,x1\n", "lax1,x1\n", "ecall\n"};

            for(int i = 0; i < valid.size(); i++) {
                if(st == valid[i]) {
                    return 1;
                }
            }

            return 0;
        }

        string findInstruction(string st)
        {
            string temp = "";
            for(int i = 0; i < st.size(); i++) {
                if(st[i] == '#') {
                    temp += '\n';
                    break;
                }
                temp += st[i];
            }
            return temp;
        }

};
