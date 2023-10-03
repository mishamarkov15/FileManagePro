cmake_minimum_required(VERSION 3.24)
project(FileManagePro)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        Sql
        REQUIRED)

add_executable(FileManagePro main.cpp src/MainWindow.cpp headers/MainWindow.h src/TextFilePreview.cpp headers/TextFilePreview.h src/FileStorage.cpp headers/FileStorage.h src/VideoFilePreview.cpp headers/VideoFilePreview.h src/LoginWindow.cpp headers/LoginWindow.h)
target_link_libraries(FileManagePro
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
        Qt::Sql
        )
