#pragma once
#include "Matterbot.h"
#include <iostream>
#include <string>

namespace lospi
{
	struct GreenBay_QuarterbacksCommand : ICommand {
		std::wstring get_name() override {
			return L"GreenBay_Quarterbacks";
		}

		std::wstring get_help() override {
			return L"`GreenBay_Quarterbacks [MESSAGE]`: `GreenBay_Quarterbacks` will respond with the starting QB(the one that started the most games) for the year you give it 1980 to 2016.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			
			std::wstring playing_year = command_text.substr(0, 4);

			//int year = _wtoi(playing_year.c_str());
			int year = std::stoi(playing_year);

			if (year >= 1980 && year <= 1985)
			{
				return L"Lynn Dickey \n Drafted: 1971 Round: 3 Pick: 56 \n Career Games Started: 111 \n Passing Yards: 23322 TDs: 141 Ints: 179";
			}
			else if (year >= 1986 && year <= 1987)
			{
				return L"Randy Wright \n Drafted: 1984 Round: 6 Pick: 153 \n Career Games Started: 32 \n Passing Yards: 7106 TDs: 31 Ints: 57";
			}
			else if (year >= 1988 && year <= 1991)
			{
				return L"Don Majkowski \n Drafted: 1987  Round: 10  Pick: 225 \n Career Games Started: 57 \n Passing Yards: 12700 TDs: 66 Ints: 67";
			}
			else if (year >= 1992 && year <= 2007)
			{
				return L"Brett Favre \n Drafted: 1991 Round: 2 Pick: 33 \n Career Games Started: 298 \n Passing Yards: 71838 TDs: 508 Ints: 336";
			}
			else if (year >= 2008 && year <= 2016)
			{
				return L"Aaron Rodgers \n Drafted: 2005 Round: 1 Pick: 24 \n Career Games Started: 135 \n Passing Yards: 36827 TDs: 297 Ints: 72";
			}
			else
			{
				return L"Invalid year supplied";
			}
			
			return command_text;
		}
	};
}