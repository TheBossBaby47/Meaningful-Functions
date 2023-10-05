#include <iostream>
#include <map>

namespace NCL
{
    void Product(const int Add, const int Minus)
    {
        std::cout << "Product of " << Add << " and " << Minus << " is : " << Add * Minus << '\n';
    }

    double Quotient(const double InDividend, const int InDivisor)
    {
        return InDividend / InDivisor;
    }

    int Add(const int InOperandLeft, const int InOperandRight)
    {
        return InOperandLeft + InOperandRight;
    }

    int Substract(const int InOperandLeft, const int InOperandRight)
    {
        return InOperandLeft - InOperandRight;
    }

    int Multiply(const int InOperandLeft, const int InOperandRight)
    {
        return InOperandLeft * InOperandRight;
    }

    int Division(const int InDividend, const int InDivisor)
    {
        return InDividend / InDivisor;
    }

    int Calculator(const int InOperandLeft, const int InOperandRight, const char InOperator)
    {
        switch (InOperator)
        {
        case '+':
            return Add(InOperandLeft,InOperandRight);
            break;
        case '-':
            return Substract(InOperandLeft,InOperandRight);
            break;
        case '*':
            return Multiply(InOperandLeft,InOperandRight);
            break;
        case '/':
            return Division(InOperandLeft,InOperandRight);
            break;
        default:
            std::cout << "Invalid operator returning -1\n";
            return -1;
            break;
        }
    }

    enum ArithmaticOperationsEnum {
        ADD = 0,
        SUBSTRACT,
        PRODUCT,
        DIVISION,
        MAXOPERARTION
    };

    int CalculatorFunctionPointer(const int InOperandLeft, const int InOperandRight, const char InOperator)
    {
        int (*AritmaticOperations[4])(const int, const int) = { NCL::Add, NCL::Substract, NCL::Multiply, NCL::Division };

        std::map<char, ArithmaticOperationsEnum> OperationsMap;
        OperationsMap.insert({ '+', ArithmaticOperationsEnum::ADD });
        OperationsMap.insert({ '-', ArithmaticOperationsEnum::SUBSTRACT });
        OperationsMap.insert({ '*', ArithmaticOperationsEnum::PRODUCT });
        OperationsMap.insert({ '/', ArithmaticOperationsEnum::DIVISION });

        if (!OperationsMap.count(InOperator))
        {
            std::cout << "Invalid operator returning -1\n";
            return -1;
        }
        return AritmaticOperations[OperationsMap.find(InOperator)->second](InOperandLeft, InOperandRight);
    }

}


int main()
{
    int (*AritmaticOperations[4])(const int, const int) = { NCL::Add, NCL::Substract, NCL::Multiply, NCL::Division };

    NCL::Product(5, 3);
    int A, B;
    char Operator;

    std::cin >> A >> B >> Operator;
    std::cout << A << ' ' << Operator << ' ' << B << " = " << NCL::CalculatorFunctionPointer(A,B,Operator) << "\n";

    return 0;
}