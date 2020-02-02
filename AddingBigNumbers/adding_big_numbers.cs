// Link on task -> https://www.codewars.com/kata/525f4206b73515bffb000b21/csharp

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace AddingBigNumbers
{
    class adding_big_numbers
    {
        public static string Add(string a, string b)
        {
            return (BigInteger.Parse(a) + BigInteger.Parse(b)).ToString();
        }

        public static int Main()
        {
            string a = "123546512132132131313279876532";
            string b = "454654879721321321321546578321";
            string expected_result = "578201391853453452634826454853";

            string result = Add(a, b);

            Console.WriteLine(expected_result.SequenceEqual(result));

            return 0;
        }
    }
}
