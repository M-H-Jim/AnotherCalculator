#include "ExpressionParser.h"

#include <string>
#include <vector>
#include <stack>

/**
*
*   -This is my implementation of the 'shunting yard algorithm'.
*   -postfix() function converts the infix expression into a postfix notation using the algorithm
*   -answer() function just calculates the postfix expression.
*
**/


using namespace std;

POSTFIX_AND_CHECK postfix(string express) {

    POSTFIX_AND_CHECK First;

    string expression = express;

	stack<char> operators;
	vector<char> num;

	short check1 = 0, check2 = 10, countB = 0;

	char characters [19] = "0123456789 +-*/(.)";

	for(unsigned i = 0; i < expression.length(); i++) {

		for(short j = 0; j < 18; j++)
			if(expression[i] == characters[j]) {
				check2 = 0;
				break;
			}

		if(check2 == 10) break;

		if(expression[i] == ' ') continue;

		else if(isdigit(expression[i]) || expression[i] == '.') {

			num.push_back(expression[i]);

		}     // push integers...
		else {

			if(!num.empty()) {
				string str(num.begin(), num.end());
				First.output.push_back(str);
				num.clear();
			}

			if(expression[i] == '(') {
				operators.push(expression[i]);
				countB++;
			}

			else if(expression[i] == ')') {

				if(countB == 0) {
					check1 = 1;
					break;
				}
				while(operators.top() != '(') {
					First.output.push_back(string(1, operators.top()));
					operators.pop();
				}
				operators.pop(); countB--;
			}

			else {

				if(operators.empty()) operators.push(expression[i]);
				else {

					while(true) {

						if(expression[i] == '*' || expression[i] == '/') {
							if(operators.top() == '*' || operators.top() == '/') {
								First.output.push_back(string(1, operators.top()));
								operators.pop();
								if(operators.empty()) {
									operators.push(expression[i]);
									break;
								}
							}
							else {
								operators.push(expression[i]);
								break;
							}
						}
						else if(expression[i] == '+' || expression[i] == '-') {

							if(operators.empty()) {
								operators.push(expression[i]);
								break;
							}

							else if(operators.top() == '(') {
								operators.push(expression[i]);
								break;
							}
							else {
								First.output.push_back(string(1, operators.top()));
								operators.pop();
								if(operators.empty()) {
									operators.push(expression[i]);
									break;
								}
							}
						}
					}
				}
			}
		}

	}


	if (!num.empty()) {
		string str(num.begin(), num.end());
		First.output.push_back(str);
		num.clear();
	}


	while(!operators.empty()) {
		First.output.push_back(string(1, operators.top()));
		operators.pop();
	}

	First.chk1 = check1 + check2;

	return First;

}


RESULT_AND_CHECK answer(vector<string> output) {

    RESULT_AND_CHECK Second;

    short check = 0;		// 1(stack size < 2), 2(divide by zero), 3(invalid expression)

	for(unsigned i = 0; i < output.size(); i++) {
        int dotCount = 0;
        for(unsigned j = 0; j < output[i].size(); j++)
            if(output[i][j] == '.')
                dotCount++;

        if(dotCount > 1) {
            check = 3;
            break;
        }

		if(isdigit(output[i].front())) {
			Second.result.push(stod(output[i]));
		}
		else {
			if(Second.result.size() < 2) {
				check = 1;
				break;
			}
			else {
				double right  = Second.result.top();
				Second.result.pop();
				double left = Second.result.top();
				Second.result.pop();

				double value = 0;

				switch(output[i][0]) {

					case '+': value = left + right; break;
					case '-': value = left - right; break;
					case '*': value = left * right; break;
					case '/':
							  if(right == 0) {
								  check = 2;
								  break;
							  }
							  else {
								  value = left / right;
								  break;
							  }
				}
				if(check == 0) Second.result.push(value);
			}
		}
		if(check != 0) break;
	}

	if(Second.result.size() != 1) check = 3;

	Second.chk2 = check;

	return Second;

}

