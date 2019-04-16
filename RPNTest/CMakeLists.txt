file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${RPNTest} ${srcs} ${hdrs})
target_link_libraries(${RPNTest} ${RPNLib} gtest)
