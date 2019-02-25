#ifndef astStatement_hpp
#define astStatement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Statement;
typedef const Statement* StatementPtr;

class Statement
{
public:
	virtual ~Statement() { }
	friend std::ostream& operator<<(std::ostream& os, const Statement& statement);

private:
	virtual void printCode(std::ostream &os) const = 0; //called in << overload

protected:
	std::vector<StatementPtr> branches;
};

#endif
