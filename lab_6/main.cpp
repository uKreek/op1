#include <iostream>

//1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
//Если в последовательности нет чисел с суммой цифр, равной 19, упорядочить последовательность по невозрастанию.

//2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
//Упорядочить последовательность по неубыванию суммы цифр числа, 
//числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию первой цифры числа, 
//числа с одинаковыми суммами цифр и одинаковыми первыми цифрами дополнительно упорядочить по неубыванию самого числа.




int main()
{
    // const int N_MAX = 10000;
    // int mas[N_MAX];

    // int n;
    // std::cin >> n;

    // input
    // for(int i=0; i<n; i++)
    //     std::cin >> mas[i];

    /*
    ///////////////////////////////////// 1 
    int is_19 = 0;
    for(int i=0; i<n; i++) 
    {
        int s = 0;
        int a = mas[i];
        while (a!=0)
        {
            s += a%10;
            a /= 10;
        }
        if(s == 19) is_19 = 1;
    }
    // 1 sorting
    if(is_19 == 0)
    {
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(mas[i] > mas[j])
                {
                    int tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;
                }
    }
    */

    //////////////////////////////////////// 2
    /*
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
        {
            // sum of digits
            int sumI = 0;
            int nI = mas[i];
            while (nI!=0)
            {   
                sumI += nI%10;
                nI /= 10;
            }
            
            int sumJ = 0;
            int nJ = mas[j];
            while (nJ!=0)
            {    
                sumJ += nJ%10;
                nJ /= 10;
            }

            // first digits
            int firstI = mas[i];
            while(firstI > 9) firstI /= 10;
            int firstJ = mas[j];
            while(firstJ > 9) firstJ /= 10;
            std::cout << firstI << " " << firstJ << std::endl;

            // sorting
            if((sumI > sumJ) || (sumI == sumJ && firstI > firstJ) || (sumI == sumJ && firstI == firstJ && mas[i] > mas[j]))
            {
                int tmp = mas[i];
                mas[i] = mas[j];
                mas[j] = tmp;
            }
            
        }
    */

    ///////////////////////////// 4
    // Сначала введите последовательность. 
    // Затем удалите и продублируйте элементы. Затем выведите полученную последовательность (каждый элемент по одному разу). 
    // Используйте в программе только один массив.

    // Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
    // Удалить из последовательности числа, начинающиеся и заканчивающиеся одной и той же цифрой, 
    // а среди оставшихся продублировать числа, начинающиеся цифрой 3.

    /*
    // deleting
    int newN = 0;
    int newMas[N_MAX];

    for(int i=0;i<n;i++)
    {   
        // first and last digits
        int first = mas[i];
            while(first > 9) first /= 10;
        int last = mas[i] % 10;

        if(first != last)
        {
            newMas[newN] = mas[i];
            newN++;
        }
    }

    //doubling
    for(int i=0;i<newN;i++)
    {
        
        if(mas[i]%10 == 3)
        {
            for(int j=newN; j>i; j--)
                newMas[j] = newMas[j-1];
        i++;
        newN++;
        }
    }


    // output 4
    for(int i=0; i<newN; i++)
        std::cout << newMas[i] << " ";
    */
   
    // output 
    // for(int i=0; i<n; i++)
    //     std::cout << n[i] << " ";  

   

    ////////////////////////////// 3
    // Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
    // Найти строку с наибольшей по абсолютной величине суммой элементов и заменить все элементы этой строки числом 9999.

    int matrix[100][100];
    int n, m;
    std::cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            std::cin >> matrix[i][j];

    // processing
    int maxN = 0;
    int indexMax = -10;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=0;j<m;j++)
        {
            sum += matrix[i][j];
            maxN = std::max(maxN, sum);
        }

        if(sum == maxN) 
            indexMax = i;
    }


    // output
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
            if(i == indexMax)
                matrix[i][j] = 9999;
            std::cout << matrix[i][j] << " ";
            }
        std::cout << std::endl;
    }

    return 0;
}