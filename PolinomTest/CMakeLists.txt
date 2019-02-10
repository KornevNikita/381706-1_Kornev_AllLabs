file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolinomTest} ${srcs} ${hdrs})

target_link_libraries(${PolinomTest} ${PolinomLib} gtest)

