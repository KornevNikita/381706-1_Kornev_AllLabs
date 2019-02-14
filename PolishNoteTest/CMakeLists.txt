file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolishNoteTest} ${srcs} ${hdrs})
target_link_libraries(${PolishNoteTest} ${PolishNoteLib} gtest)