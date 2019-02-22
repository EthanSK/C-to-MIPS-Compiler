#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

class Variable : public Expression
{
private:
    std::string id;

public:
    Variable(const std::string &_id) : id(_id) { }

    const std::string getId() const { return id; }
    virtual void print(std::ostream &dst) const override { dst << id; }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        // TODO-B : Run bin/eval_expr with a variable binding to make sure you understand how this works.
        // If the binding does not exist, this will throw an error
        return bindings.at(id);
    }
};

class Number : public Expression
{
private:
    double value;

public:
    Number(double _value) : value(_value) { }

    double getValue() const { return value; }
    virtual void print(std::ostream &dst) const override { dst << value; }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        // TODO-A : Run bin/eval_expr with a numeric expression to make sure you understand how this works.
        return value;
    }
};


#endif
