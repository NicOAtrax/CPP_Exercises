#include <iostream>

int main()
{
    using namespace std;
    string var = "";
    while (var != "q" && var != "quit" && var != "e" && var != "exit")
    {
        cout << "Enter something : " << std::endl;
        cin >> var;
    }

    return 0;
}