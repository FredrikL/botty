#include <bandit/bandit.h>
#include "../messageparser.h"

using namespace bandit;

go_bandit([](){
	describe("MessageParser",[](){
		describe("process_message", [](){
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

			it("should set numeric value correctly", [&] {
				auto result = parser.process_message(":penguin.omega.org.za 376 botty :End of message of the day.");

				AssertThat(result.num_id, Equals(376));
			});

			it("should handle ping in an odd way", [&] {
				auto result = parser.process_message("PING :lol");

				AssertThat(result.source, Equals("PING"));
				AssertThat(result.command, Equals(":lol"));
			});
		});

		
	});
});