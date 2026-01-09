# Commit message instructions (Conventional Commits)

Use **Conventional Commits v1.0.0** for all commit messages.

## Format

```
<type>[optional scope][!]: <description>

[optional body]

[optional footer(s)]
```

50 characters limit for the summary (first line).

72 characters limit for each line of the body.

### Rules

- **type**: required, lowercase.
- **scope**: optional, lowercase, short noun (no spaces or slashes). Prefer one of the recommended repo scopes below; omit it if the change is broad or no single scope fits.
- **!**: add immediately before `:` to indicate a breaking change.
- **description**: required, imperative mood (e.g., "add", "fix", "remove"), concise, no trailing period.
- **body**: optional; explain *why* and notable behavior changes. always include it complex changes.
- **footers**: optional; use for breaking changes and issue references.

## Types (use these)

- `feat`: user-facing feature
- `fix`: user-facing bug fix
- `perf`: performance improvement
- `refactor`: code change that is neither a feature nor a fix
- `test`: add or update tests
- `build`: build system or external dependencies (CMake, toolchain)
- `ci`: CI configuration (if present)
- `docs`: documentation only
- `style`: formatting only (no behavior change)
- `chore`: maintenance tasks that don’t modify production behavior
- `revert`: revert a previous commit (see Reverts)

## Recommended scopes for this repo

Choose the closest match. Use exactly one scope when one area clearly owns the change, and omit the scope for cross-cutting updates.

- `plugin`: top-level plugin integration in `source/PluginProcessor.*` or `source/PluginEditor.*`
- `dsp`: audio, convolution, IR mixing, or engine behavior in `source/dsp/*`
- `ui`: JUCE UI components in `source/ui/*`
- `cmake`: `CMakeLists.txt`, `CMakePresets.json`, or files under `cmake/`
- `assets`: bundled assets under `assets/`
- `test`: automated tests under `test/`
- `deps`: vendored or third-party code under `libs/`
- `packaging`: packaging assets or scripts under `packaging/`

Valid examples: `feat(ui): ...`, `fix(dsp): ...`, `build(cmake): ...`

Avoid invalid or vague scopes such as `ui/loader`, `ui,loader`, `source`, or `misc`.

## Breaking changes

Indicate breaking changes in one of these ways (prefer both when appropriate):

- Add `!` in the header: `feat(dsp)!: change IR normalization behavior`
- Add a footer:

```
BREAKING CHANGE: <explain what changed and how to migrate>
```

## Issue references

Use footers for tracker references when applicable:

- `Refs: #123`
- `Closes: #123`

## Reverts

Use the `revert` type and include a footer referencing the reverted commit SHA:

```
revert: <original header>

This reverts commit <sha>.
```

## Examples

- `feat(dsp): support multi-IR blending`
- `fix(dsp): prevent denormals in convolution tail`
- `perf(dsp): reduce allocations during block processing`
- `refactor(plugin): simplify parameter initialization`
- `test(test): add AudioProcessor state roundtrip coverage`
- `build(cmake): export compile_commands.json by default`
- `docs: document supported sample rates`
- `feat(ui)!: rename preset browser actions`

  `BREAKING CHANGE: preset browser command IDs changed; update host mappings.`
