using System;
using System.Collections.ObjectModel;
using System.Xml;

namespace RssReader
{
    [Serializable]
    public class RssFeed
    {
        public  string  Title { get; set; }
        public ObservableCollection<RssItem> Items { get; set; }

        public RssFeed()
        {}

        public RssFeed(string url)
        {
            Items = new ObservableCollection<RssItem>();
            XmlTextReader xmlTextReader = new XmlTextReader(url);
            XmlDocument xmlDoc = new XmlDocument();

            try
            {
                xmlDoc.Load(xmlTextReader);
                xmlTextReader.Close();

                XmlNode channelXmlNode = xmlDoc.GetElementsByTagName("channel")[0];

                if (channelXmlNode != null)
                {
                    foreach (XmlNode chanNode in channelXmlNode.ChildNodes)
                    {
                        switch (chanNode.Name)
                        {
                            case "title":
                                Title = chanNode.InnerText;
                                break;
                            case "item":
                                Items.Add(new RssItem(chanNode));
                                break;
                        }
                    }
                }
                else throw new Exception("Bad Xml");
            }
            catch (System.Net.WebException webEx)
            {
                if (webEx.Status ==
                    System.Net.WebExceptionStatus.NameResolutionFailure)
                {
                    throw new Exception("Cant set connection.\r\n" + url);
                }
                else
                {
                    throw;
                }
            }
            catch (Exception e)
            {
                throw e;
            }
            finally
            {
                xmlTextReader.Close();
            }
        }
    }
}
