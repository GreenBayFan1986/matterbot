#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct EchoCommand : ICommand {
		std::wstring get_name() override {
			return L"echo";
		}

		std::wstring get_help() override {
			return L"`echo [MESSAGE]`: `echo` will respond with whatever message you give it.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user == L"greenbayfan1986")
			{
				return command_text;
			}
			else
			{
				return L"invalid user";
			}
		}
	};
}
