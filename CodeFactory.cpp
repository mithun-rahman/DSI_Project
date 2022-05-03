#include<bits/stdc++.h>

using namespace std;

#include "Code.cpp"

class CodeFactory
{
    public:
        static string createCode(string word)
        {
            Code *code = new makeCode;

            if(code->keyWord(word)) {
                word = code->makeKey(word);
            }
            else {
                word = code->makeRegister(word);
            }

            return word;
        }
};
