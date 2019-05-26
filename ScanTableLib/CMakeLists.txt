file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${ScanTableLib} STATIC ${srcs} ${hdrs}) 

