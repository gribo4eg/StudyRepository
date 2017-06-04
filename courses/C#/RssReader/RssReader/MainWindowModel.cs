using GalaSoft.MvvmLight.Command;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Xml.Serialization;

namespace RssReader
{
    public class MainWindowModel
    {
        public static ObservableCollection<RssFeed> Channels { get; set; }

        public MainWindowModel()
        {
            Channels = new ObservableCollection<RssFeed>();

            XmlSerializer formatter = new XmlSerializer(typeof(ObservableCollection<RssFeed>));
            using (FileStream fs = new FileStream("channels.xml", FileMode.OpenOrCreate))
            {
                Channels = (ObservableCollection<RssFeed>) formatter.Deserialize(fs);
            }
        }

        private ICommand _updateCommand;

        public ICommand UpdateCommand => _updateCommand ?? (_updateCommand = new RelayCommand(() =>
        {
            List<string> urls = ReadUrls();
            try
            {
                var newChannels = new ObservableCollection<RssFeed>();
                foreach (string url in urls)
                {
                    RssFeed rssFeed = new RssFeed(url);
                    foreach (var channel in Channels)
                    {
                        if (rssFeed.Title == channel.Title)
                        {
                            newChannels.Add(channel);
                        }
                    }
                }
                Channels.Clear();
                foreach (var channel in newChannels)
                {
                    Channels.Add(channel);
                }
                foreach (string url in urls)
                {
                    RssFeed rssFeed = new RssFeed(url);
                    RssFeed inList = null;

                    bool haveThis = false;

                    foreach (RssFeed feedInList in Channels)
                    {
                        if (feedInList.Title != rssFeed.Title) continue;
                        haveThis = true;
                        inList = feedInList;
                        break;
                    }

                    if (haveThis)
                    {
                        CheckFeedTime();
                        var newFeed = new ObservableCollection<RssItem>(inList.Items);
                           
                        foreach (var rssFeedItem in rssFeed.Items)
                        {
                            bool found = inList.Items.Any(feedItem => feedItem.Title == rssFeedItem.Title);
                            if (!found)
                            {
                                newFeed.Insert(0, rssFeedItem);
                            }
                        }
                        inList.Items.Clear();
                        foreach (var item in newFeed)
                        {
                            inList.Items.Add(item);
                        }
                    }
                    else
                    {
                        Channels.Add(rssFeed);
                    }
                }
                MessageBox.Show("News Updated!");
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message, "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }));

        private static void CheckFeedTime()
        {
            DateTime nowDate = DateTime.Now;

            foreach (var channel in Channels)
            {
                var items = new ObservableCollection<RssItem>(channel.Items);
                foreach (var item in items)
                {
                    DateTime itemDate = Convert.ToDateTime(item.Date);
                    TimeSpan ts = nowDate - itemDate;

                    if(Convert.ToInt16(ts.Minutes) > 5)
                    {
                        channel.Items.Remove(item);
                    }
                }
            }
        }

        private static List<string> ReadUrls()
        {
            string path = Directory.GetCurrentDirectory();
            string file = path + "\\Urls.txt";
            StreamReader fs = new StreamReader(file);
            List<string> urls = new List<string>();
            while (true)
            {
                string s = fs.ReadLine();
                if (String.IsNullOrEmpty(s)) break;
                urls.Add(s);
            }
            return urls;
        }
    }
}
