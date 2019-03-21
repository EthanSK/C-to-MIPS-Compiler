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

def createCPP(op_name, symbol, py_symbol):
    lbracket = "\n	os << \"(\";"
    rbracket = "\n	os << \")\";"
    symbols = [op_name, op_name, lbracket, symbol, rbracket, op_name, lbracket, py_symbol, rbracket, op_name, lowerCaseFirstLetter(op_name)]
    if "Assignment" in op_name: #makes no sense to have (int x = 5) [coz in brackets]
        symbols[2] = ""
        symbols[4] = ""
        symbols[6] = ""
        symbols[8] = ""

    f = open(cppPath + "binary" + op_name + ".cpp", "w")
    to_write = open('devtools/binaryCPPtemplate.txt', 'r').read() % tuple(symbols)
    f.write(to_write)

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
    symbol = split_line[1]
    py_symbol = symbol
    if len(split_line) > 2:
        py_symbol = split_line[2] #if the no. of elements on the line >2, we have a special python symbol, eg 'and' and 'or'

    print('operator name: ' + op_name + ', symbol: ' + symbol)
    createHPP(op_name, symbol, py_symbol)
    createCPP(op_name, symbol, py_symbol)
txt_file.close()

