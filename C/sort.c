//归并排序；

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void*a, const void*b)
{
    return (*(int*)a - *(int*)b);
}

void CreatDate()
{
    remove("data.txt");
    int n = 1000;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file,"w");
    if(fin == NULL)
    {
        perror("fopen error");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        int x = rand() + i;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

int ReadNDataSortToFile(FILE* fout, int n, const char* file)
{
    int x = 0;
    int* a = (int*)malloc(sizeof(int) * n);
    if(a == NULL)
    {
        perror("malloc error");
        return 0;
    }

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(fscanf(fout, "%d", &x) == EOF)
            break;

        a[j++] = x;
    }

    if(j == 0)
    {
        free(a);
        return 0;
    }

    qsort(a, j, sizeof(int), compare);

    FILE* fin = fopen(file, "w");
    if(fin == NULL)
    {
        perror("fopen error");
        return 0;
    }

    for(int i = 0; i < j; i++)
    {
        fprintf(fin, "%d\n", a[i]);
    }

    free(a);

    fclose(fin);

    return j;
}


void MergeFile(const char* file1, const char* file2, const char* mfile)
{
    FILE* fout1 = fopen(file1, "r");
    if(fout1 == NULL)
    {
        perror("fopen error");
        return;
    }

    FILE* fout2 = fopen(file2, "r");
    if(fout2 == NULL)
    {
        perror("fopen error");
        return;
    }

    FILE* mfin = fopen(mfile, "w");
    if(mfin == NULL)
    {
        perror("fopen error");
        return;
    }

    int x1 = 0;
    int x2 = 0;
    int ret1 = fscanf(fout1, "%d", &x1);
    int ret2 = fscanf(fout2, "%d", &x2);

    while(ret1 != EOF && ret2 != EOF)
    {
        if(x1 < x2)
        {
            fprintf(mfin, "%d\n", x1);
            ret1 = fscanf(fout1, "%d", &x1);
        }
        else
        {
            fprintf(mfin, "%d\n", x2);
            ret2 = fscanf(fout2, "%d", &x2);
        }
    }

    while(ret1 != EOF)
    {
        fprintf(mfin, "%d\n", x1);
        ret1 = fscanf(fout1, "%d", &x1);
    }

    while(ret2 != EOF)
    {
        fprintf(mfin, "%d\n", x2);
        ret2 = fscanf(fout2, "%d", &x2);
    }

    fclose(fout1);
    fclose(fout2);
    fclose(mfin);
}

int main()
{
    //CreatDate();

    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";
    const char* mfile = "mfile.txt";


    FILE* fout = fopen("data.txt", "r");
    if(fout == NULL)
    {
        perror("fopen error");
        return 0;
    }

    ReadNDataSortToFile(fout, 100, file1);
    ReadNDataSortToFile(fout, 100, file2);

    while(1)
    {
        MergeFile(file1, file2, mfile);
        //删除文件；
        remove(file1);
        remove(file2);
        //重命名；
        rename(mfile, file1);

        if(ReadNDataSortToFile(fout, 100, file2) == 0)
            break;
    }

    fclose(fout);

    return 0;
}