if(NOT DRIVER_MRT_LPC55S28_INCLUDED)
    
    set(DRIVER_MRT_LPC55S28_INCLUDED true CACHE BOOL "driver_mrt component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_mrt.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_LPC55S28)

endif()
