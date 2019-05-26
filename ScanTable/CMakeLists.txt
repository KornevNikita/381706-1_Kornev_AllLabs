file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${ScanTable} ${srcs} ${hdrs}) 
target_link_libraries(${ScanTable} ${ScanTableLib})

