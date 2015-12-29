// File: mytest.cpp
#include "gtest/gtest.h"

#include <pendulum.h>

TEST(Dummy, foobar)
{
    // Put your test code here ...
    using smizzle::pendulum::Pendulum;
    EXPECT_EQ(3, Pendulum::callThePendulum());
    ASSERT_EQ(5, 4+1);
}
