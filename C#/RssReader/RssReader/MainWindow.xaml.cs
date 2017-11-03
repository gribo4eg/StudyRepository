using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.ComponentModel;
using System.Xml.Serialization;
using System.IO;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Text.RegularExpressions;
using System.Windows.Media.Animation;

namespace RssReader
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private readonly Hashtable _stopWords = new Hashtable();
        public MainWindow()
        {
            InitializeComponent();
            
            string path = Directory.GetCurrentDirectory();
            string file = path + "\\stop-words.txt";
            StreamReader fs = new StreamReader(file);
            while (true)
            {
                string s = fs.ReadLine();
                if (String.IsNullOrEmpty(s)) break;
                _stopWords.Add(s, s);
            }
            
        }

        private void MainWindow_Closing(object sender, CancelEventArgs e)
        {
            XmlSerializer formatter = new XmlSerializer(typeof(ObservableCollection<RssFeed>));
            
            using (FileStream fs = new FileStream("channels.xml", FileMode.Create))
            {
                formatter.Serialize(fs, MainWindowModel.Channels);
            }
        }

        private void searchBtn_Click(object sender, RoutedEventArgs e)
        {
            string word = searchTextBox.Text;
            searchTextBox.Text = "";
            if (string.IsNullOrEmpty(word))
                return;
            if (_stopWords.Contains(word))
                MessageBox.Show("Your word belong to \"stop-words\" list\nChoose another word");
            else
            {
                List<CountObj> resultItems = new List<CountObj>(10);
                foreach (var channel in MainWindowModel.Channels)
                {
                    foreach (var item in channel.Items)
                    {
                        var count = 0;
                        string title = item.Title,
                               desc  = item.Description;
                        count += new Regex(word).Matches(title).Count;
                        count += new Regex(word).Matches(desc).Count;
                        AddToList(resultItems, new CountObj(count, item));
                    }
                }

                if (resultItems.Count == 0)
                {
                    MessageBox.Show("Can't find news!");
                    return;
                }
                if (resultItems.Count > 10)
                    resultItems = new List<CountObj>(resultItems.GetRange(0, 10));
                else
                    resultItems = new List<CountObj>(resultItems.GetRange(0, resultItems.Count));

                List<RssItem> result = (from item in resultItems where item != null select item.Item).ToList();
                
                Window window = new IndexingWindow(result);
                window.Show();
            }
        }

        private void AddToList(List<CountObj> list, CountObj obj)
        {
            if (obj.Count == 0) return;
            bool contain = list.Any(inList => inList.Item.Title == obj.Item.Title);
            if (contain) return;
            if (list.Count < 10)
            {
                list.Add(obj);
            }
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    if (list[i].Count < obj.Count || list[i + 1].Count >= obj.Count) continue;
                    list.Insert(i, obj);
                    break;
                }
            }
            list.Sort();
        }

        private void addUrlBtn_Click(object sender, RoutedEventArgs e)
        {
            string url = addUrlTextBox.Text;
            addUrlTextBox.Text = "";

            if (string.IsNullOrEmpty(url)) return;
            Regex rgxUrl = new Regex(
                "http://[-a-z0-9_.:]+/[-a-z0-9_:@&?=+,.!/~*`%$]*(\\.rss)?");
            if (!rgxUrl.IsMatch(url))
            {
                MessageBox.Show("Invalid URL:\n"+url);
                return;
            }
            string path = Directory.GetCurrentDirectory();
            string file = path + "\\Urls.txt";
            string text = url + Environment.NewLine;
            File.AppendAllText(file, text, Encoding.UTF8);
        }
    }
}
