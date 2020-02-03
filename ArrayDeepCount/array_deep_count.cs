// Link on task -> https://www.codewars.com/kata/596f72bbe7cd7296d1000029/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayDeepCount
{
    class array_deep_count
    {
        public static int DeepCount(object a)
        {
            int length = 0;

            if (a.GetType().BaseType.Name == "Array")
            {
                foreach (var field in (Array)a)
                {
                    if (field.GetType().BaseType.Name == "Array")
                    {
                        length += DeepCount(field);
                    }
                    length++;
                }
            }

            return length;
        }

        public static int Main()
        {
            //Test case from Codewars
            int result = DeepCount(new object[] { 1, 2, new object[] { 3, 4, new object[] { 5 } } }); // Must return 7
            Console.WriteLine(result);

            return 0; 
        }
    }
}
