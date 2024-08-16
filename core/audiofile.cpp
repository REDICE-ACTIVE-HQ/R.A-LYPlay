#include <iostream>
#include <string.h>

using namespace anshub;

namespace afstream  
{
	AudioOut audio;

	char input[3];

	void PlayAudio(std::string &filename)
	{
		std::cout << dye::green("[!] : ") << "You Have Chosed The Follwing Track To Play " << dye::yellow(filename) << '.' << '\n';
		std::cout << dye::yellow("[!] : ") << "If You Want To " << dye::green("Play ") << "enter 'P' ." << '\n';
		std::cout << dye::yellow("[!] : ") << "If You Want To " << dye::red("Cancel ") << "enter any character or press 'CTRL+C' ." << '\n';
		std::cout << dye::aqua("[>>] : ");
		std::cin >> input[0];
		if(input[0] == 'P')
		{
			std::cout << dye::green("[*] : ") << "If You Want To Loop Track Enter Again " << dye::green("'P'") << " ." << '\n';
			std::cout << dye::green("[*] : ") << "Else If You Want To Play Track Without Loop Enter " << dye::red("'C'") << " ." << '\n';
			std::cout << dye::aqua("[>>] : ");
			std::cin >> input[1];
			if(input[1] == 'P')
			{
				std::cout << dye::purple("[!] : The Follwing Track (" + filename +") Is Runing With Loop , Enter Any Key To Cancel Playing This Track .") << '\n';
				audio.Play(filename, true);
				std::cout << dye::aqua("[>>] : ");
				std::cin >> input[2];
				// here function for stopping the sound
			}
			else if(input[1] == 'C')
			{
				std::cout << dye::purple("[!] : The Follwing Track (" + filename +") Is Runing Without Loop , Enter Any Key To Cancel Playing This Track .") << '\n';
				audio.Play(filename, false);
				std::cout << dye::aqua("[>>] : ");
				std::cin >> input[2];
				// here function for stopping the sound
			}
			else
			{
				std::cout << dye::red("[*] : Invalid Option's Character .") << '\n';
			}
		}
		else
		{
			std::cout << dye::red("[*] : You Have Been Cancelled Playing Follwing Track (" + filename +") .") << '\n';
			return;
		}
	}


} 