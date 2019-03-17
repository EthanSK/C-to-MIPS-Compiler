#include <iomanip>
#include <map>

//for testing
#include "test.hpp"

StatementPtr generateTestAST();
StatementPtr generateTestFragment();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    // Parse the AST
    yyin = fopen("test/testProgram.c", "r"); //default value for dev

    if (argc >= 5 && std::string(argv[1]) == "-S")
    {
         yyin = fopen(argv[2], "r");
    }

    StatementPtr ast = parseAST();
    //std::cin << "int a = 5;";
    //std::cout << ast << std::endl;

    //testing
    PythonContext context;
    //StatementPtr ast = generateTestFragment();
    std::cout << "\n\nC CODE\n======================\n";
    std::cout << ast << std::endl;
    ast->writePrintCToFile();

    std::cout << "\n\nPYTHON CODE\n======================\n";
    ast->generatePython(std::cout, context);

    if (argc >= 5 && std::string(argv[1]) == "--translate")
    {
        ast->writePythonToFile(context, std::string(argv[4]));
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

StatementPtr generateTestAST()
{

    // StatementPtr ast = new PrimitiveType(PrimitiveType::_int);// works by itself

    StatementPtr ast = new ScopeBlock({new FunctionDefinition(
        new PrimitiveType(PrimitiveType::_int),
        "main",
        new FunctionParameterList(std::vector<StatementPtr>()),
        new ScopeBlock(
            std::vector<StatementPtr>()))});

    return ast;
}

StatementPtr generateTestFragment()
{
<<<<<<< HEAD
    StatementPtr ast = new ScopeBlock({
        new FunctionDefinition(
        new PrimitiveType(PrimitiveType::_int),
        "main",
        new FunctionParameterList(std::vector<StatementPtr>()),
        new ScopeBlock({
            new BinaryAssignment(new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "x"), new IntegerLiteral(2)),
            new IfElseStatement(
                new BinaryGreaterThanOrEqualTo(new DoubleLiteral(10), new BinaryAdd(new IntegerLiteral(7), new FloatLiteral(7.7f))),
                new ScopeBlock({
                    new BinaryIsEqualTo(new StringLiteral("pink"), new StringLiteral("purple"))
                }),
                new ScopeBlock({
                    new IfElseStatement(
                        new BinaryLessThanOrEqualTo(new DoubleLiteral(3), new BinaryAdd(new DoubleLiteral(1.374), new FloatLiteral(7.7f))),
                        new ScopeBlock({
                            new BinaryIsNotEqualTo(new StringLiteral("lost"), new StringLiteral("dizzy"))
                        }),
                        new ScopeBlock({
                                new BinaryAssignment(new VariableReference("x"), new IntegerLiteral(42))
                        }))
                }))
            })
        )
    });
=======
    StatementPtr ast = new ScopeBlock({new BinaryAssignment(new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "x"), new IntegerLiteral(2)),
                                       new IfElseStatement(
                                           new BinaryGreaterThanOrEqualTo(new DoubleLiteral(10), new BinaryAdd(new IntegerLiteral(7), new FloatLiteral(7.7f))),
                                           new ScopeBlock({new BinaryIsEqualTo(new StringLiteral("pink"), new StringLiteral("purple"))}),
                                           new ScopeBlock({new IfElseStatement(
                                               new BinaryLessThanOrEqualTo(new DoubleLiteral(3), new BinaryAdd(new DoubleLiteral(1.374), new FloatLiteral(7.7f))),
                                               new ScopeBlock({new BinaryIsNotEqualTo(new StringLiteral("lost"), new StringLiteral("dizzy"))}),
                                               new ScopeBlock({new BinaryAssignment(new VariableReference("x"), new IntegerLiteral(42))}))}))});
>>>>>>> develop

    return ast;
}
