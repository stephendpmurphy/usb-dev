if(NOT UTILITY_ASSERT_LPC55S28_INCLUDED)
    
    set(UTILITY_ASSERT_LPC55S28_INCLUDED true CACHE BOOL "utility_assert component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_assert.c
    )


    include(utility_debug_console_LPC55S28)

endif()
