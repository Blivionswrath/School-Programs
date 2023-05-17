using System;

namespace Section2
{
    class Program
    {

        const string Q1 = "4)	Given a typed Stack collection named teams that contains strings," +
            " write a statement that retrieves the first item in the stack and stores it in a string variable named team." +
            "The statement should not delete the retrieved item from the stack",
            A1 = "string team = teams.Peek()",
            Q2 = "5)	Given a decimal array named testScores that contains test scores for a class, " +
            "write code that will calculate the average of the contents of the array, and then display " +
            "the average score in a message box.",
            A2 = "int sum = 0\nfor (int i = 0; i < testScores.Length(); i++) {\n" +
            "sum += testScores[i];\n}\n" +
            "decimal average = sum / testScores.Length();" +
            "MessageBox.Show(\"Average Score\" + average)";


        static void Main(string[] args)
        {
            Book p1 = new Book("BXJ456D", "Moby Dick", 9.50m, "Herman Mellville");
            Software p2 = new Software("4XJL5603F", "AI creation software", 499.95m, "2.0.1");
            Product p3 = new Product("JBLEFD456", "Some computer chip", 5.4m);
            

            Console.WriteLine(p1.GetDisplayDescription());
            Console.WriteLine(p1.getAuthorText());
            Console.WriteLine(p2.GetDisplayDescription());
            Console.WriteLine(p2.GetDisplayPrice());
            Console.WriteLine(p2.GetDisplayVersion());
            Console.WriteLine(p3.GetDisplayDescription());
            Console.WriteLine(p3.GetDisplayPrice());

            Console.Write("\n\n");
            Console.Write(Q1);
            Console.Write("\n\n");
            Console.WriteLine(A1);
            Console.Write("\n\n");
            Console.WriteLine(Q2);
            Console.WriteLine(A2);
        }

    }
}
