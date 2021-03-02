if(NOT DEVICE_LPC55S28_STARTUP_LPC55S28_INCLUDED)
    
    set(DEVICE_LPC55S28_STARTUP_LPC55S28_INCLUDED true CACHE BOOL "device_LPC55S28_startup component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_LPC55S28.S
    )


    include(device_LPC55S28_system_LPC55S28)

endif()
