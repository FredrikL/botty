#include <bandit/bandit.h>
#include "../engine.h"

using namespace bandit;

go_bandit([](){
	describe("test",[](){
		botty::Engine engine;

		it("should create a pong for a ping",[&]() {
			auto result = engine.process_message("PING :foo");

			AssertThat(result, Equals("PONG :foo"));
		});
	});
});