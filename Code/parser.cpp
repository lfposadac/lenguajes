#include <string>
#include <sstream>
#include <iostream>
#include "parser.h"
using namespace std;

enum Exception{
    ParserError,
    Unrecognized,
    ZeroDivision
};

Parser::Parser(stack<string> tokens) {
    scan = new Scanner(tokens);
}

Parser::~Parser() {
  try {
    delete scan;
  } catch (...) {}
}

bool Parser::parse() {
    Token* t;
    stack<int> nums;
    do{
        t = scan->getToken();
        if (t->getType() == number) nums.push(stoi(t->getLex()));
        else if (t->getType() == unrecognized) {
            cerr << "* unrecognized token: " << t->getLex() << endl;
            throw Unrecognized;
        }
        else if (nums.size() > 1){
            int a,b;
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            if (t->getType() == add) nums.push(a+b);
            else if (t->getType() == sub) nums.push(a-b);
            else if (t->getType() == times) nums.push(a*b);
            else if (t->getType() == divide) {
                if (a) nums.push(a/b);
                else { 
                    cerr << "* zero division" << endl;
                    throw ZeroDivision;
                }
            }
        } else if (t->getType() != eof) {
            cerr << "* parser error" << endl;   
            throw ParserError;
        }
    }while (t->getType() != eof);
    val = nums.top();
    return nums.size() == 1;
}

int Parser::eval(){
    return val;
}
