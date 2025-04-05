
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void InData(int& Number);

class Fraction
{
public:
    Fraction(int a = 1, int b = 1) : Numenator(a), Denominator(b), Result (1)
    {
        Result = float(Numenator) / float(Denominator);
        std::cout << "Your fraction is : " << "\n";
        std::cout << Numenator << "/" << Denominator << " = " << Result << "\n";
    }
    float GetResult() const
    {
        return Result;
    }

private:
    int Numenator;
    int Denominator;
    float Result;
    
};

void MakingFraction()
{

        int Numenator = 1;
        int Denominator = 1;
        std::cout << "Enter Numenator = ";
        InData(Numenator);

        if (Numenator == 0)
            throw std::runtime_error("Please use only correct numbers");

        std::cout << "Enter Denominator = ";
        InData(Denominator);

        if (Denominator == 0)
            throw std::runtime_error("Denominator can't be made zero!");

        Fraction New(Numenator, Denominator);
    
}

void InData(int& Number)
{
    
        std::cin >> Number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(30000, '\n');

            throw std::runtime_error("Only numbers will do");
        }
        
    
}

void DoAgain(bool& again)
{
    std::cout << "Do you want to try again y/n?";
    while (true)
    {
        
        char YesNo;
        std::cin >> YesNo;
        if (YesNo == 'y')
        {
            again = true;
            break;
        }
        if (YesNo == 'n')
        {
            std::cout << "OK" << "\n";
            again = false;
            break;
        }
        std::cout << "Come again?" << '\n';
        std::cin.clear();
        std::cin.ignore(30000, '\n');
    }
}

// Main programme

int main()
{
    
    std::cout << "Make a fraction" << "\n";

    bool Again = false;

    do
    {
        try 
        {
            MakingFraction();
            DoAgain(Again);
        }

        
        catch (const std::runtime_error& ex)
        {
            std::cout << ex.what() << "\n";
            DoAgain(Again);
            
        }
       
    } while (Again);

    return 0;

}

