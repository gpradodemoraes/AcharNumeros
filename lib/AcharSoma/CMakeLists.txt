add_library(AcharSoma AcharSoma.cpp GetNumbersFromFile.cpp)
target_include_directories(AcharSoma
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

