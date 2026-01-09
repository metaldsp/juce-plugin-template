# Mandatory line, sets the minimum version of CMake that should be used with this repository.
cmake_minimum_required(VERSION 3.22)

# Project name and version. Rename these values when deriving a new plugin.
project(AudioPlugin VERSION 0.0.0 LANGUAGES C CXX)

# JUCE 8 supports C++23 across supported platforms.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download the dependencies to the same folder as the project.
# If you want to install them system wide, set CPM_SOURCE_CACHE with the path to the dependencies
# either as an environment variable or pass it to the cmake script with -DCPM_SOURCE_CACHE=<path>.
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Downloads CPM if not already downloaded. CPM is an easy-to-use package manager nicely integrated with CMake.
include(cmake/cpm.cmake)

# Add JUCE.
CPMAddPackage(
    NAME JUCE
    GIT_TAG 8.0.15
    VERSION 8.0.15
    GITHUB_REPOSITORY juce-framework/JUCE
    SOURCE_DIR ${LIB_DIR}/juce
)

# Add googletest.
CPMAddPackage(
    NAME GOOGLETEST
    GITHUB_REPOSITORY google/googletest
    GIT_TAG v1.15.2
    VERSION 1.15.2
    SOURCE_DIR ${LIB_DIR}/googletest
    OPTIONS
        "INSTALL_GTEST OFF"
        "gtest_force_shared_crt ON"
)

# PRODUCT_NAME can contain spaces and is what DAWs display. Consider appending a major
# version so incompatible future versions can coexist in users' projects.
set(PRODUCT_NAME "Audio Plugin")

# Product name without version
set(PRODUCT_NAME_WITHOUT_VERSION "Audio Plugin")

# Change me! Used for the macOS bundle name and installers.
set(COMPANY_NAME "MetalDSP")

# Change me! Used for the macOS bundle identifier and signing.
set(BUNDLE_ID "com.metaldsp.audioplugin")

# Change me! Set the plugin formats you want built
# Valid choices: AAX Unity VST VST3 AU AUv3 Standalone
set(FORMATS Standalone AU VST3 AUv3)

# A four-character plugin manufacturer code
# Note: first character MUST be uppercase for AU formats
set(MANUFACTURER_CODE MDSP)

# A unique four-character plugin id
# Note: this must have at least one upper-case character
# Change me! This code must be unique for every derived plugin.
set(PLUGIN_CODE AP01)

# This command allows running tests from the "build" folder (the one where CMake generates the project to).
enable_testing()

# Add the assets.
#add_subdirectory(assets)

# Add the plugin source code.
add_subdirectory(source)

# Add the test(s).
add_subdirectory(test)
