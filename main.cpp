//#include "modules/People.h"

#include <iostream>
#include "variant/SimpleVariant.h"
#include "variant/PolyVariant.h"
#include "exceptions/Exception.h"
#include "construction/BasicObjectConstruction.h"
#include "templates/FunctionObject.h"
#include "templates/LambdaExpression.h"
#include "move/NoExceptExample.h"
#include "move/MoveOnStrings.h"
#include "move/PerfectForwarding.h"
#include "move/TemplateConcepts.h"
#include "move/PerformanceTimings.h"
#include "move/ReturnValue.h"

int main() {
    ReturnValueTest::testRetVal();
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
