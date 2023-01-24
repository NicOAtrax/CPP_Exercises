#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

using Dictionary = std::map<std::string, std::string>;
using History = std::vector<std::string>;

std::set<std::string> make_exit_commands()
{
    return {
        "q",
        "quit",
        "e",
        "exit"};
}

void add(std::istream &input, Dictionary &dictionary, History &history)
{
    using namespace std;
    string w1;
    input >> w1;
    auto &w2 = dictionary[w1];
    input >> w2;

    cout << w1 + " => " + dictionary[w1] << endl;
    history.push_back("add " + w1 + " " + w2);
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

void print(Dictionary &dictionary)
{
    using namespace std;
    for (const auto &pair : dictionary)
    {
        cout << pair.first + " => " + pair.second << endl;
    }
}

void save(std::istream &input, History &history)
{
    using namespace std;
    auto fileName = string{};
    input >> fileName;
    auto file = ofstream{fileName};
    for (const auto &command : history)
    {
        file << command << "\n";
    }
}

bool execute_command(std::istream &input, Dictionary &dictionary, History &history)
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
        add(input, dictionary, history);
    }

    if (command == "translate")
    {
        translate(input, dictionary);
    }
    if (command == "print")
    {
        print(dictionary);
    }
    if (command == "save")
    {
        save(input, history);
    }

    return true;
}

int main()
{
    using namespace std;
    auto dictionary = Dictionary{};
    auto history = History{};
    while (true)
    {
        cout << "Enter a command : " << endl;
        if (!execute_command(cin, dictionary, history))
        {
            break;
        }
    }

    return 0;
}