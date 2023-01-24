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

bool execute_command(std::istream &input)
{
    using namespace std;
    const auto exit_commands = make_exit_commands();
    string command = {};
    input >> command;

    if (exit_commands.count(command) != 0)
    {
        return false;
    }

    if (command == "add")
    {
        string w1;
        input >> w1;
        string w2;
        input >> w2;
        cout << w1 + " => " + w2 << endl;
    }

    return true;
}

int main()
{
    using namespace std;
    while (true)
    {
        cout << "Enter command : " << endl;
        if (!execute_command(cin))
        {
            break;
        }
    }

    return 0;
}