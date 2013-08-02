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
		
	});
});