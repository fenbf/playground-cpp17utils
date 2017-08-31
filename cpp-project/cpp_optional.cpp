#include <optional>
#include <iostream>
#include <string>

std::optional<int> GetInt(int r)
{
    if (r % 2 == 0)
        return r/2;
    
    return { };
}

void ShowOptionalInt(const std::optional<int>& oi)
{
    if (oi)
        std::cout << "int ok: " << *oi << "\n";
    else
        std::cout << "bad int...\n";
}
 
int main()
{
    std::cout << sizeof(int) << ", " << sizeof(std::optional<int>) << "\n";
    std::cout << sizeof(double) << ", " << sizeof(std::optional<double>) << "\n";
    std::cout << sizeof(std::string) << ", " << sizeof(std::optional<std::string>) << "\n";
    auto oi = GetInt(10);
    ShowOptionalInt(oi);
    auto oi2 = GetInt(11);
    ShowOptionalInt(oi2);
}