#pragma once
#include <stack>
#include <string>
#include "scanner.h"

class Parser {
 public:
    Parser(stack<string> tokens);
    ~Parser();
    bool parse();
    int eval();
 private:
    Scanner* scan;
    int val;
};