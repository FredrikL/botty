#include <bandit/bandit.h>
#include "../messageparser.h"

using namespace bandit;

go_bandit([](){
	describe("MessageParser",[](){
		describe("parse_msg", [](){
			botty::MessageParser parser;
			std::string msg(":source PRIVMSG botty :hai");

			it("should set source correctly", [&]() {
				auto result = parser.process_message(msg);

				AssertThat(result.source, Equals(":source"));
			});

			it("should set command correctly", [&]() {
				auto result = parser.process_message(msg);

				AssertThat(result.command, Equals("PRIVMSG"));
			});

			it("should set target correctly", [&]() {
				auto result = parser.process_message(msg);

				AssertThat(result.target, Equals("botty"));
			});

			it("should set data correctly", [&]() {
				auto result = parser.process_message(msg);

				AssertThat(result.data, Equals(":hai"));
			});
		});

		
	});
});