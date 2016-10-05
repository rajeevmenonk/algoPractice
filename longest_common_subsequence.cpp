#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

void get_common_subsequence (vector< vector <int> > &calc_table,
                             string &str1,
                             string &str2,
                             string &sub_seq)
{
    int i = str1.length();
    int j = str2.length();
    
    while(i!=0 && j!=0)
    {
        if( calc_table[i][j] == (calc_table[i-1][j-1] + 1))
        {
            sub_seq+= str1[i-1];
            j--;
        }
        i--;
    }

    // The sub string is in the reverse order.
    string temp = sub_seq;
    for (int k=0; k<sub_seq.length(); k++)
    {
        sub_seq[k] = temp[sub_seq.length() -1 -k];
    }

}

void calc (vector< vector <int> > &calc_table,
           string &str1,
           string &str2)
{
    int str1_len = str1.length();
    int str2_len = str2.length();

    // Setting default values
    for (int i=0; i<str1_len+1; i++)
        calc_table[i][0] = 0;

    // Setting default values
    for (int i=0; i<str2_len+1; i++)
        calc_table[0][i] = 0;

    for (int i = 1; i<str1_len+1; i++)
    {
        for (int j = 1; j<str1_len+1; j++)
        {
             // If the chars are the same, then incrememt
             // by one to the diagonal value.
             if (str1[i-1] == str2[j-1])
             {
                 calc_table[i][j] = calc_table[i-1][j-1] + 1;
             }
             else
             {
                 // If the values are not the same, use the 
                 // maximum of the upper value or the value to the left.
                 if (calc_table[i-1][j] > calc_table[i][j-1])
                 {
                     calc_table[i][j] = calc_table[i-1][j];
                 }
                 else
                 {
                     calc_table[i][j] = calc_table[i][j-1];
                 }
             }
        }
    }
}

int main ()
{
    string str1, str2;
    cin>> str1;
    cin>> str2;

    int str1_len = str1.length();
    int str2_len = str2.length();

    vector< vector <int> > calc_table(str1_len+1, vector<int> (str2_len + 1));
    calc(calc_table, str1, str2);

    string sub_seq = "";
    get_common_subsequence(calc_table, str1, str2, sub_seq);

    std::cout << "The size is " << calc_table[str1_len][str2_len] << " and the largest string is " << sub_seq.c_str() << "\n";

    return 0;
}
