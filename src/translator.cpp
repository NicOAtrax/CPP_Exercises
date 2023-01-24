#include <iostream>
#include <set>

std::set<std::string> make_exit_commands()
{
    return {
        "q",
        "quit",
        "e",
        "exit"};
}

int main()
{
    using namespace std;
    const auto exit_commands = make_exit_commands();
    string command = {};
    while (exit_commands.count(command) == 0)
    {
        cout << "Enter command : " << std::endl;
        cin >> command;
    }

    return 0;
}