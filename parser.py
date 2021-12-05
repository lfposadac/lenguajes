import re
import sys
#gramatica
defi = r"(\s*(real|leer|mostrar|int)\s+\w+\s*)"
iden = r"\s*\w+\s*"
valu = rf"({iden}|\s*\d+\s*)"
asig = rf"({iden}={valu}(\+|\-|\*|\/){valu})"
call = rf"(llamar\s+{iden}\(({valu}(\s{valu})*)*\))"
line = rf"({defi}|{asig}|{call})$"
sign = rf"(funcion\s+{iden}\s*\(({defi}(\s+{defi})*)*\))$"

def parse_ins(text_line):
    if not text_line:
        return True
    elif re.fullmatch(line, text_line):
        return True
    else: 
        print("error in line: ", text_line)
        return False

def parse_func(stream):
    text_line = stream.readline().strip()
    while (not re.fullmatch(r"finfuncion\s*$", text_line)) and parse_ins(text_line):
        text_line = stream.readline().strip()
    if re.fullmatch(r"finfuncion\s*$", text_line):
        return True
    else:
        return False

def parse_code(stream):
    text_line = stream.readline().strip()
    while not text_line:
        if text_line is None:
            return True
        text_line = stream.readline().strip()

    if not re.fullmatch(r"codigo\s*$", text_line):
        print("code not open (expected 'codigo'): ", text_line)
        return False
    text_line = stream.readline().strip()
    while text_line or text_line == "":
        text_line = str(text_line).strip()
        if re.fullmatch(sign, text_line):
            if not parse_func(stream):
                return False
        elif text_line and re.fullmatch(r"fincodigo\s*$", text_line):
            return True
        elif text_line:
            print("code not closed (expected 'fincodigo')")
            return False
        text_line = next(stream, "EOF")
    return False

def read(file_name):
    with open(file_name,'r') as file:
        if parse_code(file):
            print("Correct")
        else:
            print("Wrong")

if __name__ == "__main__":
    if len(sys.argv) == 2:
        read(sys.argv[1])
    else:
        print("wrong args")