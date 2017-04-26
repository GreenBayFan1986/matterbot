#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include <map>
#include <iostream>
#include "rivestment_password.h"

std::map<Md5Digest, std::string> hashes;

namespace lospi {
	struct rivestment_command : ICommand {
		//explicit WeatherCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"rcommand"; }

		std::wstring get_help() override
		{
			std::wstring return_help;
			return_help = L"`rcommand [CMD]`:\n`register`: Registers ralph_bot with rivestment";
			return_help = return_help + L"\n`password`: Prompts rivestment for the password";
			return_help = return_help + L"\n`level`: Sets the level for rivestment";
			return_help = return_help + L"\n`quit`: Has the bot quit rivestment";
			
			return return_help;
		}

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override
		{

			// Find the command
			if (command_text == L"register")
			{
				return L"rivestment register ralph_bot";
			}
			else if (command_text == L"password")
			{
				return L"rivestment password";
			}
			else if (command_text.substr(0,6) == L"level ")
			{

				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				////////////////////////////////// Build the table of passwords/hashes that //////////////////////////////////////
				////////////////////////////// will be used to compare against the challenges ////////////////////////////////////
				////////////////////////////////////////////// from rivestment ///////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				std::map<Md5Digest, std::string> hashes;
				std::string level = wstring_to_string(command_text.substr(6, 1));
				int rivestment_level = stoi(level);
				std::string password = wstring_to_string(rivestmentPassword);

				// for level 1 you would go from length 0 to 10
				// generate all the hashes and pack them into a map

				for (size_t i = (rivestment_level - 1); i < rivestment_level + 10; i++)
				{
					Combinator c{ "hsoj", i };
					while (c.has_next())
					{
						auto combo = c.next();

						//password, combo;
						copy(password.begin(), password.end(), back_inserter(combo));

						auto md5 = compute_md5(combo.data(), (unsigned long)combo.size());
						// map insertion here
						hashes.emplace(md5, std::string{ combo.begin(), combo.end() });

					}
				}

				return L"rivestment " + command_text;

				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				///////////////////////////////////////////// TABLE SHOULD BE BUILT //////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			}
			else
			{
				return L"Invalid command";
			}

		}
	};
}