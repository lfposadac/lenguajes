#include <iostream>
#include <stack>
#include <stdlib.h>
#include <sstream>
#include "parser.h"

using namespace std;
void eval(stack<string> tokens){
    try{
        Parser parser(tokens);
        if (parser.parse())
            cout << "= " << parser.eval() << endl;
    } catch (...){}
}

int main() {

    cout <<"Escriba la expresión y termine con <EOL>: " << endl;
    while(true){
        cout << "> ";
        string expresion;
        getline(cin, expresion);
        cout << endl;

        //vamos a usar pilas para luego hacer una evaluación desde
        //lo más simple a lo más complejo
        stack<string> tokens;
        istringstream cadena_elementos(expresion);
        
        char separador = ' ';
        string elemento;
        while (getline(cadena_elementos,elemento, separador))
            tokens.push(elemento);

        eval(tokens);
    }
    return EXIT_SUCCESS;
}