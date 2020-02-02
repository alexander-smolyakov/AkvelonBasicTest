// Link on task -> https://www.codewars.com/kata/52597aa56021e91c93000cb0/csharp

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovingZerosToTheEnd
{
    class moving_zeros_to_the_end
    {
        public static int[] MoveZeroes(int[] arr)
        {
            int[] result = new int[arr.Length];

            int j = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] != 0)
                {
                    result[j] = arr[i];
                    j++;
                }
            }

            for (; j < arr.Length; j++)
            {
                result[j] = 0;
            }

            return result;
        }

        public static int Main()
        {
            // Test case from Codewars
            int[] array = new int[] { 1, 2, 1, 1, 3, 1, 0, 0, 0, 0 };
            int[] excepted_result = new int[] { 1, 2, 1, 1, 3, 1, 0, 0, 0, 0 };
            int[] result = moving_zeros_to_the_end.MoveZeroes(array);

            Console.WriteLine(excepted_result.SequenceEqual(result));

            return 0;
        }
    }
}
