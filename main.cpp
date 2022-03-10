//#include "modules/People.h"

#include <iostream>
#include "variant/simple_variant.h"
#include "variant/poly_variant.h"
#include "exceptions/exception.h"
#include "construction/basic_object_construction.h"
#include "templates/function_object.h"
#include "templates/lambda_expression.h"
#include "move/no_except_example.h"
#include "move/move_on_strings.h"
#include "move/perfect_forwarding.h"
#include "move/template_concepts.h"
#include "move/performance_timings.h"
#include "move/return_value.h"
#include "inline/inline.h"
#include "constexpr/compile_time_if.h"
#include "optional/optional.h"
#include "optional/OptionalMember.h"
#include "lang_features/std_any_example.h"
#include "byte_and_bitset/byte_example.h"

int main() {
    Byte::testMe();
    //StdAny::testMe();
    //OptionalMember::testMe();
    //Optional::testMe();
    //CompileTimeIf::testMe();
    //InLineTest inLineTest;
    //inLineTest.testMe();
    //ReturnValueTest::testRetVal();
    //testPerformance();
    //testTemplateConcepts();
    //TestForwarding::testMain();
    //MoveOnStrings::testMe();
    //Person::testMain();

    //LambdaExpression::testLambdaExpression();
    //LambdaExpression::testLambda();
    //testLessThanFunctionObject();
    //BasicObjectConstruction::testMe();
//    Exception except;
//    except.testExceptions();
//    SimpleVariant simpleVariant;
//    simpleVariant.test();
//
//    PolyVariant polyVariant;
//    polyVariant.main();
    return 0;
}
