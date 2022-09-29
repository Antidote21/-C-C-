using System;

public class Grade
{
    static void Main(string[] args)
    {
        int avg = 0;
        string[] name = new string[] { "KBS", "SBS", "YTN", "MBC" };
        Console.WriteLine("학번  이름  국어  영어  수학  총점  평균  석차");
        Console.WriteLine("========================================");
        int[,] jumsu = new int[4, 7] { { 1, 33, 44, 55, 0, 0, 0 }, { 2, 77, 88, 99, 0, 0, 0 }, { 3, 55, 66, 77, 0, 0, 0 }, { 4, 87, 88, 89, 0, 0, 0 } };
        int[] Rank = { 0,0,0,0 };
        for (int i = 0; i < 4; i++)
        {
            jumsu[i, 4] = 0;
            for (int j = 0; j < 7; j++)
            {
                if (j >= 1 && j <= 3)
                {
                    jumsu[i, 4] += jumsu[i, j];
                }
            }
            avg = jumsu[i, 4] / 3;
            jumsu[i, 5] = avg;
        }
        //[2] 순위 알고리즘
        for (int i = 0; i < 5; i++)
        {
           // Rank[i] = 1; // 모든 점수는 1로 초기화
            for (int j = i; j < 5; j++)
            {
                if  (jumsu[i, 5] < jumsu[j, 5] )
                {
                    Rank[i]++; // 더 큰 수가 있으면 증가
                }
            }
        }


        for (int i = 0; i < 4; i++)
        {
            //jumsu[i, 4] = 0;
            for (int j = 0; j < 7; j++)
            {
               // if (j >= 1 && j <= 3) jumsu[i, 4] += jumsu[i, j];
                
                if (j == 1)
                {
                    Console.Write("{0}    ", name[i]);
                    Console.Write("{0}    ", jumsu[i, j]);
                }
                else if (j == 6)
                {
                 
                    Console.Write("{0}", Rank[i]);
                }
                else  Console.Write("{0}    ", jumsu[i, j]);
            
            }
            Console.WriteLine();
        }
        Console.WriteLine("========================================");
    }
}
