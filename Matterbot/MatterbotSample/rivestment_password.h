#pragma once
#include "Matterbot.h"

std::wstring rivestmentPassword;

namespace lospi
{
	struct rivestment_password : ICommand {
		std::wstring get_name() override {
			return L"password";
		}

		std::wstring get_help() override {
			return L"`password [MESSAGE]`: will update the password for the rivestment challenge";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override 
		{

			if (user != L"rivestment")
			{
				return L"Invalid User";
			}
			else if (user == L"rivestment")
			{
				rivestmentPassword = command_text;
				return L"Password has been updated";

			}
		}
	};
}