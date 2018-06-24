using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// https://www.dreamincode.net/forums/topic/352580-linq-by-example-1-enumerable-methods-a-l/

namespace LearnLinq
{
    class Record
    {
        public Record(int id)
        {
            ID = id;
            description = $"description of {id}";
        }
        public int ID;
        public string description;
    }
    class Program
    {
        static void Main(string[] args)
        {
            var records = new List<Record> { new Record(1), new Record(2), new Record(3), new Record(4) };
            var ids = new List<int> { 2, 3 };
            var selected = records.Where(r => ids.Contains(r.ID));

            foreach (var s in selected)
            {
                Console.WriteLine(s.description);
            }
        }
    }
}
