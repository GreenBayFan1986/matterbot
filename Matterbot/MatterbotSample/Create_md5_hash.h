#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <string>

namespace lospi
{
	struct Create_md5_hash : ICommand {
		std::wstring get_name() override {
			return L"Create_md5_hash";
		}

		std::wstring get_help() override {
			return L"`Create_md5_hash [MESSAGE]`: Returns a MD5 Hash based on password supplied`.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			// command handler command_text wstring
			// wstring_to_string -> string
			// c_str()  size()
			// compute_md5 char* , unsigned int. -> md5 digest
			// get_str_from_md5 -> wstring

			std::string password = wstring_to_string(command_text);
			const char * cstring = password.c_str();
			unsigned int length = strlen(cstring);
			auto digestmd5 = compute_md5(cstring, length);
			std::wstring returnHash = get_str_from_md5(digestmd5);

			return returnHash;
		}
	};
}