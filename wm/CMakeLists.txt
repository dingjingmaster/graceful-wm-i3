include(${CMAKE_SOURCE_DIR}/common/common.cmake)

file(GLOB MAIN_SRC
        ${CMAKE_SOURCE_DIR}/wm/types.h

        ${CMAKE_SOURCE_DIR}/wm/xkb.h
        ${CMAKE_SOURCE_DIR}/wm/xkb.c

        ${CMAKE_SOURCE_DIR}/wm/data.h
        ${CMAKE_SOURCE_DIR}/wm/data.c

        ${CMAKE_SOURCE_DIR}/wm/utils.h
        ${CMAKE_SOURCE_DIR}/wm/utils.c

        ${CMAKE_SOURCE_DIR}/wm/queue.h
        ${CMAKE_SOURCE_DIR}/wm/queue.c

        ${CMAKE_SOURCE_DIR}/wm/match.h
        ${CMAKE_SOURCE_DIR}/wm/match.c

        ${CMAKE_SOURCE_DIR}/wm/config.h
        ${CMAKE_SOURCE_DIR}/wm/config.c

        ${CMAKE_SOURCE_DIR}/wm/xcursor.h
        ${CMAKE_SOURCE_DIR}/wm/xcursor.c

        ${CMAKE_SOURCE_DIR}/wm/draw-utils.h
        ${CMAKE_SOURCE_DIR}/wm/draw-utils.c

        ${CMAKE_SOURCE_DIR}/wm/command-line.h
        ${CMAKE_SOURCE_DIR}/wm/command-line.c

        ${CMAKE_SOURCE_DIR}/wm/restore-layout.h
        ${CMAKE_SOURCE_DIR}/wm/restore-layout.c

        )

add_executable(graceful-wm main.c ${MAIN_SRC} ${COMMON_SRC})
target_include_directories(graceful-wm PUBLIC
        ${SN_INCLUDE_DIRS}
        ${GIO_INCLUDE_DIRS}
        ${XCB_INCLUDE_DIRS}
        ${XKB_INCLUDE_DIRS}
        ${YAJL_INCLUDE_DIRS}
        ${PCRE_INCLUDE_DIRS}
        ${PANGO_INCLUDE_DIRS}
        ${CAIRO_INCLUDE_DIRS})
target_link_libraries(graceful-wm
        -lm -lrt -lev
        ${SN_LIBRARIES}
        ${GIO_LIBRARIES}
        ${XCB_LIBRARIES}
        ${XKB_LIBRARIES}
        ${YAJL_LIBRARIES}
        ${PCRE_LIBRARIES}
        ${PANGO_LIBRARIES}
        ${CAIRO_LIBRARIES})

target_compile_definitions(graceful-wm PUBLIC
        -D SN_API_NOT_YET_FROZEN
        -D PCRE2_CODE_UNIT_WIDTH=8)