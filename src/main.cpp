#include <iomanip>
#include <map>
#include "ast.hpp"

//for testing
#include "scopeBlock.hpp"
#include "ifElseStatement.hpp"
#include "binaryGreaterThanOrEqualTo.hpp"
#include "binaryAdd.hpp"
#include "floatLiteral.hpp"
#include "doubleLiteral.hpp"
#include "integerLiteral.hpp"
#include "functionDefinition.hpp"
#include "functionParameterList.hpp"
#include "returnKeyword.hpp"

StatementPtr generateTestAST();
StatementPtr generateTestFragment();


int main(int argc, char *argv[])
{
    std::map<std::string, double> bindings;

    // Grab the pairs of bindings from argv
    for (int i = 1; i < argc - 1; i += 2)
    {
        bindings.insert(std::make_pair(argv[i], strtod(argv[i + 1], 0)));
    }

    // Parse the AST
    // StatementPtr ast = parseAST();
    // std::cout << ast << std::endl;
    
    //testing
    PythonContext context;
    StatementPtr ast = generateTestFragment();
    std::cout << "\n\nC CODE\n======================\n";
    std::cout << ast;
    std::cout << "\n\nPYTHON CODE\n======================\n";
    ast->generatePython(std::cout, context);
    std::cout << std::endl;

    return 0;
}

StatementPtr generateTestAST()
{
    StatementPtr ast = new ScopeBlock({
        new FunctionDefinition(
            PrimitiveType::_int,
            "main",
            new FunctionParameterList(std::vector<StatementPtr>()),
            new ScopeBlock(
                std::vector<StatementPtr>()
                ))
    });

    return ast;
}

StatementPtr generateTestFragment()
{
    StatementPtr ast = new ScopeBlock({
        new IfElseStatement(
            new BinaryGreaterThanOrEqualTo(new DoubleLiteral(10), new BinaryAdd(new IntegerLiteral(7), new FloatLiteral(7.7f))),
            new ScopeBlock({
                
            }),
            new ScopeBlock({

            }))
    });

    return ast;
}
