cmake_minimum_required(VERSION 3.15)    # Проверка версии CMake
					# Если версия установленной программы
					# старее указанной, аварийный выход

set(PROJECT_NAME example)  # зажать значение PROJECT_NAME
project("${PROJECT_NAME}")  		# установить имя проекта


set(CMAKE_CXX_STANDART 17)		# устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

# сказать проге, что должен быть исполняемый файл 
add_executable("${PROJECT_NAME}" main.cpp)
