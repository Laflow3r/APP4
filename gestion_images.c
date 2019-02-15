/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    // int lignes1, colonnes1;
    // int lignes2, colonnes2;
    // int maxval;
    // int histogramme[MAX_VALEUR+1];
    // char nom[MAX_CHAINE];
    // struct MetaData metadonnees;

	// int retour;

    // printf("-> Debut!\n");

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
    int type;
    int length;
    int width;
    int max;
    char rien;
    struct MetaData m_metaData;
    int i = 0, j = 0;
    int info = 0;
    int A[1000];
    char buff[1024];

    FILE* fpointer;
    fpointer = fopen("APP4_P2_TEST.txt", "r");
    if(!fpointer)
    {
        fputs("fopen failed! Exiting...\n", stderr);
        //exit(-1); /* Requires `stdlib.h` */
    }

    fscanf(fpointer, "%c", &rien);
    if (rien == '#') {
        //pogner la vielle affaire
        j = 0;
        while(fscanf(fpointer, "%c", &buff[i]) != EOF)
        {
            
            if (buff[i] == ';') {
                info++;
                j = 0;
                
            }
            switch (info)
            {
                case 0:
                    m_metaData.auteur[j] = buff[i];
                    break;

                case 1:
                    m_metaData.dateCreation[j] = buff[i];
                    break;

                case 2:
                    m_metaData.lieuCreation[j] = buff[i];
                    break;

                default:
                    break;
            }

            j++;
            i++;
        }
    }
    
    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", &length);
    fscanf(fpointer, "%d", &width);
    fscanf(fpointer, "%d", &max);


    while(fscanf(fpointer, "%d", &A[i]) != EOF)
    {
        i = i + 1;
    }

    fclose(fpointer);

    printf("auteur = '%d'\n", type);
    printf("type = '%d'\n", type);
    printf("type = '%d'\n", type);
    printf("length = '%d'\n", length);
    printf("width = '%d'\n", width);
    printf("max = '%d'\n", max);

    for (j = 0; j < i; j++){
        printf("A[%d] = '%d'\n", j, A[j]);
    }

    return 0;
}
