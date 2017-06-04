using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace RssReader
{
    [Serializable]
    public class RssItem
    {
        public string Title { get; set; }
        public string Link { get; set; }
        public string Description { get; set; }
        public string Date { get; set; }

        public RssItem()
        { }

        public RssItem(XmlNode item)
        {

            foreach (XmlNode tag in item.ChildNodes)
            {
                switch (tag.Name)
                {
                    case "title":
                        Title = tag.InnerText;
                        break;
                    case "link":
                        Link = tag.InnerText;
                        break;
                    case "description":
                        Description = tag.InnerText;
                        break;
                }
            }

            Date = DateTime.Now.ToString(new CultureInfo("en-US"));
        }
    }
}
