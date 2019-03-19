#ifndef statement_hpp
#define statement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "context.hpp"

class Statement;
typedef const Statement *StatementPtr;

class Statement
{
  public:
	virtual ~Statement();
	friend std::ostream &operator<<(std::ostream &os, const Statement &statement);
	friend std::ostream &operator<<(std::ostream &os, const StatementPtr statementPtr);

	virtual void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const
	{
		os << "[Not Supported: " << typeid(*this).name() << "]";
	}
	void generatePython(std::ostream &os) const
	{
		PythonContext pyContext;
		generatePython(os, pyContext);
	}

	void writePrintCToFile(std::string filePath = "bin/printC.c") const; //can't use for write python because whats output is different
	void writePythonToFile(std::string filePath = "bin/translated.py") const;

  protected:
	virtual void printC(std::ostream &os) const = 0; //prints c90 code so we can compare against input code //called in << overload

  protected:
	std::vector<StatementPtr> branches;
};

#endif
