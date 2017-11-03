using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RssReader
{
    public class CountObj : IComparable<CountObj>
    {
        public int Count { get; set; }
        public RssItem Item { get; set; }

        public CountObj(int count, RssItem item)
        {
            Count = count;
            Item = item;
        }

        public int CompareTo(CountObj obj)
        {
            return obj.Count.CompareTo(Count);
        }
    }
}
