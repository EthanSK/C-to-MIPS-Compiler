#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

class Operator : public Expression
{
protected:
    ExpressionPtr left;
    ExpressionPtr right;

    Operator(ExpressionPtr _left, ExpressionPtr _right) : left(_left) , right(_right) { }

public:
    virtual const char *getOpcode() const = 0;

    ExpressionPtr getLeft() const { return left; }
    ExpressionPtr getRight() const { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst << "( ";
        left->print(dst);
        dst << " ";
        dst << getOpcode();
        dst << " ";
        right->print(dst);
        dst << " )";
    }
};

class AddOperator : public Operator
{
protected:
    virtual const char *getOpcode() const override { return "+"; }

public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right) : Operator(_left, _right) { }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        return left->evaluate(bindings) + right->evaluate(bindings);
    }
};

class SubOperator: public Operator
{
protected:
    virtual const char *getOpcode() const override { return "-"; }

public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right) : Operator(_left, _right) { }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        return left->evaluate(bindings) - right->evaluate(bindings);
    }
};


class MulOperator : public Operator
{
protected:
    virtual const char *getOpcode() const override { return "*"; }

public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right) : Operator(_left, _right) { }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        return left->evaluate(bindings) * right->evaluate(bindings);
    }
};

class DivOperator : public Operator
{
protected:
    virtual const char *getOpcode() const override { return "/"; }

public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right) : Operator(_left, _right) { }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        return left->evaluate(bindings) / right->evaluate(bindings);
    }
};

class ExpOperator : public Operator
{
protected:
    virtual const char *getOpcode() const override { return "^"; }

public:
    ExpOperator(ExpressionPtr _left, ExpressionPtr _right) : Operator(_left, _right) { }

    virtual double evaluate(const std::map<std::string,double> &bindings) const override
    {
        return pow(left->evaluate(bindings), right->evaluate(bindings));
    }
};


#endif
