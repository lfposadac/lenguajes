#include "scanner.h"
#include <iostream>
#include <string>
using namespace std;

int isNumber(string element) {
    for (char c: element)
        if (not isdigit(c)) 
            return false;
    return not element.empty();
}

Scanner::Scanner(stack<string> tokens):
  tokens(tokens),
  lastToken(new Token(unrecognized))
{}

Scanner::~Scanner() {
   try {
      //delete tokens;
   } catch (...) {}
}

void Scanner::putBackToken() {
   tokens.push(lastToken->getLex());
}

Token* Scanner::getToken() {
    Token* t;
    if (tokens.empty())
        t = new Token(eof);
    else{
        string token = tokens.top();
        tokens.pop();
        if (isNumber(token)) t = new LexicalToken(number, new string(token));
        else if (token == "+") t = new Token(add);
        else if (token == "-") t = new Token(sub);
        else if (token == "*") t = new Token(times);
        else if (token == "/") t = new Token(divide);
        else t = new LexicalToken(unrecognized, new string(token));
    }
    return lastToken = t;
}