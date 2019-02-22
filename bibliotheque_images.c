/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    char auteurTemp[MAX_CHAINE];
    char dateTemp[MAX_CHAINE];
    char lieuTemp[MAX_CHAINE];
    char premierChar;
    int i,j,k,l = 0;
    int info = 0;
    int type;
    int lengthInfo[3] = {0};

    FILE* fpointer;
    fpointer = fopen(nom_fichier, "r");
    if(!fpointer)
    {
        //printf("marche pas");
        return -1;
    }

    
    fscanf(fpointer, "%c", &premierChar);
    // printf("%c \n", premierChar);
    if(premierChar == '#'){

        char c;
        i = 0;
        j = 0;

        while(fscanf(fpointer, "%c", &c) != EOF)
        {
            if (c == '\n') {
                //printf("enter\n");
                lengthInfo[info] = j;
                if(info < 2) return -1;
                break;
            } else
            {
                if (c == ';') {
                   lengthInfo[info] = j;
                    j = 0;
                   info++;
                } else
                {
                    switch (info)
                    {
                        case 0:
                            auteurTemp[j] = c;
                            j++;
                            break;
                        case 1:
                            dateTemp[j] = c;
                            j++;
                            break;
                        case 2:
                            lieuTemp[j] = c;
                            j++;
                            break;
                        default:
                            break;
                    }
                }
                
            }
            
        }

        fscanf(fpointer, "%c", &premierChar);
    }
    if (premierChar != 'P') {
        //printf("premier char = \n", premierChar);
        return -3;
    }

    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", p_colonnes);
    fscanf(fpointer, "%d", p_lignes);
    fscanf(fpointer, "%d", p_maxval);

	if(*p_lignes < 1 || *p_lignes > MAX_HAUTEUR || *p_colonnes < 1 || *p_colonnes > MAX_LARGEUR) return -2;
	
	
    if (type != 2) {
        //printf("ERREUR, type = '%d', attendu = 2\n", type);
        return -3;
    }
    
    // printf("width = '%d'\n", p_lignes);
    // printf("height = '%d'\n", p_colonnes);
    // printf("max = '%d'\n", p_maxval);

    for(int m = 0; m < *p_lignes; m++)
    {
        for(int n = 0; n < *p_colonnes; n++)
        {
            fscanf(fpointer, "%d", &matrice[m][n]);
            //printf("[%d][%d] = %d\n", m,n,matrice[m][n]);
        }
        
    }
    
    //printf("info0: %d ",lengthInfo[0]);
    for(i = 0; i < lengthInfo[0]; i++)
    {
        p_metadonnees->auteur[i] = auteurTemp[i];
        //printf("%c", auteurTemp[i]);
        
    }

    strcpy( p_metadonnees->auteur, auteurTemp);
    strcpy( p_metadonnees->dateCreation, dateTemp);
    strcpy( p_metadonnees->lieuCreation, lieuTemp);

    fclose(fpointer);

    return OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////>

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], 
    int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees)
{
    char auteurTemp[MAX_CHAINE];
    char dateTemp[MAX_CHAINE];
    char lieuTemp[MAX_CHAINE];
    char premierChar;
    int i,j,k,l = 0;//l,m,n,x,y,z = 0;
    int info = 0;
    int type;
    int lengthInfo[3] = {0};

    FILE* fpointer;
    fpointer = fopen(nom_fichier, "r");
    if(!fpointer)
    {
        printf("marche pas");
        return -1;
    }

    
    fscanf(fpointer, "%c", &premierChar);
    // printf("%c \n", premierChar);
    if(premierChar == '#'){

        char c;
        i = 0;
        j = 0;
        while(fscanf(fpointer, "%c", &c) != EOF)
        {
            if (c == '\n') {
                //printf("enter\n");
                lengthInfo[info] = j;
                if(info < 2) return -1;
                break;
            } else
            {
                if (c == ';') {
                   lengthInfo[info] = j;
                    j = 0;
                   info++;
                } else
                {
                    switch (info)
                    {
                        case 0:
                            auteurTemp[j] = c;
                            j++;
                            break;
                        case 1:
                            dateTemp[j] = c;
                            j++;
                            break;
                        case 2:
                            lieuTemp[j] = c;
                            j++;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        fscanf(fpointer, "%c", &premierChar);
    }
    if (premierChar != 'P') {
        return -3;
    }
    
    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", p_colonnes);
    fscanf(fpointer, "%d", p_lignes);
    fscanf(fpointer, "%d", p_maxval);
	
	if(*p_lignes < 1 || *p_lignes > MAX_HAUTEUR || *p_colonnes < 1 || *p_colonnes > MAX_LARGEUR) return -2;    

    if (type != 3) {
        printf("ERREUR, type = '%d', attendu = 3\n", type);
        return -3;
    }
    
    for(int m = 0; m < *p_lignes; m++)
    {
        for(int n = 0; n < *p_colonnes; n++)
        {
            if (fscanf(fpointer, "%d", &matrice[m][n].valeurR) == EOF) {
                printf("erreur format\n");
                return -3;
            }
            if (fscanf(fpointer, "%d", &matrice[m][n].valeurG) == EOF) {
                printf("erreur format\n");
                return -3;
            }
            if (fscanf(fpointer, "%d", &matrice[m][n].valeurB) == EOF) {
                printf("erreur format\n");
                return -3;
            }
        }
    }

    strcpy( p_metadonnees->auteur, auteurTemp);
    strcpy( p_metadonnees->dateCreation, dateTemp);
    strcpy( p_metadonnees->lieuCreation, lieuTemp);
    
    fclose(fpointer);

    return OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
    //erreurs
    if(lignes1 < 1 || lignes1 > MAX_HAUTEUR || colonnes1 < 1 || colonnes1 > MAX_LARGEUR) return -1;

    for(int i = 0; i < lignes1; i++)
    {
        for(int j = 0; j < colonnes1; j++)
        {
            matrice2[i][j] = matrice1[i][j];
        }
    }
    *p_lignes2 = lignes1;
    *p_colonnes2 = colonnes1;

    return OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]){
    if(lignes < 1 || lignes > MAX_HAUTEUR || colonnes < 1 || colonnes > MAX_LARGEUR) return -1;
    int temp;
    for(int i = 0; i < MAX_VALEUR+1; i++)
    {
        histogramme[i] = 0;          
    }
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            temp = matrice[i][j];
            if (temp < 0 || temp > MAX_VALEUR) {
                return -2;
            }
            //printf("temp = %d\n", temp);
            histogramme[temp]++;          
        } 
    }

    return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes){
    if(lignes < 1 || lignes > MAX_HAUTEUR || colonnes < 1 || colonnes > MAX_LARGEUR) return -1;

    int histogramme[MAX_VALEUR+1];
    if(pgm_creer_histogramme(matrice,lignes,colonnes,histogramme) < 0) return -2;
    int max = 0;
    int indexMax = 0;
    int reponsesMultiples = 0;
    for(int i = 0; i < MAX_VALEUR+1; i++)
    {
        //printf("%d ", histogramme[i]);
        if (histogramme[i] > max) {
            max = histogramme[i];
            indexMax = i;
            reponsesMultiples = 0;
        } else if (histogramme[i] == max) {
            reponsesMultiples = 1;
        }       
    }
    if(reponsesMultiples == 1)return -3;
    // ou return n'importe laquelle??
    return indexMax;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur){
    if(lignes < 1 || lignes > MAX_HAUTEUR || colonnes < 1 || colonnes > MAX_LARGEUR) return -1;
    int temp;
    //printf("lignes = %d\n", lignes);
    //printf("colonnes = %d\n", colonnes);

    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            temp = matrice[i][j];
            //printf("maxval = %d\n", maxval);
            //printf("temp = %d\n", temp);
            if(temp > maxval) return -2;
            if(temp < 0) return -2; 
            temp = temp + valeur;
            if(temp > maxval) temp = maxval;
            if(temp < 0) temp = 0;
            matrice[i][j] = temp;         
        } 
    }
    return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval){
    if(lignes < 1 || lignes > MAX_HAUTEUR || colonnes < 1 || colonnes > MAX_LARGEUR) return -1;
    int temp;
    for(int i = 0; i < lignes; i++)
    {
        for(int j = 0; j < colonnes; j++)
        {
            temp = matrice[i][j]; 
            //printf("temp = %d\n", temp);
            temp = maxval - temp;
            if(temp > maxval) return -2;
            if(temp < 0) return -3;
            matrice[i][j] = temp;         
        } 
    }
    return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes){
    // printf("p_lignes = %d \n", *p_lignes);
    // printf("p_colonnes = %d \n", *p_colonnes);
    // printf("lignes1 = %d \n", lignes1);
    // printf("lignes2 = %d \n", lignes2);
    // printf("colonnes1 = %d \n", colonnes1);
    // printf("colonnes2 = %d \n", colonnes2);

    if(*p_lignes < 1 || *p_lignes > MAX_HAUTEUR || *p_colonnes < 1 || *p_colonnes > MAX_LARGEUR) return -1;   
    if(lignes1 < 0 || lignes1 >= *p_lignes || colonnes1 < 0 || colonnes2 >= *p_colonnes) return -1;
    if(lignes2 < lignes1 || lignes2 >= *p_lignes || colonnes2 < colonnes1 || colonnes2 >= *p_colonnes) return -1;

    int matriceTemp[MAX_HAUTEUR][MAX_LARGEUR];
    for(int i = lignes1; i <= lignes2; i++)
    {
        for(int j = colonnes1; j <= colonnes2; j++)
        {
            matriceTemp[i - lignes1][j - colonnes1] = matrice[i][j];
        }
    }
    *p_lignes = lignes2 - lignes1 + 1;
    *p_colonnes = colonnes2 - colonnes1 + 1;
    for(int i = 0; i <= *p_lignes; i++)
    {
        for(int j = 0; j <= *p_colonnes; j++)
        {
            matrice[i][j] = matriceTemp[i][j];
        }   
    }
    
    return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2){
    if(lignes1 != lignes2 || colonnes1 != colonnes2) return -2;
    if(lignes1 < 1 || lignes1 > MAX_HAUTEUR || colonnes1 < 1 || colonnes1 > MAX_LARGEUR) return -1;
    for(int i = 0; i < lignes1; i++)
    {
        for(int j = 0; j < colonnes1; j++)
        {
            if (matrice1[i][j] != matrice2[i][j]) {
               return 1;
            }  
        }
    }
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    FILE * fp;

   fp = fopen (nom_fichier,"w");
    if(!fp)
    {
        return -1;
    }
    fprintf(fp,"#");
    fprintf(fp,metadonnees.auteur);
    fprintf(fp,";");
    fprintf(fp,metadonnees.dateCreation);
    fprintf(fp,";");
    fprintf(fp,metadonnees.lieuCreation);
    fprintf(fp,"\n");
    fprintf(fp,"P2\n%d %d\n%d\n",colonnes,lignes,maxval);

   for(int i = 0; i < lignes; i++)
   {
       for(int j = 0; j < colonnes; j++)
       {
           fprintf(fp,"%d",matrice[i][j]);
           fprintf(fp," ");
       }
     fprintf(fp,"\n");  
   }
    fclose(fp);
    return OK;
}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
    int i_temp, j_temp, temp = 0;
    int matrice_temp[MAX_HAUTEUR][MAX_LARGEUR] = {0};
    if(*p_colonnes < 0 || *p_colonnes > MAX_LARGEUR) return -1;
    if(*p_lignes < 0 || *p_lignes > MAX_HAUTEUR) return -1;

    for(int i = 0; i < *p_colonnes; i++)
    {
        for(int j = 0; j < *p_lignes; j++)
        {
            if(sens == 1){
                j_temp = i;
                i_temp = *p_lignes - j -1;
            }
            if(sens == 0){
                i_temp = j;
                j_temp = *p_colonnes - i- 1;
            }
            //printf("transfering [%d][%d] = %d to matriceTemp[%d][%d] = ",i_temp, j_temp, matrice[i_temp][j_temp], i,j);
            
            matrice_temp[i][j] = matrice[i_temp][j_temp];
            //printf("%d\n", matrice_temp[i][j]);
            //matrice_temp[i_temp][j_temp] = matrice[i][j];
        }
        
    }

    temp = *p_lignes;
    *p_lignes = *p_colonnes;
    *p_colonnes = temp;

    for(int i = 0; i < *p_lignes; i++)
    {
        for(int j = 0; j < *p_colonnes; j++)
        {
            matrice[i][j] = matrice_temp[i][j];
        }
        
    }

    //printf("lignes = %d, colonnes = %d\n", *p_lignes, *p_colonnes);
    return OK;
}

int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees)
{
     FILE * fp;
    
    printf("writing to %s\n", nom_fichier);
    printf("height = '%d'\n", lignes);
    printf("width = '%d'\n", colonnes);
    printf("max = '%d'\n", maxval);
   /* open the file for writing*/
   fp = fopen (nom_fichier,"w");
    if(!fp)
    {
        return -1;
    }

       fprintf(fp,"#");
       fprintf(fp,metadonnees.auteur);
       fprintf(fp,";");
       fprintf(fp,metadonnees.dateCreation);
       fprintf(fp,";");
       fprintf(fp,metadonnees.lieuCreation);
       fprintf(fp,"\n");
   fprintf(fp,"P3\n%d %d\n%d\n",colonnes,lignes,maxval);

   for(int i = 0; i < lignes; i++)
   {
       for(int j = 0; j < colonnes; j++)
       {
           fprintf(fp,"%d",matrice[i][j].valeurR);
           fprintf(fp," ");
           fprintf(fp,"%d",matrice[i][j].valeurG);
           fprintf(fp," ");
           fprintf(fp,"%d",matrice[i][j].valeurB);
           fprintf(fp," ");
       }
     fprintf(fp,"\n");  
   }
    fclose(fp);
    return OK;
}

int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
    int i_temp, j_temp, temp = 0;
    struct RGB matrice_temp[MAX_HAUTEUR][MAX_LARGEUR];
    if(*p_colonnes < 0 || *p_colonnes > MAX_LARGEUR) return -1;
    if(*p_lignes < 0 || *p_lignes > MAX_HAUTEUR) return -1;

    for(int i = 0; i < *p_colonnes; i++)
    {
        for(int j = 0; j < *p_lignes; j++)
        {
            if(sens == 1){
                j_temp = i;
                i_temp = *p_lignes - j -1;
            }
            if(sens == 0){
                i_temp = j;
                j_temp = *p_colonnes - i- 1;
            }
            //printf("transfering [%d][%d] = %d to matriceTemp[%d][%d] = ",i_temp, j_temp, matrice[i_temp][j_temp], i,j);
            
            matrice_temp[i][j] = matrice[i_temp][j_temp];
            //printf("%d\n", matrice_temp[i][j]);
            //matrice_temp[i_temp][j_temp] = matrice[i][j];
        }
        
    }

    temp = *p_lignes;
    *p_lignes = *p_colonnes;
    *p_colonnes = temp;

    for(int i = 0; i < *p_lignes; i++)
    {
        for(int j = 0; j < *p_colonnes; j++)
        {
            matrice[i][j] = matrice_temp[i][j];
        }
        
    }

    //printf("lignes = %d, colonnes = %d\n", *p_lignes, *p_colonnes);
    return OK;
}

int afficher_image_PPM(struct RGB imagePPM[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes){
    printf("-------------------------------------------\n");            
    for(size_t i = 0; i < lignes; i++)
    {
        for(size_t j = 0; j < colonnes; j++)
        {
            printf("[");            
            printf(" %5d ", imagePPM[i][j].valeurR);
            printf(" %5d ", imagePPM[i][j].valeurG);
            printf(" %5d ", imagePPM[i][j].valeurB);
            printf("]");

        }
        printf("\n");
    }
    printf("-------------------------------------------\n");            
	return OK;
}

int afficher_image_PGM(int imagePGM[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes){
    printf("-------------------------------------------\n");            
    for(size_t i = 0; i < lignes; i++)
    {
        for(size_t j = 0; j < colonnes; j++)
        {
            printf(" %5d ", imagePGM[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");            
    return OK;
}

int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
    //erreurs
    if(lignes1 < 1 || lignes1 > MAX_HAUTEUR || colonnes1 < 1 || colonnes1 > MAX_LARGEUR) return -1;

    for(int i = 0; i < lignes1; i++)
    {
        for(int j = 0; j < colonnes1; j++)
        {
            matrice2[i][j].valeurR = matrice1[i][j].valeurR;
            matrice2[i][j].valeurG = matrice1[i][j].valeurG;
            matrice2[i][j].valeurB = matrice1[i][j].valeurB;
        }
    }
    *p_lignes2 = lignes1;
    *p_colonnes2 = colonnes1;

    return OK;
}

int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
    if(lignes1 != lignes2 || colonnes1 != colonnes2) return -2;
    if(lignes1 < 1 || lignes1 > MAX_HAUTEUR || colonnes1 < 1 || colonnes1 > MAX_LARGEUR) return -1;
    for(int i = 0; i < lignes1; i++)
    {
        for(int j = 0; j < colonnes1; j++)
        {
            if (matrice1[i][j].valeurR != matrice2[i][j].valeurR) return 1;
            if (matrice1[i][j].valeurG != matrice2[i][j].valeurG) return 1;
            if (matrice1[i][j].valeurB != matrice2[i][j].valeurB) return 1;
        }
    }
    return OK;
}
