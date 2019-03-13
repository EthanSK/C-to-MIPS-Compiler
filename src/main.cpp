#include <iomanip>
#include <map>
#include "ast.hpp"

//for testing
#include "scopeBlock.hpp"
#include "functionDefinition.hpp"
#include "functionParameterList.hpp"
#include "returnKeyword.hpp"

StatementPtr generateTestAST();


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
    std::cout << generateTestAST();
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
