file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${6.StackListTest} ${srcs} ${hdrs})
target_link_libraries(${6.StackListTest} ${6.StackListLib} gtest)
