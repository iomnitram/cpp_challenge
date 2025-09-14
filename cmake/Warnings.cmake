# Warnings.cmake

function(warnings_project)
    if(MSVC)
        add_compile_options(/W4 /permissive-)
    else()
        add_compile_options(
                -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wsign-conversion
                -Wshadow
                -Wold-style-cast
                -Wnon-virtual-dtor
                -Woverloaded-virtual
                -Wnull-dereference
                -Wdouble-promotion
                -Wformat=2
        )
    endif()
endfunction()

function(warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${target} PRIVATE
                -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wsign-conversion
                -Wshadow
                -Wold-style-cast
                -Wnon-virtual-dtor
                -Woverloaded-virtual
                -Wnull-dereference
                -Wdouble-promotion
                -Wformat=2
        )
    endif()
endfunction()

function(warnings_error_project)
    add_compile_options(-Werror)
endfunction()

function(warnings_error targed)
    target_compile_options(${target} PRIVATE -Werror)
endfunction()