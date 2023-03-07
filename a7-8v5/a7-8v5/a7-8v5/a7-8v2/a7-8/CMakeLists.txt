cmake_minimum_required(VERSION 3.21)
project(a5_6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(a5_6
        main.cpp
        controller.cpp
        controller.h
        Duration.cpp
        Duration.h
        Repo.cpp
        Repo.h
        DynamicVector.h
        DynamicVector.cpp
        Agenda.cpp
        Agenda.h
        Event.cpp
        Event.h
        ListViewWidget.h ListViewWidget.cpp ListViewWidget.ui redoclass.h redoclass.cpp
        UI.cpp UI.h EventModel.cpp EventModel.h tests.cpp tests.h validator.cpp validator.h Agenda_csv.cpp Agenda_csv.h Agenda_html.cpp Agenda_html.h compa.cpp compa.h GUIOLD.cpp GUIOLD.h gui.cpp gui.h qtgui.cpp qtgui.h qtgui.ui undoclass.cpp undoclass.h)

target_link_libraries(a5_6
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        )


if (WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Charts)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
