﻿file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${TreeTableLib} STATIC ${srcs} ${hdrs}) 

