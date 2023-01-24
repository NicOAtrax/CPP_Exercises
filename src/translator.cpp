#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

using Dictionary = std::map<std::string, std::string>;
using History = std::vector<std::string>;
using Context = std::pair<Dictionary, History>;
using Languages = std::pair<std::string, std::string>;
using Translator = std::map<Languages, Context>;

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

bool execute_command(std::istream &input, Translator &translator, Languages &languages);

void load(std::istream &input, Translator &translator, Languages &languages)
{
    using namespace std;
    auto fileName = string{};
    input >> fileName;
    auto file = ifstream{fileName};
    while (!file.eof())
    {
        execute_command(file, translator, languages);
    }
}

void clear(Dictionary &dictionary, History &history)
{
    dictionary.clear();
    history.clear();
}

void remove(std::istream &input, Dictionary &dictionary, History &history)
{
    using namespace std;
    auto word = string{};
    input >> word;
    for (auto it = dictionary.begin(); it != dictionary.end();)
    {
        if (it->first == word || it->second == word)
        {
            cout << it->first + " x " + it->second << endl;
            it = dictionary.erase(it);
        }
        else
        {
            ++it;
        }
    }
    history.push_back("remove " + word);
}

void from(std::istream &input, Languages &languages)
{
    using namespace std;
    input >> languages.first;
}

void to(std::istream &input, Languages &languages)
{
    using namespace std;
    input >> languages.second;
}

bool execute_command(std::istream &input, Translator &translator, Languages &languages)
{
    using namespace std;
    const auto exit_commands = make_exit_commands();
    auto &context = translator[languages];
    auto &dictionary = context.first;
    auto &history = context.second;

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
    if (command == "load")
    {
        load(input, translator, languages);
    }
    if (command == "clear")
    {
        clear(dictionary, history);
    }
    if (command == "remove")
    {
        remove(input, dictionary, history);
    }
    if (command == "from")
    {
        from(input, languages);
    }
    if (command == "to")
    {
        to(input, languages);
    }

    return true;
}

int main(int argc, char **argv)
{
    using namespace std;
    auto languages = argc == 3 ? Languages{argv[1], argv[2]} : Languages{"fr", "en"};
    auto dictionary = Dictionary{};
    auto history = History{};
    auto translator = Translator{};
    while (true)
    {
        cout << "Enter a command : " << endl;
        if (!execute_command(cin, translator, languages))
        {
            break;
        }
    }

    return 0;
}