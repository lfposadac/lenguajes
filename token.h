#pragma once
#include <string>
using namespace std;

enum TokenType {
    number,
    add,
    sub,
    times,
    divide,
    eof,
    unrecognized
};

class Token {
 public:
  Token();
  Token(TokenType typ);
  virtual ~Token();

  TokenType getType() const;
  virtual string getLex() const;

private:
  TokenType type;
  int line,col;
};

class LexicalToken: public Token {
 public:
   LexicalToken(TokenType typ, string* lex);
   ~LexicalToken();

   virtual string getLex() const;

 private:
   string* lexeme;
};