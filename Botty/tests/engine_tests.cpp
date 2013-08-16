#include <bandit/bandit.h>
#include "../engine.h"

using namespace bandit;

go_bandit([](){
	describe("Engine",[](){
		describe("parse_msg", [](){
			botty::Engine engine;
			std::string msg(":source PRIVMSG botty :hai");

			it("should set source correctly", [&]() {
				auto result = engine.process_message(msg);

				AssertThat(result.source, Equals(":source"));
			});

			it("should set command correctly", [&]() {
				auto result = engine.process_message(msg);

				AssertThat(result.command, Equals("PRIVMSG"));
			});

			it("should set target correctly", [&]() {
				auto result = engine.process_message(msg);

				AssertThat(result.target, Equals("botty"));
			});

			it("should set data correctly", [&]() {
				auto result = engine.process_message(msg);

				AssertThat(result.data, Equals(":hai"));
			});
		});

		
	});
});