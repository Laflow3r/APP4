/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotheque_images.h"
#include "AutoValidation.h"

int main()
{
	//AUTOVALIDE
	AutoValidation(); 
	//test_pgm_lire(); 
	//test_pgm_ecrire(); 
	//test_pgm_copier(); 
	//test_pgm_couleur_preponderante(); 
	//test_pgm_creer_histogramme(); 
	//test_pgm_eclaircir_noircir(); 
	//test_pgm_creer_negatif(); 
	//test_pgm_extraire(); 
	//test_pgm_sont_identiques(); 
	//test_pgm_pivoter90(); 
	//test_ppm_lire(); 
	//test_ppm_ecrire(); 
	//test_ppm_copier(); 
	//test_ppm_sont_identiques(); 
	//test_ppm_pivoter90(); 
	 
	
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
    
    // printf("youhou \n");

    //int imagePGM[MAX_HAUTEUR][MAX_LARGEUR];
    //struct RGB imagePPM[MAX_HAUTEUR][MAX_LARGEUR];
    //int height = 0;
    //int width = 0;
    //int max = 0;
    //struct MetaData m_metaData;

    //int imagePGM2[MAX_HAUTEUR][MAX_LARGEUR];
    //struct RGB imagePPM2[MAX_HAUTEUR][MAX_LARGEUR];
    //int height2 = 0;
    //int width2 = 0;
    //int max2;
    //struct MetaData m_metaData2;

    //pgm_lire("Sherbrooke_Frontenac_nuit.pgm", imagePGM, &height, &width, &max, &m_metaData);
    //pgm_lire("example5000-grey.pgm", imagePGM, &height, &width, &max, &m_metaData);
    //ppm_lire("Sherbrooke_Frontenac_nuit.ppm", imagePPM, &height, &width, &max, &m_metaData);
    //pgm_lire("Sherbrooke_Frontenac_nuit.pgm", imagePGM, &height, &width, &max, &m_metaData);
    //pgm_lire("APP4_P2_TEST.txt", imagePGM, &height, &width, &max, &m_metaData);

    //printf("image:  \n");

    //printf("height = '%d'\n", height);
    //printf("width = '%d'\n", width);
    //printf("max = '%d'\n", max);

    // printf("auteur = '%s'\n", m_metaData.auteur);
    // printf("date = '%s'\n", m_metaData.dateCreation);
    // printf("lieu = '%s'\n", m_metaData.lieuCreation);

    
    // int histogramme[MAX_HAUTEUR * MAX_LARGEUR] = {0};
    //afficher_image_PGM(imagePGM, height, width);
    //afficher_image_PPM(imagePPM, height, width);
    //printf("eclaircir = %d \n",pgm_eclaircir_noircir(imagePGM, height, width, max, -100));
    //printf("eclaircir = %d \n",pgm_eclaircir_noircir(imagePGM, height, width, max, 100));
    //printf("pgm_copier = %d \n",pgm_copier(imagePGM, height, width,imagePGM2,&height2, &width2));
    //printf("pgm_pivoter90 = %d \n",pgm_pivoter90(imagePGM2, &height2, &width2, 0));
    //printf("pgm_creer_negatif = %d \n",pgm_creer_negatif(imagePGM2, height2, width2,max));
    //printf("ppm_pivoter90 = %d \n",ppm_pivoter90(imagePPM, &height, &width, 0));
    //printf("ppm_copier = %d \n",ppm_copier(imagePPM, height, width,imagePPM2, &height2, &width2));


    //afficher_image_PGM(imagePGM2, height2, width2);
    //printf("pgm_extraire = %d \n",pgm_extraire(imagePGM,0,0,3,0, &height, &width));
    //printf("pgm_sont_identiques = %d \n",pgm_sont_identiques(imagePGM, height, width,imagePGM2,height2, width2));
    //afficher_image_PGM(imagePGM, height, width);

    //pgm_ecrire("ECRIRE_APP4.pgm",imagePGM,height,width,max,m_metaData);
    //printf("ppm_ecrire = %d \n", ppm_ecrire("ppm_pivoter90.ppm",imagePPM, height, width, max, m_metaData));

    return 0;
}


