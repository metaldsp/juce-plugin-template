# JUCE Audio Plugin Template

This is based on [WolfSound's Audio Plugin Template](https://github.com/JanWilczek/audio-plugin-template)

Icon is from [pamplejuce](https://github.com/sudara/pamplejuce/)

Want to create an audio plugin (e.g., a VST3 plugin) with C++ but don't know how to go about?

Heard about the [JUCE C++ framework](https://github.com/juce-framework/JUCE) but not sure how to start a JUCE project?

Want to use CMake with JUCE but don't know how?

Want to be able to easily integrate third-party C++ libraries to your project?

Want to unit test your audio plugin?

Want to ensure maximum safety of your software?

And all this with a click of a button?

Well, this template allows you to immediately start your JUCE C++ framework audio plugin project with a CMake-based project structure. It involves

* clear repo structure
* C++ 20 standard
* effortless handling of third-party dependencies with the CPM package manager; use the C++ libraries you want together with JUCE
* highest warning level and "treat warnings as errors"
* ready-to-go unit test project with GoogleTest
* devcontainer

Additionally

* continuous integration made easy with Github actions: build and run tests on the main branch and on every pull request
* automatic clang-format on C++ files run on every commit; don't worry about code formatting anymore!

I am personally using this template all the time.

Feel free to propose suggestions 😉

## Usage

This is a template repository which means you can right click "Use this template" on GitHub and create your own repo out of it.

After cloning it locally, you can proceed with the usual CMake workflow.

In the main repo directory execute

```bash
$ cmake -S . -B build
$ cmake --build build
```

The first run will take the most time because the dependencies (CPM, JUCE, and googletest) need to be downloaded.

Alternatively, you can use bundled CMake presets:

```bash
$ cmake --preset default # uses the Ninja build system
$ cmake --build build
$ ctest --preset Default
```

Existing presets are `Default`, `Release`, and `Xcode`.

Don't forget to change "YourPluginName" to, well, your plugin name everywhere 😉
