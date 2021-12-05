#include "token.h"

Token::Token() :
  type(eof)
{}

Token::~Token() {}

Token::Token(TokenType type) : 
  type(type)
{}

TokenType Token::getType() const {
  return type;
}

string Token::getLex() const { return ""; }

LexicalToken::LexicalToken(TokenType typ, string* lex) :
   Token(typ),
   lexeme(lex)
{}

LexicalToken::~LexicalToken() {
   try {
      delete lexeme;
   } catch (...) {}
}

string LexicalToken::getLex() const {
  return *lexeme;
}