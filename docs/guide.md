# Gothic 1 Remake Tools — User Guide

A clean utility pack for Gothic 1 Remake players, modders, and save editors.

## Features

- Save backup helper
- Config presets
- Experimental stat editor structure
- Modding notes for Unreal Engine 5 based projects
- Research-friendly layout for future trainer and memory-table work

## Installation

1. Download the latest ZIP from GitHub Releases.
2. Extract the archive to any folder outside the game directory.
3. Run `Gothic1RemakeTools.exe` as a normal user.
4. Create a backup before editing saves or configs.

## Recommended folder layout

```text
Gothic1RemakeTools/
├─ Gothic1RemakeTools.exe
├─ config.json
├─ docs/
├─ backups/
└─ logs/
```

## Safety notes

- Use only in single-player/offline mode.
- Always back up saves before editing.
- Do not use with online services, anti-cheat environments, or multiplayer mods.
- This project is unofficial and not affiliated with THQ Nordic, Alkimia Interactive, Piranha Bytes, or Gothic.

## Troubleshooting

### Tool does not start

Install the latest Microsoft Visual C++ Redistributable and .NET Desktop Runtime if your build requires it.

### Save file is not detected

Check the configured save path in `config.json`.

### Game update broke offsets

Update the values in the configuration file or wait for a new release.
