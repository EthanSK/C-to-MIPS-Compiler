#include <iomanip>
#include <map>

//for testing
#include "headers.hpp"

StatementPtr generateTestAST();
StatementPtr generateTestFragment();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    bool isTranslatingToPython = false;
    // Parse the AST
    yyin = fopen("test/parser/testProgram.c", "r"); //default value for dev

    if (argc >= 5 && std::string(argv[1]) == "-S")
    {
         yyin = fopen(argv[2], "r");
    }

     if (argc >= 5 && std::string(argv[1]) == "--translate")
    {
        isTranslatingToPython = true;
        yyin = fopen(argv[2], "r");
    }

    StatementPtr ast = parseAST();

    std::cout << "\n\nC CODE\n======================\n";
    std::cout << ast << std::endl;
    ast->writePrintCToFile();


    if (isTranslatingToPython)
    {
        PythonContext context;
        std::cout << "\n\nPYTHON CODE\n======================\n";
        ast->generatePython(std::cout, context);
        ast->writePythonToFile(context, std::string(argv[4]));
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

StatementPtr generateTestAST()
{

    // StatementPtr ast = new PrimitiveType(PrimitiveType::_int);// works by itself

    StatementPtr ast = new ScopeBlock(new FunctionDefinition(
        new PrimitiveType(PrimitiveType::_int),
        "main",
        new FunctionParameterList(std::vector<StatementPtr>()),
        new ScopeBlock(
            std::vector<StatementPtr>())));

    return ast;
}

StatementPtr generateTestFragment()
{
    StatementPtr ast = new RootNode(
        new SequenceBlock({

            new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "y"),
            new BinaryAssignment(new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "z"), new IntegerLiteral(2)),
            
            new FunctionDefinition(
            new PrimitiveType(PrimitiveType::_int),
            "blankFunc",
            new FunctionParameterList({new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "input")}),
            new ScopeBlock()),

            new FunctionDefinition(
            new PrimitiveType(PrimitiveType::_int),
            "someFunc",
            new FunctionParameterList({new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "input")}),
            new ScopeBlock({
                new WhileLoop(
                    new BinaryLessThan(new VariableReference("input"), new IntegerLiteral(10)),
                    new ScopeBlock(
                        new BinaryAddAssignment(new VariableReference("input"), new IntegerLiteral(1))
                    )),
                new ReturnKeyword(new VariableReference("input"))
            })),

            new FunctionDefinition(
            new PrimitiveType(PrimitiveType::_int),
            "main",
            new FunctionParameterList(std::vector<StatementPtr>()),
            new ScopeBlock({
                new BinaryAssignment(new VariableDeclaration(new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int), "x"), new IntegerLiteral(2)),
                new IfElseStatement(
                    new BinaryGreaterThanOrEqualTo(new DoubleLiteral(10), new BinaryAdd(new IntegerLiteral(7), new FloatLiteral(7.7f))),
                    new ScopeBlock(
                        new BinaryIsEqualTo(new StringLiteral("pink"), new StringLiteral("purple"))
                    ),
                    new ScopeBlock(
                        new IfElseStatement(
                            new BinaryLessThanOrEqualTo(new DoubleLiteral(3), new BinaryAdd(new DoubleLiteral(1.374), new FloatLiteral(7.7f))),
                            new ScopeBlock(
                                new BinaryIsNotEqualTo(new StringLiteral("lost"), new StringLiteral("dizzy"))
                            ),
                            new ScopeBlock({
                                    new BinaryAssignment(new VariableReference("x"), new IntegerLiteral(42)),
                                    new BinaryAssignment(new VariableReference("y"), new FunctionCall("someFunc", new FunctionParameterList({new VariableReference("z")})))
                            }))
                    )),
                    new ReturnKeyword(new IntegerLiteral(10))
                })
                
            )
        })
    );

    return ast;
}
