#include "Matterbot.h"
#include <iostream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "WeatherCommand.h"
#include "GreenBayQuarterbacksCommand.h"
#include "Create_md5_hash.h"
#include "rivestment_challenge.h"
#include "rivestment_command.h"
#include "rivestment_scraps.h"

#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {
  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"services/T4Z1QAKSS/B501HPM32/o06knPCUizfVe4woGOnqyT0z",
    outgoing_hook_route = L"http://127.0.0.1:9002/",
    outgoing_hook_token = L"fSpImEanEQ8Kp3AaN2DzBK7V",
    welcome_message = L"bot is running.";

  try {
    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
    bot->register_command(make_shared<EchoCommand>());
    bot->register_command(make_shared<ReverseCommand>(bot));
	bot->register_command(make_shared<WeatherCommand>());
	bot->register_command(make_shared<GreenBay_QuarterbacksCommand>());
	bot->register_command(make_shared<Create_md5_hash>());
	bot->register_command(make_shared<rivestment_password>());
	bot->register_command(make_shared<rivestment_challenge>(bot));
	bot->register_command(make_shared<rivestment_scraps>(bot));
	bot->register_command(make_shared<rivestment_command>());
    bot->post_message(welcome_message);

    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { bot->post_message(console); }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }
}
