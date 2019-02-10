file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${StackListLib} ${srcs} ${hdrs}) 


