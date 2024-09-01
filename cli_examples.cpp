/*#include <iostream>
#include "libraries/args.hxx"
int main(int argc, char **argv)
{
    args::ArgumentParser parser("This is a test program.", "This goes after the options.");
    args::Group group(parser, "This group is all exclusive:", args::Group::Validators::Xor);
    args::Flag foo(group, "foo", "The foo flag", {'f', "foo"});
    args::Flag bar(group, "bar", "The bar flag", {'b'});
    args::Flag baz(group, "baz", "The baz flag", {"baz"});
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Declared #1";
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Declared #2";
        std::cerr << parser;
        return 1;
    }
    if (foo) { std::cout << "foo" << std::endl; }
    if (bar) { std::cout << "bar" << std::endl; }
    if (baz) { std::cout << "baz" << std::endl; }
    return 0;
}*/

#include <iostream>
#include "libraries/args.hxx"
int main(int argc, char **argv)
{
    args::ArgumentParser parser("This is a test program.", "This goes after the options.");
    
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    
    args::ValueFlag<int> integer(parser, "integer", "The integer flag", {'i'});
    
    args::ValueFlagList<char> characters(parser, "characters", "The character flag", {'c'});
    
    args::Positional<std::string> foo(parser, "foo", "The foo position");
    
    args::PositionalList<double> numbers(parser, "numbers", "The numbers position list");
    
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    if (integer) { std::cout << "i: " << args::get(integer) << std::endl; }
    if (characters) { for (const auto ch: args::get(characters)) { std::cout << "c: " << ch << std::endl; } }
    if (foo) { std::cout << "f: " << args::get(foo) << std::endl; }
    if (numbers) { for (const auto nm: args::get(numbers)) { std::cout << "n: " << nm << std::endl; } }
    return 0;
}