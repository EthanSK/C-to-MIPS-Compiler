#include "arrayInitDeclarator.hpp"
#include "initializerList.hpp"
#include "utils.hpp"
#include "rvalue.hpp"

void ArrayInitDeclarator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    InitializerListPtr initList = Utils::tryCast<InitializerList>(getInitializer(), "arrays cannot be initialized with normal initializers and require an initializer list");
    std::vector<StatementPtr> initializers = initList->getElements();

    instrs.push_back(Instr("decla", getIdentifierName(), std::to_string(initializers.size() * 4)));
    if (initList->isConstant())
    {
        Instr instr("inita", getIdentifierName());
        for (size_t i = 0; i < initializers.size(); ++i)
        {
            RValuePtr rvalue = Utils::tryCast<RValue>(initializers[i], "non rvalue cannot be used to initialize array element");
            instr.extraData.push_back(std::to_string(rvalue->evalConst()));
        }

        instrs.push_back(instr);
    }
}