file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${HashTableLib} ${srcs} ${hdrs}) 

