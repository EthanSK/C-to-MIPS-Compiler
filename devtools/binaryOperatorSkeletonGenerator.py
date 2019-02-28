#to be run from project root




def createHPP(op_name, symbol ):
    f = open("include/ast/operators/binaryOperators/binary" + op_name + ".hpp", "w")
    to_write = open('devtools/binaryHPPtemplate.txt', 'r').read() % (op_name, op_name, op_name)
    f.write(to_write)

def createCPP(op_name, symbol):
    f = open("src/ast/operators/binaryOperators/binary" + op_name + ".cpp", "w")
    to_write = open('devtools/binaryCPPtemplate.txt', 'r').read() % (op_name, op_name, symbol)
    f.write(to_write)

txt_file = open("devtools/binaryNames.txt", "r")

for line in txt_file.read().splitlines():
    op_name = line.split()[0]
    symbol = line.split()[1]
    print('operator name: ' + op_name + ', symbol: ' + symbol)
    createHPP(op_name, symbol)
    createCPP(op_name, symbol)
txt_file.close()

