#pragma once
#include "Matterbot.h"
#include <algorithm>

namespace lospi {
	struct WeatherCommand : ICommand {
		//explicit WeatherCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"weather"; }

		std::wstring get_help() override 
		{ 
			return L"`weather [CMD]`:\n`weather rain`: Make it rain\n`weather sunny`: Make it sunny\n`weather report`: Print the status."; 
		}

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override 
		{

			// what the command is going to do
			if (command_text == L"sunny")
			{
				is_raining = false;
				return L"It's sunny.";
			}
			else if (command_text == L"rain")
			{
				is_raining = true;
				return L"It's raining.";
			}
			else if (command_text == L"report")
			{
				if (is_raining == true)
				{
					return L"Get your Umbrella";
				}
				else if (is_raining == false)
				{
					return L"Get some sunscreen";
				}
				else
				{
					return L"is_raining must be null or something went wrong";
				}
			}
			else
			{
				return L"No weather reported... command text not a valid option";
			}
				
		}
	private:
		bool is_raining;
	};
}