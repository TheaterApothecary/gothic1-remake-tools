# Finding Addresses and Offsets

This document is a research note for maintaining Gothic 1 Remake modding tools.

## Goal

Keep offsets and memory-related values separated from the source code so future game updates are easier to support.

## Suggested workflow

1. Record the game build version.
2. Create a clean save file.
3. Change only one value at a time in-game.
4. Compare values before and after.
5. Store confirmed values in `assets/tool-config.example.json`.

## Example config fields

```json
{
  "gameVersion": "1.0.0",
  "processName": "GothicRemake-Win64-Shipping.exe",
  "saveFolder": "%LOCALAPPDATA%/GothicRemake/Saved/SaveGames",
  "features": {
    "backupSaves": true,
    "editStats": false,
    "scanMemory": false
  }
}
```

## Maintenance notes

- Never hard-code offsets directly in the release build.
- Keep experimental values marked as experimental.
- Confirm changes after every game patch.
- Prefer readable configs over hidden binary settings.

## Disclaimer

This repository is intended for educational, modding, and single-player utility purposes only.
