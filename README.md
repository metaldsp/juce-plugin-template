# JUCE Plugin Template

A compact starting point for audio-effect plugins built with JUCE, CMake, and GoogleTest.
It demonstrates an `AudioProcessorValueTreeState` parameter, realtime-safe parameter access,
state persistence, and a standard JUCE editor attachment.

## Create a Plugin

Before shipping a derived plugin, update the project metadata in `CMakeLists.txt`:

- `PROJECT_NAME`, `PRODUCT_NAME`, and `PRODUCT_NAME_WITHOUT_VERSION`
- `COMPANY_NAME` and `BUNDLE_ID`
- `MANUFACTURER_CODE` and the unique four-character `PLUGIN_CODE`

`AP01` is only a placeholder. Reusing it for multiple plugins causes host-identification
conflicts.

## Build and Test

Install CMake, Ninja, a C++23 compiler, and the platform SDK required by JUCE. Configure,
build, and test the default Clang preset from the repository root:

```sh
cmake --preset Clang
cmake --build --preset Clang
ctest --preset Clang
```

The first configure downloads JUCE and GoogleTest into the ignored `libs/` directory.

## Starter Architecture

`PluginParameters.h` defines the versioned gain parameter. `PluginProcessor` caches its raw
atomic value during construction, loads it once per block, and uses a gain ramp to avoid steps.
`PluginEditor` binds a rotary slider to the same parameter with `SliderAttachment`.

Add DSP state in `prepareToPlay()`, reset it in `releaseResources()`, and keep
`processBlock()` allocation-free and lock-free. Extend the tests whenever a parameter or DSP
stage is added.
