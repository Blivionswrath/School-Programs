//Tanner Gordon
//OCCC C# Online
//Section 1 of Exam 1
//

using System;
using System.Text;
namespace Exam1
{
    class Section1
    {
        static void Main(string[] args)
        {
            int selection, int1, int2;
            string s1, s2, output;


            while (true)
            {
                output = "";
                Console.WriteLine("Please enter a function number [1-5]");
                string input = Console.ReadLine();

                if (!int.TryParse(input, out selection)) { continue; }

                if (selection == 3 || selection == 5)
                {
                    Console.WriteLine("Please enter a string: ");
                    s1 = Console.ReadLine();

                    if (selection == 5 )
                    {
                        Console.WriteLine("Please enter a string: ");
                        s2 = Console.ReadLine();
                        output = numberFive(s1, s2);
                    }else
                    {
                        output = numberThree(s1);
                    }

                }
                else
                {
                    Console.WriteLine("Please enter an integer: ");
                    if (!int.TryParse(Console.ReadLine(), out int1)) { continue; }

                    //Check for four since it takes one input
                    if (selection == 4 )
                    {
                        if (int1 < 0) int1 *= -1;
                        output = numberFour((uint)int1).ToString();
                    }

                    Console.WriteLine("Please enter another integer: ");
                    if (!int.TryParse(Console.ReadLine(), out int2)) { continue; }



                    switch (selection)
                    {
                        case 1:
                            output = numberOne(int1, int2).ToString();
                            break;
                        case 2:
                            output = numberTwo(int1, int2).ToString();
                            break;

                    }

                }

                Console.WriteLine(output);
            }
        }

        
        /// <summary>
        /// Function number one from exam one
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns>Returns n1 + n2, unless n1 == n2. This returns n1 * 3</returns>
        static int numberOne(int n1, int n2)
        {
            int result;

            if (n1 == n2)
            {
                result = n1 * 3;
            }
            else
            {
                result = n1 + n2;
            }

            return result;
        }

        /// <summary>
        ///Function number two from Exam 1
        /// </summary>
        /// <param name="n1"></param>
        /// <param name="n2"></param>
        /// <returns></returns>
        static bool numberTwo(int n1, int n2)
        {
            //Check for 30's
            if (n1 == 30 || n2 == 30)
            {
                return true;
            }
            //Check the sum 
            if (n1 + n2 == 30)
            {
                return true;
            }

            return false;
        }


        static string numberThree(string s1)
        {

            int lastIndex = s1.Length - 1;

            StringBuilder swapped = new StringBuilder(s1);

            //Swap the first and last characters
            swapped[0] = s1[lastIndex];
            swapped[lastIndex] = s1[0];

            //Return the final string
            return swapped.ToString();
        }

        static bool numberFour(uint n)
        {

            if (n % 3 == 0) return true;
            if (n % 4 == 0) return true;

            return false;
        }

        static string numberFive(string s1, string s2)
        {
            StringBuilder result = new StringBuilder(s1 + s2);

            removeDoubles(ref result);


            return result.ToString();
        }
        /// <summary>
        /// A recursive Function to remove duplicate characters
        /// </summary>
        /// <returns>Returns true if end of string is encountered</returns>
        static bool removeDoubles(ref StringBuilder s)
        {


            //If the string becomes too short in the process, it is considered invalid
            if (s.Length < 2) throw new ArgumentException();

            char previous = s[0];

            for(int i = 1; i < s.Length; i++)
            {
                if (s[i] == previous)
                {
                    s.Remove(i, 1);
                    if (removeDoubles(ref s)) { return true; }
                    else { return false; }
                }

                previous = s[i];
            }
            return true;
        }
    }
}
