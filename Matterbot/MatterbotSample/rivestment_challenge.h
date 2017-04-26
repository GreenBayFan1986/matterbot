#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include <map>
#include <iostream>
#include "rivestment_password.h"
#include "rivestment_command.h"

namespace lospi
{
	struct rivestment_challenge : ICommand {
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			// need the list of commands added
			return L"`challenges` will attempt to solve the password for the given hashes";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////// Find the password by comparing /////////////////////////////////////////
			////////////////////////////////// hash map and the challenge from rivestment ////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			std::wstring return_passwords = L"rivestment try";							// used to return the try to rivestment

			// load hashes provided by rivestment into a vector
			std::wstring input;
			std::wistringstream rivestment_input{ command_text };
			while (getline(rivestment_input, input, L' ')) {

				Md5Digest rivestment_md5 = get_md5_from_str(input);

				auto result = hashes.find(rivestment_md5);

				if (result == hashes.end())
				{
					// couldn't find a match;
				}
				else
				{
					auto password = result->second;

					return_passwords = return_passwords + L" " + string_to_wstring(password);
				}
			}



				
			return return_passwords;

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		}  // end handle command
	};
}