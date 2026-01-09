//======================================================================================
// Copyright (c) 2026 Pier Luigi Fiorini
// All rights reserved.
//======================================================================================

#pragma once

namespace AudioPlugin::PluginParameters {

inline constexpr auto gainID = "gain";
inline constexpr int gainVersionHint = 1;
inline constexpr auto gainName = "Gain";
inline constexpr float gainMinimum = -24.0f;
inline constexpr float gainMaximum = 24.0f;
inline constexpr float gainDefault = 0.0f;

} // namespace AudioPlugin::PluginParameters
