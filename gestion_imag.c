/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque_images.h"

// Valeurs maximales pour les images
#define MAX_LARGEUR 256
#define MAX_HAUTEUR 256
#define MAX_VALEUR 65535

// Valeurs de retour des operations
#define OK 0
#define ERREUR -1
#define ERREUR_FICHIER -1
#define ERREUR_TAILLE -2
#define ERREUR_FORMAT -3
#define IDENTIQUES 0
#define DIFFERENTES 1

// Sens des rotations pour l'operation pivoter90
#define SENS_ANTIHORAIRE 0
#define SENS_HORAIRE 1

// Longueur maximale d'une chaine de caracteres
#define MAX_CHAINE 1024

struct MetaData{
    char auteur[MAX_CHAINE];
    char dateCreation[MAX_CHAINE]; // yyyy-mm-dd 
    char lieuCreation[MAX_CHAINE];
};

struct RGB
{
    int valeurR;
    int valeurG;
    int valeurB;
};

// Operations pour les images noir et blanc
int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees);
int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees);
int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2);
int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]);
int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes);
int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur);
int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval);
int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes);
int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2);
int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens);

// Operations pour les images couleurs
int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees);
int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees);
int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2);
int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2);
int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens);

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    // int lignes1, colonnes1;
    // int lignes2, colonnes2;
    // int maxval;
    // int histogramme[MAX_VALEUR+1];
    // char nom[MAX_CHAINE];
    // struct MetaData metadonnees;

	// int retour;


	// // exemple d'appel de fonction
    // retour = pgm_lire(nom, image1, 
    //                   &lignes1, &colonnes1, 
    //                   &maxval, &metadonnees);

	// // exemple detraitement d'un code de retour (erreur ou reussite)
	// printf("-> Retour: ");
	// if (retour == OK)
	// 	printf("-> OK");
	// else
	// 	printf("-> ERREUR");
	// printf("\n");

	// // autre exemple d'appel de fonction
    // pgm_ecrire(nom, image1, 
    //            lignes1, colonnes1, 
    //            maxval, metadonnees);

    // printf("-> Fin!\n");

    //ppm_lire("APP4_P2_")


    // for(int i = 0; i < 10; i++)
    // {
 
    // }
    
    printf("youhou \n");

    int image[256][256];
    int height = 0;
    int width = 0;
    int max = 0;
    struct MetaData m_metaData;

    pgm_lire("Sherbrooke_Frontenac_nuit.pgm", image, &height, &width, &max, &m_metaData);

    printf("image =  \n");

    printf("height = '%d'\n", height);
    printf("width = '%d'\n", width);
    printf("max = '%d'\n", max);

    printf("auteur = '%s'\n", m_metaData.auteur);
    printf("date = '%s'\n", m_metaData.dateCreation);
    printf("lieu = '%s'\n", m_metaData.lieuCreation);


    for(size_t i = 0; i < height; i++)
    {
        for(size_t j = 0; j < width; j++)
        {
            printf(" %5d ", image[i][j]);
        }
        printf("\n");

    }
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
    char auteurTemp[MAX_CHAINE];
    char dateTemp[MAX_CHAINE];
    char lieuTemp[MAX_CHAINE];
    char premierChar;
    int i,j,k,l,m,n,x,y,z = 0;
    int info = 0;
    int A[1000];
    char buff[1024];
    int type;
    int lengthInfo[3] = {0};
    char * comment = NULL;

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
        i,j = 0;

        while(fscanf(fpointer, "%c", &c) != EOF)
        {
            if (c == '\n') {
                //printf("enter\n");
                lengthInfo[info] = j;
                break;
            } else
            {
                buff[i++] = c;
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
    }else
    {
        //printf("fuck");
    }

    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", p_lignes);
    fscanf(fpointer, "%d", p_colonnes);
    fscanf(fpointer, "%d", p_maxval);

    if (type != 2) {
        printf("ERREUR, type = '%d', attendu = 2\n", type);
        return -1;
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

    //printf("\n");
    //printf("info1: %d ",lengthInfo[1]);
    for(k = 0; k < lengthInfo[1]; k++)
    {
        p_metadonnees->dateCreation[k] = dateTemp[k];
        //printf("%c", dateTemp[k]);
        
    }

    //printf("info2: %d",lengthInfo[2]);
    for(l = 0; l < lengthInfo[2]; l++)
    {
        p_metadonnees->lieuCreation[l] = lieuTemp[l];
        //printf("%c", lieuTemp[l]);
        
    }
    

    fclose(fpointer);

    return OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{

    return OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], 
    int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees)
{
    char auteurTemp[MAX_CHAINE];
    char dateTemp[MAX_CHAINE];
    char lieuTemp[MAX_CHAINE];
    char premierChar;
    int i,j,k,l,m,n,x,y,z = 0;
    int info = 0;
    int A[1000];
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
        i,j = 0;
        while(fscanf(fpointer, "%c", &c) != EOF)
        {
            if (c == '\n') {
                //printf("enter\n");
                lengthInfo[info] = j;
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

    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", p_lignes);
    fscanf(fpointer, "%d", p_colonnes);
    fscanf(fpointer, "%d", p_maxval);

    if (type != 3) {
        printf("ERREUR, type = '%d', attendu = 3\n", type);
        return -1;
    }
    
    for(int m = 0; m < *p_lignes; m++)
    {
        for(int n = 0; n < *p_colonnes; n++)
        {
            fscanf(fpointer, "%d", &matrice[m][n].valeurR);
            fscanf(fpointer, "%d", &matrice[m][n].valeurG);
            fscanf(fpointer, "%d", &matrice[m][n].valeurB);
        }
        
    }
    for(i = 0; i < lengthInfo[0]; i++)
    {
        p_metadonnees->auteur[i] = auteurTemp[i];        
    }
    for(k = 0; k < lengthInfo[1]; k++)
    {
        p_metadonnees->dateCreation[k] = dateTemp[k];        
    }
    for(l = 0; l < lengthInfo[2]; l++)
    {
        p_metadonnees->lieuCreation[l] = lieuTemp[l];
    }
    fclose(fpointer);

    return OK;
}