using System.Transactions;

namespace homework1
{
    internal class Total
    {
        static void Main(string[] args)
        {
            string? numStr = "";
            int num = 0;
            int cnt = 0;
            int oddNum = 0;
            int oddSum = 0;
            int evenNum = 0;
            int evenSum = 0;
            while (true)
            {
                Console.Write("하나의 정수 입력 : ");
                numStr = Console.ReadLine();
                num = Convert.ToInt16(numStr);
                if (num == -1) break;
                else if (num < 0 || num > 10)
                {
                    Console.WriteLine("1부터 10까지의 정수를 입력하세요.");
                    continue;
                }
                cnt++;
                if (num % 2 == 1)
                {
                    oddNum++;
                    oddSum += num;
                }
                else if (num % 2 == 0)
                {
                    evenNum++;
                    evenSum += num;
                }
            }
            Console.WriteLine("입력 데이터 갯수는 {0}", cnt);
            Console.WriteLine("입력 데이터 짝수 갯수는 {0}", evenNum);
            Console.WriteLine("입력 데이터 짝수의 합은 {0}", evenSum);
            Console.WriteLine("입력 데이터 홀수 갯수는 {0}", oddNum);
            Console.WriteLine("입력 데이터 홀수의 합은 {0}", oddSum);
        }

    }
}
