cmake_minimum_required(VERSION 3.21)
project(cppLanguageFeatures)
set(Boost_INCLUDE_DIR /home/usman/boost/boost_1_79_0/stage/include)
set(Boost_LIBRARY_DIR /home/usman/boost/boost_1_79_0/stage/lib)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-pthread  -lpthread")


add_executable(cppLanguageFeatures main.cpp library/line.h library/coord.h library/circle.h library/rectangle.h variant/simple_variant.h variant/poly_variant.h enum/building_enum.h namespace/sample_namespace.h namespace/sample_namespace.cpp exceptions/exception.cpp exceptions/exception.h auto/auto_test.h construction/basic_object_construction.h templates/simple_template.h templates/function_object.h lambda/lambda_expression.h move/no_except_example.h move/move_on_strings.h move/perfect_forwarding.h move/template_concepts.h move/performance_timings.h move/return_value.h inline/inline.h inline/inline.cpp lang_features/copy_epsilon_mandatory_for_temporaries.h constexpr/const_expr_example.h constexpr/compile_time_if.h optional/optional.h optional/OptionalMember.h lang_features/std_any_example.h byte_and_bitset/byte_example.h byte_and_bitset/bitset_example.h stl_algos/search_one.h stl_algos/search_two.h stl_algos/sample_example.h stl_algos/container_splice_and_merge.h exceptions/uncaught_exception.h polymorphic_memory/track_new.h polymorphic_memory/pmr_one.h polymorphic_memory/pmr_two.h polymorphic_memory/pmr_three.h polymorphic_memory/pmr_customer.h polymorphic_memory/tracker.h polymorphic_memory/pmr_null.h polymorphic_memory/stable_memory_pool.h polymorphic_memory/memory_alignment.h polymorphic_memory/cache_line.h pointers/unique_ptr.h pointers/weak_ptr.h pointers/shared_ptr.h stl_algos/transform_example.h stl_algos/sort_example.h stl_algos/remove.h lambda/lamda_example.h stl_algos/for_each_example.h stl_algos/copy_example.h stl_algos/find_first_of.h lang_features/using_example.h lang_features/using_example_two.h lang_features/override_example.h pointers/pimpl/widget.h pointers/pimpl/widget.cpp pointers/pimpl/gadget.h pointers/prefer_make_unique_and_shared.h views_and_ranges/views_pipe.h)

include_directories(${Boost_INCLUDE_DIR})
