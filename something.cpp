# include"something.h"
# include"iostream"
Color i2c(int num)
{
    switch (num % 4)
    {
        case 0: return red;
        case 1: return green;
        case 2: return blue;
        case 3: return yellow;
    }
}

void outInfo(int num)
{
    switch (num % 4)
    {
        case 0:     std::cout << "   Red ";   break;
        case 1:     std::cout << " Green "; break;
        case 2:     std::cout << "  Blue ";  break;
        case 3:     std::cout << "Yellow "; break;
        default :   std::cout << "  None ";
    }
}
