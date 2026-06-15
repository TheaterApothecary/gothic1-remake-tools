using System;
using System.IO;
using System.Text.Json;

namespace GothicRemakeTools;

public sealed class GothicToolConfig
{
    public string GameVersion { get; set; } = "1.0.0";
    public string ProcessName { get; set; } = "GothicRemake-Win64-Shipping.exe";
    public string SaveFolder { get; set; } = "%LOCALAPPDATA%/GothicRemake/Saved/SaveGames";
    public bool BackupSaves { get; set; } = true;
    public bool EditStats { get; set; } = false;
    public bool ScanMemory { get; set; } = false;

    public static GothicToolConfig Load(string path)
    {
        if (!File.Exists(path))
        {
            var config = new GothicToolConfig();
            config.Save(path);
            return config;
        }

        var json = File.ReadAllText(path);
        return JsonSerializer.Deserialize<GothicToolConfig>(json) ?? new GothicToolConfig();
    }

    public void Save(string path)
    {
        var options = new JsonSerializerOptions { WriteIndented = true };
        var json = JsonSerializer.Serialize(this, options);
        File.WriteAllText(path, json);
    }
}
