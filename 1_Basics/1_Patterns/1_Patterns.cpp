// 3rd June, 2025
//  In this program, I have practiced several patterns.
//  This is not asked in interviews but it gives a good grasp about the loops, which are in turn beneficial for DSA.

/*
Theory:
Patterns-->> Contain nested loops
1. The outer loop is specifically for the rows, count the number of lines.
2. The inner loop are for the columns and connect them somehow to the rows.
3. Print the required letter (*) inside the inner for loop.
4. Observe symmetry inn case of some pattern.(OPTIONAL because not applied in all).
*/

#include <iostream>
using namespace std;

void pattern1()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern2()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern3()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5()
{
    for (int i = 5; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern6()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern7()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (2 * n) - (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9()
{
    pattern7();
    pattern8();
}

void pattern10() // Do this again
{
    int n = 5;
    for (int i = 1; i <= (2 * n) - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern11()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j % 2 != 0)
                cout << "0";
            else
                cout << "1";
        }
        cout << endl;
    }
}

void pattern12()
{
    int n = 5;
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

void pattern13()
{
    int n = 5;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++, count++)
        {
            cout << count << " ";
        }
        cout << endl;
    }
}

void pattern14()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern15()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + (n - i - 1); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern16()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern17()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {

            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern19()
{
    int n = 5;
    int iniS = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // The spaces increase by 2 every time we hit a new row.
        iniS += 2;
        cout << endl;
    }
}

void pattern20()
{
    int n = 5;
    // for the upper half of the pattern.

    // initial spaces.
    int iniS = 0;
    for (int i = 0; i < n; i++)
    {

        // for printing the stars in the row.
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        // The spaces increase by 2 every time we hit a new row.
        iniS += 2;

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }

    // for lower half of the pattern

    // initial spaces.
    iniS = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // The spaces decrease by 2 every time we hit a new row.
        iniS -= 2;

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

void pattern21()
{
    int n = 5;
    // initialising the spaces.
    int spaces = 2 * n - 2;

    // Outer loop for printing row.
    for (int i = 1; i <= 2 * n - 1; i++)
    {

        // stars for first half
        int stars = i;

        // stars for the second half.
        if (i > n)
            stars = 2 * n - i;

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // for printing the spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

void pattern22()
{
    int n = 5;
    // outer loop for no. of rows.
    for (int i = 0; i < n; i++)
    {

        // inner loop for printing the stars at borders only.
        for (int j = 0; j < n; j++)
        {

            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";

            // if not border index, print space.
            else
                cout << " ";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

void pattern23()
{
    int n = 5;
    // Outer loop for no. of rows
    for (int i = 0; i < 2 * n - 1; i++)
    {

        // inner loop for no. of columns.
        for (int j = 0; j < 2 * n - 1; j++)
        {

            // Initialising the top, down, left and right indices of a cell.
            int top = i;
            int bottom = j;
            int right = (2 * n - 2) - j;
            int left = (2 * n - 2) - i;

            // Min of 4 directions and then we subtract from n
            // because previously we would get a pattern whose border
            // has 0's, but we want with border N's and then decreasing inside.
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}

int main()
{
    // pattern1();
    // pattern2();
    // pattern3();
    // pattern4();
    // pattern5();
    // pattern6();
    // pattern7();
    // pattern8();
    // pattern9();
    // pattern10();
    // pattern11();
    // pattern12();
    // pattern13();
    // pattern14();
    // pattern15();
    // pattern16();
    // pattern17();
    // pattern18();
    // pattern19();
    // pattern20();
    // pattern21();
    // pattern22();
    // pattern23();

    return 0;
}
