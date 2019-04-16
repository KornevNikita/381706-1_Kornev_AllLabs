file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${RPN} ${srcs} ${hdrs}) 
target_link_libraries(${RPN} ${RPNLib}) 


