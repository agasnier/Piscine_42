// TRANSFORMER UN CHIFFRE EN TOUTE LETTRE 123 --> ONE HUNDRED TWENTY THREE


//IDÉE 1 : TRAITER CENTAINE DIZAINE UNITE --> LEN_NB = 10² 
// 
// 1234 -> prendre 1234 / 1000 = 1 on print ONE THOUSAND et gerer le reste
// 234 -> le reste on le gere de la meme maniere donc 234 / 100 = 2 
// on print two hundred et on gere le reste de la meme manière 
// 34 / 10 = 3 donc on print thirty et on gere l'unité 4 
// de cette maniere si il y a un reste et qu'il equivaut a 0 
// il ne sera pas print 2 fois car (234 % 100 != 0) si ya un zero on le gere pas
// EXEMPLE 1200 on gere jusqu'a la centaine et apres on regarde si le reste est 
// différent de 0 si non on le gere pas
//
//
//___________________________________________________________________________
//                                                                           |
// <--------------------------CAS SPECIAUX A GERER-------------------------->|
//___________________________________________________________________________|
//
// 11 = eleven pas ten + one 
// 12 = twelve pas ten + two
// 13 = thirteen pas ten + three same jusqu'a 19
//___________________________________________________________________________
//
// si un chiffre a plus d'un 0 on l'ecris pas 
// 1200 = one thousand two hundred || pas ONE THOUSAND TWO HUNDRED ZERO ZERO 
//___________________________________________________________________________
//                                                                           |
// <-------------------------EXEMPLE D'APPLICATION-------------------------->|
//___________________________________________________________________________|
// 
    int num;
    if (num >= 1000) // pour notre cas oui 1234 est plus grand que 1000
    {
        num / 1000;// pour avoir le ONE // COMME C'EST 1000 ON AJOUTE THOUSAND
        num % 1000;

    }
    if (num >= 100) // après le 1er if on a 234 donc on poursuis de la meme façon
    {
        num / 100;  // on a TWO // HUNDRED
        num % 100; // et le reste 34
    }
    if (num >= 20)
    {
       num / 10;  // le 3 !! attention gardé en tete que a la dizaine on peut mettre directement thirty sans gerer le 3
       num % 10; // le 4 
    }

                    /* RESULTAT ATTENDU : */ 
              ONE THOUSAND TWO HUNDRED THIRTY FOUR
//
//
//_____________________________________________________________________________
//                                                                             |
//        CE QUE L'ALGO EST CENSE FAIRE                                        |
//_____________________________________________________________________________|
//
//                      ======EXEMPLE AVEC 1234=======
//           1. 1234 >= 1000 ? oui 
//           2. 1234 / 1000 = 1  // ALLER CHERCHER 1 PRINT ONE APRES 1000 ET PRINT THOUSAND
//           3. 1234 % 1000  // SI YA UN RESTE LE TRAITER EN APPELANT LA FONCTION RECURSIVE
//           4. 234 >+ 100 oui 
//           5. 234 / 100  = 2 // ALLER CHERCHER 2 LE PRINT TWO ET APRES 100 PRINT HUNDRED
//           6. 234 % 100 != 0  
//           7. 34 >+ 20 oui 
//           8. (34 / 10) * 10 // qui donne 30 on print thirty
//           9. 34 % 10 = 4 // traiter le reste et print four
//
//
//          OUTPUT == one thousand two hundred thirty four
//
//____________________________________________________________________________
//                                                                            |
//                            CODE A ADAPTER                                  |
//____________________________________________________________________________|
//                                                                            |
//                                                                            |
//   FONCTION QUI RECUPERE LA LIGNE DU DICTIONNAIRE                           |
//   FONCTION QUI PRINT LE MOT                                                |
//                                                                            |
     void ft_convert_(int nb)                                               
     { 
           if (nb == 0)
           {
           // print zero
            return;
           }
// gere les millions +
           if (nb >= 1000000)
           {
              ft_convert(nb / 1000000) // convertir le million   
              // print million
              if (nb % 1000000 != 0) // si il y a un reste 
              {
                  ft_convert(nb % 1000000) // convertir le reste
              }
           }
// gere entre 1000 - 999,999            
           if  (nb >= 1000)
           {
               ft_convert(nb / 1000);
               //print thousand         
              if (nb % 1000 != 0) // si il y a un reste
              {
                   ft_convert(nb % 1000) // convertir le reste
              }
           }
//gere entre 100 - 999
           if  (nb >= 100)
           {
               ft_convert(nb / 100);
               //print thousand         
              if (nb % 100 != 0) // si il y a un reste
              {
                  ft_convert(nb % 100)
              }
           }

// gere les dizaine de 20 a 99 car on a des cas speciaux entre 10 et 19

           if (nb >= 20) 
           {
                int dizaine = (nb / 10) * 10; // donne la dizaine sans l'unité 47  = 40 donc fourty 
                // print la dizaine
                if (nb % 10 != 0) // geere le reste si y'en a un 
                {   
                       ft_convert(nb % 10);
                }
           }

// geres les unité et les cas spéciaux de 1 a 19                     
           if (nb > 0)
           {
               // print la bonne ligne correspondant au nb
           }
     }
//                                                                             |
//                                                                             |
//_____________________________________________________________________________|
