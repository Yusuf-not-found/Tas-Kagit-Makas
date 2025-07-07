#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <direct.h>

void girisi_temizle()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    system("cls");

    char isim[50], dosya_adi[100] = "skorlar\\", secim, dosyadan_okuma[20];
    int ben = 0, bilgisayar = 0, yapay_zeka;
    int oyuncu, bot, satir_sayac;

    printf("Ismini gir oyuncu : ");
    scanf("%s", isim);
    mkdir("skorlar");
    FILE *skor;
    strcat(dosya_adi, isim);
    strcat(dosya_adi, "_skor.txt");

    srand(time(0));
    printf("\t\tTAS KAGIT MAKAS\n\n");
    printf("!!! KURALLAR !!!\n\n1 : Tas makasi yener.\n2 : Makas kagiti yener.\n3 : Kagit tasi yener.\n\n");
    printf("Her el 3 'de biter ve 1 puan degerindedir.\n");

    char basla;
    do
    {
        printf("Baslamak icin \"ENTER\" 'a bas ...");

        basla = getchar();
        girisi_temizle();
        if (basla == '\n')
        {
            system("cls");
        }
        else
        {
            system("cls");
            printf("Oyuna donmek icin \"1\" 'e \nOyundan ayrilmak icin herhangi bir tusa basin\n : ");
            basla = getchar();
            girisi_temizle();

            if (basla == '1')
            {
                system("cls");
            }
            else
            {
                return 0;
            }
        }
    } while (basla != '\n');

    satir_sayac = 0;
    skor = fopen(dosya_adi, "r");
    if (skor == NULL)
    {
        oyuncu = 0;
        bot = 0;
    }
    else
    {
        while (!(feof(skor)))
        {
            fgets(dosyadan_okuma, sizeof(dosyadan_okuma), skor);
            satir_sayac++;
        }
        fclose(skor);
        skor = fopen(dosya_adi, "r");
        for (int i = 0; i < satir_sayac - 3; i++)
        {
            fgets(dosyadan_okuma, sizeof(dosyadan_okuma), skor);
        }
        if ((sscanf(dosyadan_okuma, "%d : %d\n", &oyuncu, &bot)) != 2)
        {
            printf("Skor okunamadi \n");
        }
        fclose(skor);
    }

    while (!(ben == 3 || bilgisayar == 3))
    {

        satir_sayac = 0;
        skor = fopen(dosya_adi, "a");
        if (skor == NULL)
        {
            printf("Kayit dosyasi acilmadi !\n");
            return 0;
        }

        yapay_zeka = rand() % 3 + 1;
        printf("\nTas secmek icin   : T\nKagit secmek icin : K\nMakas secmek icin : M\n\nSecimin : ");

        secim = getchar();
        girisi_temizle();
        if (secim == 't' || secim == 'T')
        {
            printf("Tas VS ");
            switch (yapay_zeka)
            {
            case 1:
                printf("Tas");
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 2:
                printf("Kagit");
                bilgisayar++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 3:
                printf("Makas");
                ben++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            }
        }
        else if (secim == 'k' || secim == 'K')
        {
            printf("Kagit VS ");
            switch (yapay_zeka)
            {
            case 1:
                printf("Tas");
                ben++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 2:
                printf("Kagit");
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 3:
                printf("Makas");
                bilgisayar++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            }
        }
        else if (secim == 'm' || secim == 'M')
        {
            printf("Makas VS ");
            switch (yapay_zeka)
            {
            case 1:
                printf("Tas");
                bilgisayar++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 2:
                printf("Kagit");
                ben++;
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            case 3:
                printf("Makas");
                printf("\n%s : %d\tBilgisayar : %d\n==================================\n\n", isim, ben, bilgisayar);
                break;
            }
        }
        else
        {
            system("cls");
            printf("Bir tusa basmayi beceremedin xD\n\n");
        }

        if (ben == 3)
        {
            printf("Kazanan : %s\n", isim);
            oyuncu++;
        }
        else if (bilgisayar == 3)
        {
            printf("kazanan : Bilgisayar\n");
            bot++;
        }

        if (ben == 3 || bilgisayar == 3)
        {

            fprintf(skor, "%s : %d\tBilgisayar : %d\n", isim, ben, bilgisayar);
            fprintf(skor, "%d : %d\n====================================\n", oyuncu, bot);

            fclose(skor);
            skor = fopen(dosya_adi, "r");
            while (!(feof(skor)))
            {
                fgets(dosyadan_okuma, sizeof(dosyadan_okuma), skor);
                satir_sayac++;
            }
            fclose(skor);
            skor = fopen(dosya_adi, "r");
            for (int i = 0; i < satir_sayac - 3; i++)
            {
                fgets(dosyadan_okuma, sizeof(dosyadan_okuma), skor);
            }
            printf("%s", dosyadan_okuma);
            fclose(skor);

            printf("Tekrar oynamak ister misin ( E / H )\nTercihin nedir ? ");
            secim = getchar();

            girisi_temizle();
            if (secim == 'e' || secim == 'E')
            {
                ben = 0;
                bilgisayar = 0;
                system("cls");
            }
            else if (secim == 'h' || secim == 'H')
            {
                printf("Elbet geri geleceksin ...\n");
            }
            else
            {
                printf("Belirsizlikler beraberinde vedalari getirir :/\n");
            }
        }
    }

    printf("Ayrilmak icin herhangi bir tusa basin ... ");
    girisi_temizle();
    return 0;
}