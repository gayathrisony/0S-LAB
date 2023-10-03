#include <stdio.h>
#define max 25
int main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        // Initialize temp to a large value to ensure it's updated correctly.
        temp = -1;
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1 && b[j] >= f[i])
            {
                // Calculate fragment and update temp.
                frag[i] = b[j] - f[i];
                if (temp == -1 || frag[i] < frag[temp])
                {
                    temp = j;
                }
            }
        }
        if (temp != -1)
        {
            ff[i] = temp;
            bf[temp] = 1;
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment:\n");
    for (i = 1; i <= nf; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
}
