#include "utils.hpp"
#include "../../src/asm-dom.hpp"
#include <emscripten/val.h>

using namespace asmdom;

void assertEquals(emscripten::val actual, emscripten::val expected) {
	if (!actual.strictlyEquals(expected)) {
		throw 20;
	}
};

emscripten::val getBodyFirstChild() {
	return emscripten::val::global("document")["body"]["firstChild"];
};

emscripten::val getRoot() {
	return emscripten::val::global("document").call<emscripten::val>("getElementById", emscripten::val("root"));
};

emscripten::val getNode(VNode* vnode) {
	return emscripten::val::global("window")["asmDomHelpers"]["nodes"][std::to_string(vnode->elm).c_str()];
};