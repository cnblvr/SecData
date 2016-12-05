using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace laba4Client
{
    static class Settings
    {
        static public Dictionary<string, string> ReadFile(string path)
        {
            string file = string.Empty;
            if (File.Exists(path))
            {
                StreamReader sr = File.OpenText(path);
                try
                {
                    file = sr.ReadToEnd();
                }
                catch (Exception) { throw new Exception("Ошибка при чтении файла настроек."); }
                finally { sr.Close(); }
            }
            else
                throw new Exception("Файл " + path + " не найден.");
            Regex rx = new Regex("\\[(?<key>[a-z0-9_]+)\\] (?<value>[^\\r\\n]*)\\r?\\n?");
            MatchCollection matches = rx.Matches(file);
            Dictionary<string, string> settings = new Dictionary<string, string>();
            foreach (Match match in matches)
                settings.Add(match.Groups["key"].Value, match.Groups["value"].Value);
            return settings;
        }
        static public void WriteFile(string path, Dictionary<string, string> settings)
        {
            string file = string.Empty;
            foreach (KeyValuePair<string, string> en in settings)
            {
                file += "[" + en.Key + "] " + en.Value + Environment.NewLine;
            }
            if (File.Exists(path))
            {
                FileStream fs = File.OpenWrite(path);
                try
                {
                    byte[] bytes = Encoding.ASCII.GetBytes(file);
                    fs.Write(bytes, 0, bytes.Length);
                }
                catch (Exception) { throw new Exception("Ошибка при записи файла настроек."); }
                finally { fs.Close(); }
            }
            else
                throw new Exception("Файл " + path + " не найден.");

        }
    }
}
