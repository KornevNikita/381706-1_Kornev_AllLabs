file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${6.StackList} ${srcs} ${hdrs}) 

target_link_libraries(${6.StackList} ${6.StackListLib})
