file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${TreeTable} ${srcs} ${hdrs}) 

target_link_libraries(${TreeTable} ${TreeTableLib})

