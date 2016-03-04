#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stulpeliu_suma.h"

int main()
{
    int s_aukstis=0, s_plotis=0, i, j, k=0, plo=0, auk=0, ATS=0, ATS_1=0, good=0, a=0, p=0;
    int magic_stulpelis=0, magic_eilute=0, magic_istryzaine_1=0, magic_istryzaine_2=0;
    int *rodykle = &s_aukstis, *rodykle_1 = &s_plotis;
    time_t kint;
    time(&kint);
    srand(kint);
    printf("****MAGISKU KVADRATU RADEJAS****\n");
    printf("\n");
    printf("\n");
    printf("Iveskite koki noresite tureti dydzio staciakampi \n");
    printf("Aukstis: ");
    scanf("%d", &*rodykle);
    printf("Plotis: ");
    scanf("%d", &*rodykle_1);
    int staciakampis[s_aukstis][s_plotis];
    for(i=0; i<=s_aukstis-1;i++)              ///// surasomi skaiciai i musu staciakampi ir jis ispausdina /////
    {
       for(j=0;j<=s_plotis-1;j++)
       {
        if (j==0)
            printf("\n");
          staciakampis[i][j] = rand()%10;
          printf("%d | ", staciakampis[i][j]);

       }
    }                                                   ///// *************** /////
    printf("\n");
    printf("\n");
    printf("Iveskite koki noresite tureti MAGISKO KVADRATO dydi \n");
    printf("Kvadrato dydis: ");
    while (good<1)                                 ///// Uztikrinam kad MAGISKAS KVADRATAS nebutu didesnis uz musu staciakampi /////
    {
    scanf("%d", &k);
    if (k>s_aukstis || k>s_plotis || k<=1)
    {
        if (k<=1)
        printf("MAGISKAS KVADRATAS per mazas iveskite is naujo: \n");
        else
        printf("MAGISKAS KVADRATAS per didelis iveskite is naujo: \n");
    }
    else
        good=1;
    }                                                                               ///// *************** /////
    int kvadratas[k][k], magiska_suma[k*k];
    for(i=0;i<k;i++)                                                ///// Naujas sukurtas masyvas(kvadratas) vaiksto po musu /////
    {                                                                     ///// seniau sukurta masyva(staciakampis) /////
    if (j==k)
        printf("\n");
       for(j=0;j<k;j++)
       {
        kvadratas[i][j] = staciakampis[i+auk][j+plo];
        printf("%d | ", kvadratas[i][j]);
        magic_stulpelis += kvadratas[i][j];
        if (j==p)
            magic_istryzaine_1 += kvadratas[i][j];
        if (j==(k-1)-p)
            magic_istryzaine_2 += kvadratas[i][j];
       }
       magiska_suma[a] = magic_stulpelis;
       a += 1;
       if (i==k-1)
       {
            magiska_suma[a] = magic_istryzaine_1;
            a += 1;
            magiska_suma[a] = magic_istryzaine_2;
            a += 1;
       }
       magic_stulpelis = 0;
       p += 1;
       if (i==k-1)                                                              ///// Grazina skaicius i pradniu parametru kaip i, j, sum /////
       {
           for(i=0;i<k;i++)
           {
               for(j=0;j<k;j++)
                {
                    magic_eilute += kvadratas[j][i];
                }
                magiska_suma[a] = magic_eilute;
                a += 1;
                magic_eilute = 0;
           }
           for (j=0;j<k*2+2;j++)
           {
                printf("%d , ", magiska_suma[j]);
           }
           for (j=1;j<k*2+2;j++)
            {
                if (magiska_suma[0]!=magiska_suma[j])
                {
                    printf("ne magiskas kvadratas");
                    j=k*2+3;
                }
                else
                    ATS+=1;
            }
            if (ATS == k*2+1)
            {
                printf("magiskas kvadratas !!!!!!!!!!");
                ATS_1 = SUM(ATS_1);
            }
            printf(" \n");
            printf(" \n");
            if (plo<s_plotis-k)                                ///// Parindinis vaiksiotojas kuris kelnoja stulpelius ir eiluter/////
                plo += 1;
            else
            {
                auk += 1;
                plo = 0;
            }                                                                       ///// *************** /////
            magic_istryzaine_1 = 0;
            magic_istryzaine_2 = 0;
            p = 0;
            a = 0;
            i = -1;
            j = -1;
            ATS = 0;
            if (auk==s_aukstis-(k-1))
                i=k+1;
       }
    }                                                                                    ///// *************** /////
    printf("Visame staciakampyje(%dx%d) MAGISKU KVADRATU yra: %d", s_aukstis, s_plotis, ATS_1);
    return 0;
}
