//#include "modules/People.h"

#include <iostream>
#include "variant/simple_variant.h"
#include "variant/poly_variant.h"
#include "exceptions/exception.h"
#include "construction/basic_object_construction.h"
#include "templates/function_object.h"
#include "lambda/lambda_expression.h"
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
#include "byte_and_bitset/bitset_example.h"
#include "stl/search_one.h"
#include "stl/search_two.h"
#include "polymorphic_memory/pmr_one.h"
#include "polymorphic_memory/pmr_two.h"
#include "polymorphic_memory/pmr_three.h"
#include "polymorphic_memory/pmr_customer.h"
#include "polymorphic_memory/pmr_null.h"
#include "polymorphic_memory/stable_memory_pool.h"
#include "polymorphic_memory/cache_line.h"
#include "pointers/unique_ptr.h"
#include "pointers/weak_ptr.h"
#include "pointers/shared_ptr.h"
#include "stl/transform_example.h"
#include "stl/sort_example.h"
#include "stl/remove.h"
#include "lambda/lamda_example.h"
#include "stl/algos/accumulate1.h"
#include "stl/algos/binarysearch.h"
#include "stl/algos/bounds1.h"
#include "stl/algos/lexicocmp.h"
#include "stl/algos/merge.h"
#include "stl/algos/nthelement.h"
#include "stl/algos/partialsum.h"

int main() {
    PartialSum::main();
    //NthElement::main();
    //Merge::main();
    //LexicographicCompare::main();
    //BoundsExample::main();
    //BinarySearchExample::main();
    //AccumulateExample::main();
    //LambdaExampleOne::main();
    //Remove::testMe();
    //Sort::main();
    //Transform::main();
    //SharedPtr::SharedPtr::testMe();
    //WeakPtr::WeakPtr::testMe();
    //UniquePtr::UniquePtr::testMe();
    //TestCacheLines::testMe();
    //StableMemoryPool::testMe();
    //PMRNull::testMe();
    //PmrCustomer::testMe();
    //PMRThree::testMe();
    //PMRTwo::testMe();
    //PMROne::testMe();
    //SearchOne::testMe();
    //SearchTwo::testMe();
    //BitsetExample::testMe();
    //Byte::testMe();
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
