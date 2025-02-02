#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <Medium.hpp>

using cucumber::ScenarioScope;

class StromCtx {
public:
    // StromCtx() : strom(0, 0), result(0) {}
    Strom strom{0, 0};
    int result;
};

GIVEN("^I have set (\\d+) for the current$") {
    REGEX_PARAM(int, c);
    ScenarioScope<StromCtx> context;
    context->strom.set_current(c);
}

WHEN("^The current has been set$") {
    // This is where the current must be set
    ScenarioScope<StromCtx> context;

    context->result = context->strom.read_current();
}

THEN("^The result is (\\d+)$") {
    REGEX_PARAM(int, expected);
    ScenarioScope<StromCtx> context;

    EXPECT_EQ(expected, context->result);
}
