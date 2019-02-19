file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${RPNLib} STATIC ${srcs} ${hdrs})


