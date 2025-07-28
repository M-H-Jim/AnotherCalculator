#pragma once

#include <string>
#include <vector>
#include <stack>

using namespace std;

struct POSTFIX_AND_CHECK {
    vector<string> output;
    short chk1;
};

struct RESULT_AND_CHECK {
    stack<double> result;
    short chk2;
};


POSTFIX_AND_CHECK postfix(string expression);

RESULT_AND_CHECK answer(vector<string> output);
