#include <cctype>
#include <iostream>

int IsAlpha(char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        return (true);
    return (false);
}

char    ToUpper(char c)
{
    if (c > 96 && c < 123)
        return (c - 32);
    else
        return (c);
}

char    *StrToUpper(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (IsAlpha(str[i]) == true)
            str[i] = ToUpper(str[i]);           
        i++;
    }
    return(str);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
        std::cout << StrToUpper(argv[i]) << ' ';
    std::cout << std::endl;
}
