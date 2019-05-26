file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${HashTable} ${srcs} ${hdrs}) 

target_link_libraries(${HashTable} ${HashTableLib})

