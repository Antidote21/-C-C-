using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ch4_배열
{
    internal class Gugudan
    {
        static void Main(string[] args)
        {
            int j = 0;
            int i = 0;
            int k = 0;
            for (k = 0; k < 9; k++)
            {
                for (i = 1; i < 10; i++)
                {
                    for (j = 1; j < 4; j++)
                    {
                        Console.Write("{0}x{1}={2:D2}\t",k+j, i, i * (j+k));
                    }
                    Console.WriteLine();
                }
                k += 2;
                Console.WriteLine();
            }
       
        }
    }
}
