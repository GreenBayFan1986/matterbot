#pragma once
#include "Matterbot.h"
#include <time.h>

namespace lospi
{
	struct TimeCommand : ICommand {
		std::wstring get_name() override { return L"Time";}

		std::wstring get_help() override 
		{
			return L"`echo [MESSAGE]`: `echo` will give the current time.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			return (int)time(NULL);
		}
	};
}