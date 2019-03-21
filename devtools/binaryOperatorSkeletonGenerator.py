#to be run from project root
import shutil, os

binaryOperatorPath = "ast/operators/binaryOperators/"
hppPath = "include/" + binaryOperatorPath
cppPath = "src/" + binaryOperatorPath

lowerCaseFirstLetter = lambda s: s[:1].lower() + s[1:] if s else ''


def createHPP(op_name, symbol, py_symbol):
    f = open(hppPath + "binary" + op_name + ".hpp", "w")
    to_write = open('devtools/binaryHPPtemplate.txt', 'r').read() % (op_name, op_name, op_name)
    f.write(to_write)

def createCPP(op_name, symbol, py_symbol, opcode):
    lbracket = "\n	os << \"(\";"
    rbracket = "\n	os << \")\";"
    symbols = [op_name, op_name, lbracket, symbol, rbracket, op_name, lbracket, py_symbol, rbracket]
    symbols_il = [op_name, opcode]
    if "Assignment" in op_name: #makes no sense to have (int x = 5) [coz in brackets]
        symbols[2] = ""
        symbols[4] = ""
        symbols[6] = ""
        symbols[8] = ""

    f = open(cppPath + "binary" + op_name + ".cpp", "w")
    to_write = open('devtools/binaryCPPtemplate.txt', 'r').read() % tuple(symbols)
    to_write_il = open('devtools/binOpSkelGenIL.txt', 'r').read() % tuple(symbols_il)
    if "Assignment" in op_name:
        to_write_il = open('devtools/binOpSkelGenILAssignment.txt', 'r').read() % tuple(symbols_il)


    f.write(to_write + to_write_il)

if (os.path.isdir(hppPath)):
    shutil.rmtree(hppPath)
if (os.path.isdir(cppPath)):
    shutil.rmtree(cppPath)
os.mkdir(hppPath)
os.mkdir(cppPath)

txt_file = open("devtools/binaryNames.txt", "r")

for line in txt_file.read().splitlines():
    split_line = line.split()

    op_name = split_line[0]
    opcode = split_line[1]
    symbol = split_line[2]
    py_symbol = symbol
    if len(split_line) > 3:
        py_symbol = split_line[3] #if the no. of elements on the line >2, we have a special python symbol, eg 'and' and 'or'

    print('operator name: ' + op_name + ', symbol: ' + symbol)
    createHPP(op_name, symbol, py_symbol)
    createCPP(op_name, symbol, py_symbol, opcode)
txt_file.close()

