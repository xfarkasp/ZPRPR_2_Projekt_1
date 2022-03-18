#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

void v(FILE **Subor,char **NazovPP,char **MenoPP,char **TypPP,char **CasPP,int *DatumPP,int PocetZaznamov) {

    if(*Subor != NULL)
    {
        if(PocetZaznamov != 0)
        {
            for (int i = 0; i < PocetZaznamov; ++i) {
                    printf("pocet zaznamov: %d\n", PocetZaznamov);
                printf("Nazov prispevku: %s\n", NazovPP[i]);
                printf("Mena autorov: %s\n",MenoPP[i]);
                printf("Typ prezentovania: %s\n", TypPP[i]);
                printf("Cas prezentovania:  %s\n", CasPP[i]);
                printf("Datum: %d\n", DatumPP[i]);
                //printf("Mena autorov: %s\n",MenoPP[i]);
                printf("\n");
            }
        }
        else{
            char ln[1000], NazovP[150], meno[100], typ[50], cas[50], datumStr[8];
            int datum=0;
            char c;
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

               printf("Nazov prispevku: %s", NazovP);
               printf("Mena autorov: %s", meno);
               printf("Typ prezentovania: %s", typ);
               printf("Cas prezentovania: %s", cas);
               printf("Datum: %ld\n\n", datum);
                }
            }
    fseek(*Subor, 0, SEEK_SET);

        }
    }
    else{
            printf("subor este nebol otvoreny\n");
        if ((*Subor = fopen("OrganizacnePodujatia.txt", "r")) == NULL)
        {
            printf("Neotvoreny subor\n");
        }
        else{
            printf("subor sa otvoril, vypis zo suboru\n");
            char ln[1000], NazovP[150], meno[100], typ[100], cas[100], datumStr[8];
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
            fseek(*Subor, 0, SEEK_SET);
        }
    }
}
void n(FILE *Subor,char ***NazovPP,char ***MenoPP,char ***TypPP,char ***CasPP,int **DatumPP,int *PocetZaznamov) {

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

        if(*DatumPP != NULL) {
            free(*DatumPP);
            *DatumPP = NULL;
        }

        *PocetZaznamov=0;
        int pocetRiadkov = 0;
        char ln[200];
        fseek(Subor, 0, SEEK_SET);
        while( fgets(ln, sizeof(ln), Subor) != NULL)
        {
            if(pocetRiadkov % 6 == 0){
                *PocetZaznamov += 1;
            }
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


        *DatumPP = (int*)malloc(*PocetZaznamov * sizeof(int));
        //naplnenie poli zo suboru
        char c;
        for (int i = 0; i < *PocetZaznamov; ++i) {
            //odstranenie prazdnych riadkov

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

            fscanf(Subor,"%d",&(*DatumPP)[i]);

            c = getc(Subor);
            if(c == '\n'){
                getc(Subor);
            }
        }
        printf("Nacitane data\n");
    }
}
void s(FILE **Subor,char **NazovPP,char **MenoPP,char **TypPP,char **CasPP,int *DatumPP,int *PocetZaznamov) {
    char vstupTyp[2]=" ";
    int Zhoda=0;
    int sDatum=0;
    scanf("%d %s", &sDatum, &vstupTyp);
    if(vstupTyp[strlen(vstupTyp)-1] == '\n'){
                vstupTyp[strlen(vstupTyp)-1] = '\0';
            }
    if(PocetZaznamov != 0){
            for (int i = 0; i < 6; ++i) {
                //printf("vstup typ %s == TypPP %s hodnota porovnania str=%d\n", vstupTyp, TypPP[i], strcmp(vstupTyp,TypPP[i]));
                if(strcmp(TypPP[i], vstupTyp)==0 && sDatum==DatumPP[i]){
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
void p(FILE *Subor,char ***NazovPP,char **MenoPP,char ***TypPP,char ***CasPP,int **DatumPP,int *PocetZaznamov){
    int string[100];
    *PocetZaznamov+=1;
    printf("%d\n", *PocetZaznamov);

    *DatumPP= realloc(*DatumPP ,*PocetZaznamov * sizeof(int));

    MenoPP =(char**)realloc(MenoPP, *PocetZaznamov * sizeof(char*));
    (MenoPP)[*PocetZaznamov-1] =(char*) malloc(100 * sizeof(char));

    scanf("%d",&(*DatumPP)[*PocetZaznamov-1]);
    scanf("%s", &string);
    if(string[strlen(string)-1] == '\n'){
                string[strlen(string)-1] = '\0';
            }
    strcpy((MenoPP)[*PocetZaznamov-1], string);
    printf("pole stringov realloc: %s\n", (MenoPP)[*PocetZaznamov-1]);


}
void h(char **TypPP,char **CasPP, int PocetZaznamov){

    if(PocetZaznamov != 0){
            int Zhoda=0;
            int intCas=8;
            int casZaznam=0;
            int casOd=800;
            int casDo=959;
            int Typ[4];
            for(int i=0; i<4;i++){
                Typ[i]=0;
            }
            printf("  hodina             UP       UD       PP       PD\n");

            for (int i = 9; i < 15 ; ++i) {

                if(i>9)
                    printf("%d:00 - %d:59:", casOd/100, casDo/100);
                else
                    printf("0%d:00 - 0%d:59:", casOd/100, casDo/100);

                intCas++;
                for(int j=0; j<PocetZaznamov; j++){
                    casZaznam=atoi(CasPP[j]);
                    if(casOd<=casZaznam&&casZaznam<=casDo){

                            if(strcasecmp(TypPP[j], "UP")==0){
                                Typ[0]++;
                            }
                            else if(strcasecmp(TypPP[j], "UD")==0){
                                Typ[1]++;
                            }
                            else if(strcasecmp(TypPP[j], "PP")==0){
                                Typ[2]++;
                            }
                            else if(strcasecmp(TypPP[j], "PD")==0){
                                Typ[3]++;
                            }
                    }
                }
                for(int i=0; i<4;i++){
                    printf("        %d", Typ[i]);
                    Typ[i]=0;
                }
                printf("\n");

                casOd+=200;
                casDo+=200;
        }
    }
    else{
       printf("Polia nie su vytvorene\n");
    }
}
void o(FILE **Subor,char **NazovPP,char **MenoPP,char **TypPP,char **CasPP,int *DatumPP,int PocetZaznamov){
    int Zhoda=0;
    int sDatum=0;
    int *UPUD=NULL;
    int *UPUDZoradene=NULL;
    int *PPPD=NULL;
    int *PPPDZoradene=NULL;
    int Upi=0;
    int Ppi=0;

    UPUD = (int*)malloc(PocetZaznamov * sizeof(int));
    if(UPUD!=NULL)
    {
        printf("pole UPUD alkovane\n");
    }

    PPPD = (int*)malloc(PocetZaznamov * sizeof(int));
    if(PPPD!=NULL)
    {
        printf("pole PPPD alkovane\n");
    }
    scanf("%d", &sDatum);

    UPUDZoradene = (int*)malloc(Upi * sizeof(int));
        if(UPUDZoradene!=NULL)
        {
            printf("pole UPUDZoradene alkovane\n");
        }
    PPPDZoradene = (int*)malloc(Ppi * sizeof(int));
        if(PPPDZoradene!=NULL)
        {
            printf("pole PPPDZoradene alkovane\n");
        }

    if(PocetZaznamov != 0){
            for (int i = 0; i < PocetZaznamov; ++i) {
                //printf("vstup typ %s == TypPP %s hodnota porovnania str=%d\n", vstupTyp, TypPP[i], strcmp(vstupTyp,TypPP[i]));
                if(sDatum==DatumPP[i]){
                    if(strcasecmp(TypPP[i],"UD")==0||strcasecmp(TypPP[i],"UP")==0){
                        UPUD[Upi]=atoi(CasPP[i]);
                        UPUDZoradene[Upi]=i;
                        Upi++;

                    }
                    else if(strcasecmp(TypPP[i],"PP")==0||strcasecmp(TypPP[i],"PD")==0){
                        PPPD[Ppi]=atoi(CasPP[i]);
                        PPPDZoradene[Ppi]=i;
                        Ppi++;
                    }
                    Zhoda++;
            }
        }
        int zoradenie;

        int temp1=0;
        int temp2=0;
        for(int i=0; i<Upi;i++){
            for(int j=i+1; j<Upi; j++){
                if(UPUD[i]>UPUD[j]){
                    temp1=UPUD[i];
                    UPUD[i]=UPUD[j];
                    UPUD[j]=temp1;

                    temp2=UPUDZoradene[i];
                    UPUDZoradene[i]=UPUDZoradene[j];
                    UPUDZoradene[j]=temp2;
                }
            }
        }
        temp1=0;
        temp2=0;
        for(int i=0; i<Ppi;i++){
            for(int j=i+1; j<Ppi; j++){
                if(PPPD[i]>PPPD[j]){
                    temp1=PPPD[i];
                    UPUD[i]=PPPD[j];
                    UPUD[j]=PPPD;

                    temp2=PPPDZoradene[i];
                    PPPDZoradene[i]=PPPDZoradene[j];
                    PPPDZoradene[j]=temp2;
                }
            }
             printf("zoradena hodnota %d\n", UPUDZoradene[i]);
        }

        for(int i=0; i< Upi; i++){
            int indexik= UPUDZoradene[i];
            printf("%s  %s  %s  %s\n", CasPP[indexik], TypPP[indexik], MenoPP[indexik], NazovPP[indexik]);
        }
        printf("\n");
        for(int i=0; i< Ppi; i++){
            int indexik= PPPDZoradene[i];
            printf("%s  %s  %s  %s\n", CasPP[indexik], TypPP[indexik], MenoPP[indexik], NazovPP[indexik]);
        }

        free(UPUD);
        UPUD=NULL;
        free(PPPD);
        PPPD=NULL;
        free(UPUDZoradene);
        UPUDZoradene=NULL;
        free(PPPDZoradene);
        PPPDZoradene=NULL;
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

        scanf(" %c",&volba);
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
        else if(volba=='p'){
            printf("Volba p\n");
            p(&subor,nazovP,meno,typ,cas,&datum,&pocetzaznamov);
        }
        else if(volba=='h'){
            printf("Volba h\n");
            h(typ,cas,pocetzaznamov);
        }
        else if(volba=='o'){
            printf("Volba o\n");
            o(&subor,nazovP,meno,typ,cas,datum,pocetzaznamov);
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
