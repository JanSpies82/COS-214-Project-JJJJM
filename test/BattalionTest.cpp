#include <limits.h>
#include <stdexcept>
#include "../src/Military.h"
#include "../src/Battalion.h"
#include "gtest/gtest.h"

namespace {

  // Test attack()
	//=============Precondition Testing ===================
	//Test Precondition passing in NULL 
TEST(BatalionTest,TestPreconditionNullptr){
	Battalion * person=new Battalion();
	try{
		person->attack(NULL);
		FAIL()<<"Expected std::invalid_argument";
	}catch(std::invalid_argument & err){
		EXPECT_EQ(err.what(),std::string("NULLPTR PASSED IN"));
	}catch(...){
		FAIL();
	}
}
    
}

