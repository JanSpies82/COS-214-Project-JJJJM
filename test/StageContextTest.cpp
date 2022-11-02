#include <limits.h>
#include <stdexcept>
#include "../src/StageContext.h"
#include "gtest/gtest.h"

namespace {
    TEST(StageContextTest, getInstance) {
        StageContext* stageContext1 = StageContext::getInstance();
        StageContext* stageContext2 = StageContext::getInstance();
        EXPECT_EQ(stageContext1, stageContext2);
        delete stageContext1;
    }    
}