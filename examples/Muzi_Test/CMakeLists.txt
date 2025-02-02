project(Muzi_Test)

add_library(Muzi_Test STATIC src/Medium.cpp)
target_include_directories(Muzi_Test INTERFACE src)

if(TARGET GTest::gtest)
    add_executable(MediumSteps features/step_definitions/MediumSteps.cpp)
    target_link_libraries(MediumSteps PRIVATE Muzi_Test cucumber-cpp GTest::gtest)
endif()
