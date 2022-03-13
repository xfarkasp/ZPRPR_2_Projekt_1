#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

void v(FILE **Subor,char **NazovPP,char **MenoPP,char **TypPP,char **CasPP,int *DatumPP,int PocetZaznamov) {

    if(*Subor != NULL)
    {
        if(PocetZaznamov != 0)
        {
            printf("num of items: %d\n", PocetZaznamov);
            for (int i = 0; i < 6; ++i) {
                printf("NazovP: %s\n", NazovPP[i]);
                printf("Meno: %s\n",MenoPP[i]);
                printf("Typ: %s\n", TypPP[i]);
                printf("Cas:  %s\n", CasPP[i]);
                printf("datum: %d\n", DatumPP[i]);
                printf("\n");
            }

        }
    }
    if ((*Subor = fopen("OrganizacnePodujatia.txt", "r")) == NULL)
    {
        printf("Neotvoreny subor\n");
        return;
    }


    char ln[1000], NazovP[150], meno[100], typ[2], cas[4], datumStr[8];
            int datum=0;
            while (fgets(ln, 1000, *Subor)){
                 if(ln[0] != '\n'){
                     strcpy(NazovP,ln);
                     fgets(ln, 1000, *Subor);
                     strcpy(meno,ln);
                     fgets(ln, 1000, *Subor);
                     strcpy(typ,ln);
                     fgets(ln, 1000, *Subor);
                     strcpy(cas,ln);
                     fgets(ln, 1000, *Subor);
                     strcpy(datumStr,ln);
                     datum=atoi(datumStr);
                    if(ln[0] == '\n'){
                        break;
                    }
               printf("Nazov prispevku: %s", NazovP);
               printf("Mena autorov: %s", meno);
               printf("Typ prezentovania: %s", typ);
               printf("Cas prezentovania: %s", cas);
               printf("Datum: %ld\n\n", datum);
                }
            }
    printf("\n");
    fseek(*Subor, 0, SEEK_SET);
}
void n(FILE *Subor,char ***NazovPP,char ***MenoPP,char ***TypPP,char ***CasPP,int **date,int *PocetZaznamov) {

    if(Subor == NULL)
    {
        printf("Neotvoreny subor\n");

    }
    else{
        //dealokacii poly, ak uz boli alokovane
        if(*NazovPP != NULL) {
            for (int i = 0; i < *PocetZaznamov; i++) {
                free((*NazovPP)[i]);
                (*NazovPP)[i] = NULL;
            }

            free(*NazovPP);
            *NazovPP = NULL;
        }

        if(*MenoPP != NULL) {
            for (int i = 0; i < *PocetZaznamov; i++) {
                free((*MenoPP)[i]);
                (*MenoPP)[i] = NULL;
            }

            free(*MenoPP);
            *MenoPP = NULL;
        }

        if(*TypPP != NULL) {
            for (int i = 0; i < *PocetZaznamov; i++) {
                free((*TypPP)[i]);
                (*TypPP)[i] = NULL;
            }

            free(*TypPP);
            *TypPP = NULL;
        }

        if(*CasPP != NULL) {
            for (int i = 0; i < *PocetZaznamov; i++) {
                free((*CasPP)[i]);
                (*CasPP)[i] = NULL;
            }

            free(*CasPP);
            *CasPP = NULL;
        }

        if(*date != NULL) {
            free(*date);
            *date = NULL;
        }

        *PocetZaznamov=0;
        int pocetRiadkov = 0;
        char ln[200];
        fseek(Subor, 0, SEEK_SET);
        while( fgets(ln, sizeof(ln), Subor) != NULL)
        {
            if(pocetRiadkov % 6 == 0)
                *PocetZaznamov += 1;

            pocetRiadkov++;
        }
        fseek(Subor, 0, SEEK_SET);

       //alokacia poli
        *NazovPP = (char**)malloc(*PocetZaznamov * sizeof(char*));

        for(int i = 0; i < *PocetZaznamov; i++)
            (*NazovPP)[i] =(char*) malloc(150 * sizeof(char));


        *MenoPP = (char**)malloc(*PocetZaznamov * sizeof(char*));

        for(int i = 0; i < *PocetZaznamov; i++)
            (*MenoPP)[i] =(char*) malloc(100 * sizeof(char));

        *TypPP = (char**)malloc(*PocetZaznamov * sizeof(char*));

        for(int i = 0; i < *PocetZaznamov; i++)
            (*TypPP)[i] =(char*) malloc(2 * sizeof(char));

        *CasPP = (char**)malloc(*PocetZaznamov * sizeof(char*));

        for(int i = 0; i < *PocetZaznamov; i++)
            (*CasPP)[i] =(char*) malloc(4* sizeof(char));


        *date = (int*)malloc(*PocetZaznamov * sizeof(int));
        //naplnenie poli zo suboru
        char c;
        for (int i = 0; i < *PocetZaznamov; ++i) {
            //odstranenie prazdnych riadkov
            c = getc(Subor);
            if(c == '\n'){
                getc(Subor);
            }
            //ziskanie noveho riadku zo suboru do stringu ln
            fgets(ln, sizeof(ln), Subor);
            //odstranenie znaku \n (ukoncovaci znak riadku) a vymena za \0(ukoncovaci znak stringu)
            if(ln[strlen(ln)-1] == '\n'){
                ln[strlen(ln)-1] = '\0';
            }
            strcpy((*NazovPP)[i],ln);

            fgets(ln, sizeof(ln), Subor);
            if(ln[strlen(ln)-1] == '\n'){
                ln[strlen(ln)-1] = '\0';
            }
            strcpy((*MenoPP)[i],ln);

            fgets(ln, sizeof(ln), Subor);
            if(ln[strlen(ln)-1] == '\n')
                ln[strlen(ln)-1] = '\0';
            strcpy((*TypPP)[i],ln);

            fgets(ln, sizeof(ln), Subor);
            if(ln[strlen(ln)-1] == '\n')
                ln[strlen(ln)-1] = '\0';
            strcpy((*CasPP)[i],ln);

            fscanf(Subor,"%d",&(*date)[i]);

        }
        printf("Nacitane data\n");
    }
}
void s(FILE **Subor,char **NazovPP,char **MenoPP,char **TypPP,char **CasPP,int *DatumPP,int PocetZaznamov) {
    int vstupDatum=0;
    char vstupTyp[2];
    int Zhoda=0;
    scanf("%d %s", &vstupDatum, &vstupTyp);
    if(PocetZaznamov != 0){
            for (int i = 0; i < 6; ++i) {
                if(vstupDatum==DatumPP[i]&&strcasecmp(vstupTyp,TypPP[i])){
                    char string[100];
                    memset(string, 0, sizeof(string));
                    int pomoc=0;
                    if(strchr(MenoPP[i], '#')!=NULL){
                        pomoc=strlen(MenoPP[i])-strlen(strchr(MenoPP[i], '#'));
                        strncpy(string, MenoPP[i], pomoc);
                    }
                    else{
                        strcpy(string, MenoPP[i]);
                    }
                    printf("%s %*s %*s\n", CasPP[i], 2+strlen(string),string, 20+(strlen(NazovPP[i])-strlen(string)), NazovPP[i]);
                    Zhoda++;
            }
        }
        if(Zhoda==0){
            printf("Pre dany vstup neexistuju zaznamy\n");
        }
    }
    else{
       printf("Polia nie su vytvorene\n");
    }
}

int main() {

    char **nazovP = NULL;
    char **meno = NULL;
    char **typ = NULL;
    char **cas = NULL;
    int *datum = NULL;
    int pocetzaznamov = 0;
    char volba=' ';
    FILE *subor = NULL;


    while(1){

        scanf("%c",&volba);
        if(volba=='v'){
            printf("Volba V\n");
            v(&subor,nazovP,meno,typ,cas,datum,pocetzaznamov);
        }
        else if(volba=='n'){
            printf("Volba N\n");
            n(subor,&nazovP,&meno,&typ,&cas,&datum,&pocetzaznamov);
        }
         else if(volba=='s'){
            printf("Volba s\n");
            s(&subor,nazovP,meno,typ,cas,datum,pocetzaznamov);
        }
        else if(volba=='k'){
            printf("Volba k\n");
            // zatvorenie subora
            if(subor != NULL){
                fclose(subor);
                subor=NULL;
            }
            //uvolnenie a dealokacia dyn. pola na nazov prednasky
            if(nazovP != NULL) {
                for (int i = 0; i < pocetzaznamov; i++) {
                    free(nazovP[i]);
                    nazovP[i] = NULL;
                }
                free(nazovP);
                nazovP = NULL;
                }
                //uvolnenie a dealokacia dyn. pola na nazov autra/rov
                if(meno != NULL) {
                    for (int i = 0; i < pocetzaznamov; i++) {
                        free(meno[i]);
                        meno[i] = NULL;
                    }
                    free(meno);
                    meno = NULL;
                }
                //uvolnenie a dealokacia dyn. pola na kod prednasky
                if(typ != NULL) {
                    for (int i = 0; i < pocetzaznamov; i++) {
                        free(typ[i]);
                        typ[i] = NULL;
                    }
                    free(typ);
                    typ = NULL;
                }
                //uvolnenie a dealokacia dyn. pola na cas prednasky
                if(cas != NULL) {
                    for (int i = 0; i < pocetzaznamov; i++) {
                        free(cas[i]);
                        cas[i] = NULL;
                    }
                    free(cas);
                    cas = NULL;

                }
                //uvolnenie a dealokacia dyn. pola na datum prednasky
                if(datum != NULL) {
                    free(datum);
                    datum=NULL;
                }
                //ukoncenie nekonecneho cyklu a posunute programu na return 0, ktory ho ukonci
                break;
        }
    }
    return 0;
}
