#include <iostream>
#include <windows.h>
#include "libraries/args.hxx"
#include "libraries/color.hpp"
#include "libraries/audio_out.cc"


#include "core/message.hpp"
#include "core/audiofile.cpp"


using namespace anshub;

int main(int argc, char const *argv[])
{
	if(argc <= 1)
    {
        std::cout << dye::aqua("R.A-LYPLAY Version 0.0.1 Crab") << std::endl;
    }
	
    args::ArgumentParser parser("*************************************************************", "*************************************************************");
    //parser.LongPrefix("/");
    parser.LongSeparator(" ");
    args::HelpFlag       help(parser, "help", "Display this help menu", {'h', "help"});
    args::ValueFlag<std::string> playurl(parser, "", "Playing The Sound File From Stream", {'u', "playurl"});
    args::ValueFlag<std::string> playfile(parser, "", "Playing The Sound File From Hard Drive", {'f', "playfile"});
	
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
        message::ParserErrorHelp();
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "Declared #2";
        std::cerr << parser;
        return 1;
    }

    if(playfile)
    {
        std::string buffer = args::get(playfile);
        afstream::PlayAudio(buffer);
    }
    else if(playurl)
    {
        std::cout << "URL File :" << args::get(playurl) << std::endl;
    }


	return 0;
}




