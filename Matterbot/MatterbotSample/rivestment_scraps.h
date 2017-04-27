#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include <map>
#include <iostream>
#include "rivestment_password.h"
#include "rivestment_command.h"

namespace lospi
{
	struct rivestment_scraps : ICommand
	{
		explicit rivestment_scraps(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"scraps"; }

		std::wstring get_help() override { return L"`scraps` will attempt to solve the password for the given hashes"; }

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override
		{

			if (user == L"greenbayfan1986" || user == L"rivestment")
			{
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				///////////////////////////////////////// Find the password by comparing /////////////////////////////////////////
				////////////////////////////////// hash map and the challenge from rivestment ////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				_sleep(1050);

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


				bot->post_message(return_passwords);
				_sleep(1050);
				return L"rivestment challenge " + rivestment_tries;

				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			}
			else
			{
				return L"invalid user";
			}
		}  // end handle command
	private:
		std::shared_ptr<Matterbot> bot;
	};
}