file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ReversePolishNotationTest} ${srcs} ${hdrs})
target_link_libraries(${ReversePolishNotationTest} ${ReversePolishNotationLib} gtest)