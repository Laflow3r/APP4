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
    int height;
    int width;
    int max;
    char rien;
    struct MetaData m_metaData;
    int i = 0, j = 0, x = 0, y = 0;
    int info = 0;
    int A[1000];
    char buff[1024];
    int image[256][256];

    
    char * comment = NULL;
    size_t len = 0;
    size_t read;

    FILE* fpointer;
    fpointer = fopen("APP4_P2_TEST.txt", "r");
    if(!fpointer)
    {
        printf("marche pas");
        fputs("fopen failed! Exiting...\n", stderr);
        //exit(-1); /* Requires `stdlib.h` */
    }

    fscanf(fpointer, "%c", &rien);
    printf("%d", rien);
    if(rien == '#'){
        getline(&comment, &len, fpointer);
        printf("%s", comment);
        fscanf(fpointer, "%c", &rien);
    }else
    {
        printf("fuck");
    }
    

    
/*
    fscanf(fpointer, "%c", &rien);

   
        //pogner la vielle affaire
        //type != 2 && (buff[i-1] != ' ' || 
        printf("rien = #");
        j = 0;
        fscanf(fpointer, "%c", &buff[i]);
        do
        {
            
            if (buff[i] == ';') {
                info++;
                j = 0;
                
            }
            switch (info)
            {
                case 0:
                    m_metaData.auteur[j] = buff[i];
                    printf("auteur = %s", m_metaData.auteur[j]);
                    break;

                case 1:
                    m_metaData.dateCreation[j] = buff[i];
                    printf("auteur = %s", m_metaData.dateCreation[j]);
                    break;

                case 2:
                    m_metaData.lieuCreation[j] = buff[i];
                    printf("auteur = %s", m_metaData.lieuCreation[j]);
                    break;

                default:
                    break;
            }

            j++;
            i++;
            fscanf(fpointer, "%c", &buff[i]);
        }while(buff[i] != 10 || buff[i] != 13 || buff[i] != EOF  );
*/
        //fscanf(fpointer, "%c", &rien);
    
    

    
    fscanf(fpointer, "%d", &type);
    fscanf(fpointer, "%d", &width);
    fscanf(fpointer, "%d", &height);
    fscanf(fpointer, "%d", &max);


    /* int r = width, c = height, count; 
     i = 0;
     j = 0;

  
    int *arr[r]; 
    for (i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count 
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         printf("%d ", arr[i][j]); 
  
    /* Code for further processing and free the  
      dynamically allocated memory */
    

    printf("type = '%d'\n", type);
    printf("width = '%d'\n", width);
    printf("height = '%d'\n", height);
    printf("max = '%d'\n", max);

    /*while(fscanf(fpointer, "%d", &A[i]) != EOF)
        {
            i = i + 1;
        }
    
    for (j = 0; j < i; j++){
        printf("A[%d] = '%d'\n", j, A[j]);
    }
    */


    for(int m = 0; m < height; m++)
    {
        for(int n = 0; n < width; n++)
        {
            fscanf(fpointer, "%d", &image[m][n]);
            printf("[%d][%d] = %d\n", m,n,image[m][n]);
        }
        
    }
    
    fclose(fpointer);

    return 0;
}
