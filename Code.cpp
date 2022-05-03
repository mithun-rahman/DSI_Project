#include<bits/stdc++.h>

using namespace std;

class Code
{
    public:
        virtual bool isNumber(string word)      = 0;
        virtual string makeKey(string st)       = 0;
        virtual bool keyWord(string st)         = 0;
        virtual string makeRegister(string st)  = 0;
};

class makeCode:public Code
{
    public:
        // Checking for number
        bool isNumber(string st)
        {
            int cnt, pnt;
            cnt = pnt = 0;
            for(int i = 0; i < st.size(); i++) {
                if(st[i] >= '0' && st[i] <= '9') cnt += 1;
                else if(st[i] == '.') pnt++;
            }
            if(cnt == st.size()) return 1;
            else if((cnt+1 == st.size()) && pnt == 1) return 1;
            return 0;
        }

        string makeKey(string st)   // Converting key.
        {
            if(st == "add" || st == "addi") return "add";
            else if(st == "sub" || st == "subi") return "add";
            else if(st == "la" || st == "li") return "la";
            else if(st == "ecall") return "ecall";
            return "dummmy";
        }

        bool keyWord(string st)    // Checking for keyword.
        {
            st = makeKey(st);
            if(st == "add" || st == "sub" || st == "ecall" || st == "la") return 1;
            return 0;
        }

        string makeRegister(string st)
        {
            set<string> operand = {"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13",
                       "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26",
                       "x27", "x28", "x29", "x30", "x31", "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0",
                       "fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6",
                       "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

            if(operand.find(st) != operand.end()) return "x1";
            if(isNumber(st)) return "x1";
            return "dummy";
        }

};
