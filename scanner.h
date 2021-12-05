#pragma once
#include <stack>
#include <string>
#include "token.h"
using namespace std;

class Scanner {
public:
  Scanner(stack<string> tokens);
  ~Scanner();

  Token* getToken();
  void putBackToken();
 
private:
  Scanner();
  stack<string> tokens;
  Token* lastToken;
};