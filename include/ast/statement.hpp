#ifndef statement_hpp
#define statement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "context.hpp"
#include "ILinstr.hpp"

class Statement;
typedef const Statement *StatementPtr;

class Statement
{
  public:
	virtual ~Statement();
	friend std::ostream &operator<<(std::ostream &os, const Statement &statement);
	friend std::ostream &operator<<(std::ostream &os, const StatementPtr statementPtr);

	void printTree(std::ostream &os, int scopeDepth = 0) const;
	virtual void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const;
	void generatePython(std::ostream &os) const;

	void writeDotFile(std::string filePath = "bin/ast.dot") const;
	void writePrintCToFile(std::string filePath = "bin/printC.c") const;
	void writePythonToFile(std::string filePath = "bin/translated.py") const;
	void writeILToFile(std::string filePath = "bin/intermediateLanguage.txt") const;

	virtual void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const;
	void generateIL(std::vector<ILinstr> &instrs) const;
	void generateIL(std::ostream &os) const;

  protected:
	virtual void printC(std::ostream &os) const = 0; //prints c90 code so we can compare against input code //called in << overload
	std::string getGraphNodeID() const;
	virtual std::string getGraphNodeLabel() const;
	void generateTreeGraph(std::ostream &os) const;
	std::vector<StatementPtr> branches;
};

#endif
