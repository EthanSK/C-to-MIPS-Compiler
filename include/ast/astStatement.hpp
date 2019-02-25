#ifndef astStatement_hpp
#define astStatement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Statement;
typedef std::unique_ptr<Statement> StatementPtr;

class Statement
{
public:
	virtual ~Statement() { }
	virtual void printCode(std::ostream &os) const = 0;

protected:
	std::vector<StatementPtr> branches;
};

#endif
