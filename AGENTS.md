## Build Commands

```sh
cmake --preset Clang
cmake --build --preset Clang
ctest --preset Clang
```

## Audio-Thread Rules

- Treat `processBlock()` and all of its callees as realtime code: do not allocate, lock, perform
  I/O, or access UI objects there.
- Start `processBlock()` with `juce::ScopedNoDenormals`.
- Cache APVTS raw parameter atomics in the processor constructor and load them with
  `std::memory_order_relaxed` in the audio callback. Do not call `getRawParameterValue()` from
  the callback.
- Allocate and prepare DSP objects in `prepareToPlay()`, then reset stateful processors in
  `releaseResources()`.
- Move audio-to-UI updates onto the message thread with `juce::Timer` or `juce::AsyncUpdater`.
