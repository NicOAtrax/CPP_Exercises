#include <iostream>
#include <set>
#include <map>
#include <sstream>

using Dictionary = std::map<std::string, std::string>;

std::set<std::string> make_exit_commands()
{
    return {
        "q",
        "quit",
        "e",
        "exit"};
}

void add(std::istream &input, Dictionary &dictionary)
{
    using namespace std;
    string w1;
    input >> w1;
    auto &w2 = dictionary[w1];
    input >> w2;

    cout << w1 + " => " + dictionary[w1] << endl;
}

void translate(std::istream &input, Dictionary &dictionary)
{
    using namespace std;
    auto words = stringstream{};
    auto line = string{};
    getline(input, line);
    words << line;
    while (!words.eof())
    {
        string w1;
        words >> w1;
        const auto it = dictionary.find(w1);
        cout << (it == dictionary.end() ? "???" : it->second) << " ";
    }

    cout << endl;
}

bool execute_command(std::istream &input, Dictionary &dictionary)
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
        add(input, dictionary);
    }

    if (command == "translate")
    {
        translate(input, dictionary);
    }

    return true;
}

int main()
{
    using namespace std;
    auto dictionary = Dictionary{};
    while (true)
    {
        cout << "Enter a command : " << endl;
        if (!execute_command(cin, dictionary))
        {
            break;
        }
    }

    return 0;
}