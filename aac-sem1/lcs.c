// longest common subsequence

#include <stdio.h>
#include <string.h>
int main()
{

    char str1[100], str2[100];
    printf("Enter strings:");
    scanf("%s%s", str1, str2);

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    int lcs[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; i++)
    {
        lcs[i][0] = 0;
    }

    for (int i = 0; i <= n2; i++)
    {
        lcs[0][i] = 0;
    }

    // rule if equal add +1 to diagonal v
    // if not equal check max from left and above of current number and pu
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                if (lcs[i][j - 1] > lcs[i - 1][j])
                    lcs[i][j] = lcs[i][j - 1];
                else
                    lcs[i][j] = lcs[i - 1][j];
            }
        }
    }

    // now rebuild the string from the table
    int i = n1;
    int j = n2;
    int n = lcs[n1][n2];

    char ans[n + 1];
    ans[n] = '\0';

    while (i > 0 && j > 0)
    {
        // there are 3 cases
        // case 1 character match
        if (str1[i - 1] == str2[j - 1])
        {
            ans[--n] = str1[i - 1];
            i--;
            j--;
        }//case 2 left and upper check 
        else if (lcs[i - 1][j] > lcs[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("lcs=%s\n", ans);

    return 0;
}
