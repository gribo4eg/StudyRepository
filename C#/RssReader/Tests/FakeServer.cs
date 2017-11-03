using System;
using System.IO;

namespace Tests
{
    public class FakeServer
    {
        public string RssFeed { get; set; }
        public FakeServer()
        {
            RssFeed = "";
            string path = Directory.GetCurrentDirectory();
            string file = path + "\\Feeds.xml";
            StreamReader fs = new StreamReader(file);
            while (true)
            {
                string s = fs.ReadLine();
                if (string.IsNullOrEmpty(s)) break;
                RssFeed += s;
            }
        }
    }
}