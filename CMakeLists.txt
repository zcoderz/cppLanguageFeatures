cmake_minimum_required(VERSION 3.21)
project(cppLanguageFeatures)

set(CMAKE_CXX_STANDARD 23)
set(Boost_INCLUDE_DIR /home/usman/boost/boost_1_77_0)
set(Boost_LIBRARY_DIR /home/usman/boost/boost_1_77_0/stage/lib)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-pthread  -lpthread")


add_executable(cppLanguageFeatures main.cpp library/line.h library/coord.h library/circle.h library/rectangle.h variant/simple_variant.h variant/poly_variant.h enum/building_enum.h namespace/sample_namespace.h namespace/sample_namespace.cpp exceptions/exception.cpp exceptions/exception.h auto/auto_test.h construction/basic_object_construction.h templates/simple_template.h templates/function_object.h templates/lambda_expression.h move/no_except_example.h move/move_on_strings.h move/perfect_forwarding.h move/template_concepts.h move/performance_timings.h move/return_value.h inline/inline.h inline/inline.cpp lang_features/copy_epsilon_mandatory_for_temporaries.h constexpr/const_expr_example.h constexpr/compile_time_if.h)


