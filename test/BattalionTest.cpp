#include <limits.h>
#include <stdexcept>
#include "../src/Battalion.h"
#include "gtest/gtest.h"

namespace {

<<<<<<< HEAD
   // Test attack()
	//=============Precondition Testing ===================
	//Test Precondition passing in NULL 
TEST(attackTest,TestPreconditionNullptr){
	try{
		attack(NULL);
		FAIL();
	}catch(std::invalid_argument & err){
		EXPECT_EQ(err.what(),std::string("NULLPTR PASSED IN"));
	}catch(...){
		FAIL();
	}
}

=======
    
}
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
