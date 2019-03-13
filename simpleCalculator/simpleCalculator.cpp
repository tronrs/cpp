/*
Simple Calculator
Operators:
  +, -, /, *
Author:
  Ryan Citron
Date:
  3/13/2019
*/

#include <iostream>

using namespace std;

void doMath(char,float,float);
char getOp();
float getNum();

int main(){

  char op;
  float num1, num2;

  op = getOp();           // Get operator
  num1 = getNum();        // Get the first number
  num2 = getNum();        // Get the second number
  doMath(op, num1, num2); // Solve

  return 0;
}

/*
doMath takes in an operator and two floating point numbers. It then uses a
switch case to check which operator has been chosen. Once the correct operator
is found it then does the math and prints it out to the console.
*/
void doMath(char op, float num1, float num2){

  cout << "\nYour answer is:\n";

  switch(op){

    case '+':
      cout << num1 + num2;
      break;

    case '-':
      cout << num1 - num2;
      break;

    case '*':
      cout << num1 * num2;
      break;

    case '/':
      if(num2 == 0) cout << "Cannot divide by zero!";
      else cout << num1 / num2;
      break;
    default:
      cout << "Something went wrong!";
      break;
  }
  cout << "\n";
}

/*
getOp asks the user for an operator. The default operator used is addition
if a wrong operator was picked.
*/
char getOp(){
  char op = '+';

  cout << "Enter an operator! If not a choice the operator\n"
   << " will default to addition.\n+, -, *, /\n";

  cin >> op;

  // If the inputed operator is correct return that op.
  if(op == '+' || op == '-' || op == '*' || op == '/') return op;

  // If no, return addition.
  op = '+';
  return op;
}

/*
getNum() asks the user for a number.
*/
float getNum(){
  int num;

  cout << "\nThanks!\nEnter a number!\n";
  cin >> num;

  return num;
}
