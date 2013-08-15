#include <bandit/bandit.h>
#include "../engine.h"

using namespace bandit;

go_bandit([](){
	describe("Engine",[](){

		describe("PING/PONG", []() {
			botty::Engine engine;

			it("should create a pong for a ping",[&]() {
				auto result = engine.process_message("PING ");

				AssertThat(result, Equals("PONG "));
			});

			it("should include ping data in pong", [&]() {
				auto result = engine.process_message("PING :some data");

				AssertThat(result, Equals("PONG :some data"));
			});
		});

		describe("parse_msg", [](){
			botty::Engine engine;
			std::string msg(":source PRIVMSG botty :hai");

			it("should set source correctly", [&]() {
				auto result = engine.parse_msg(msg);

				AssertThat(result.source, Equals(":source"));
			});

			it("should set command correctly", [&]() {
				auto result = engine.parse_msg(msg);

				AssertThat(result.command, Equals("PRIVMSG"));
			});

			it("should set target correctly", [&]() {
				auto result = engine.parse_msg(msg);

				AssertThat(result.target, Equals("botty"));
			});

			it("should set data correctly", [&]() {
				auto result = engine.parse_msg(msg);

				AssertThat(result.data, Equals(":hai"));
			});
		});

		
	});
});