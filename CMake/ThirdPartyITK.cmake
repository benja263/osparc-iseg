#
# Define how to use third party, i.e. 
# - include directory
# - library
# - preprocessor definitions needed by package
#

FIND_PACKAGE(ITK 4.12 COMPONENTS 
		ITKCommon ITKOptimizers ITKOptimizersv4 ITKTransform ITKTransformFactory
		ITKVNLInstantiation ITKVTK ITKBiasCorrection ITKLabelMap
		ITKWatersheds ITKStatistics ITKMetaIO ITKIOImageBase ITKIOGDCM ITKIOMesh 
		ITKIOMeta ITKIONIFTI ITKIONRRD ITKIOTransformBase ITKIOTransformMatlab  
		ITKIOPNG ITKIOTIFF ITKIOJPEG ITKIOVTK ITKBinaryMathematicalMorphology
		ITKGDCM  		
			REQUIRED)
 
MACRO(USE_ITK)
	INCLUDE( ${ITK_USE_FILE} )
	LIST( APPEND MY_EXTERNAL_LINK_LIBRARIES ${ITK_LIBRARIES} )
	REMEMBER_TO_CALL_THIS_INSTALL_MACRO( INSTALL_RUNTIME_LIBRARIES_ITK )
ENDMACRO()

MACRO(INSTALL_RUNTIME_LIBRARIES_ITK)
	IF(MSVC)
		MESSAGE( STATUS "--> ThirdPartyITK: installing ITK dlls ..." )
		FOREACH(BUILD_TYPE ${CMAKE_CONFIGURATION_TYPES})
		STRING(TOLOWER ${BUILD_TYPE} build_type)
			IF(${build_type} MATCHES rel*)
				FILE(COPY ${ITK_DIR}/bin/${BUILD_TYPE}/
						DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TYPE}
						FILES_MATCHING PATTERN "ITK*.dll" PATTERN "ITK*.pdb" EXCLUDE)
			ELSE()
				FILE(COPY ${ITK_DIR}/bin/${BUILD_TYPE}/
					DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TYPE}
					FILES_MATCHING PATTERN "ITK*.dll" PATTERN "ITK*.pdb")
			ENDIF()
		ENDFOREACH()
	ENDIF()
ENDMACRO()
