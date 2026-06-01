# SPRITES

- Pendant le raycast des wall, stocker la distance perpendiculaire de chaque ligne verticale dans un tableau (ou liste chainee) 1D ZBuffer
- Calculer la distance de chaque sprite jusqu'au joueur
- Trier les sprites en fonctions de la distance de chacun. Du + loin au + proche
- Projeter le sprite en 2D sur le plan de camera: Soutraire la position du joueur de la position du sprite, puis multiplier le resultat par l'inverse de la matrice 2x2 de la camera
- Calculer la taille du sprite sur l'ecran en utilisant sa distance perpendiculaire. 
- Dessiner le sprite ligne verticale par ligne verticale. Ne pas dessiner la ligne verticale si la distance est supérieure à la taille du ZBuffer 1D des murs de la ligne actuelle. (pas compris)
- Dessiner la ligne verticale pixel par pixel. Assurez-vous qu'il y a une couleur invisible (par exemple le noir = a ignorer donc devient la couleur "transparente");

sprite_pos_relative_to_player = sprite_pos - player_pos;



F 66,66,66
C 0,0,0

NO           ./map/texture1.xpm
SO ./map/texture2.xpm
EA							./map/texture51.xpm
WE ./map/texture52.xpm


1111111111111111111111111111111111
1000000000000000000110000000000001
1000000000011000001110000000000001
1111111111001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111D11111
1111011111111101110000001N001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
1000000000000000110101000001
110000011101010111110111100011111
11110111 1110101 101111010001
11111111 1111111 111111111111




/////////////////

wallhack

//////////////////




F 66,66,66
C 0,0,0

NO           ./map/texture1.xpm
SO ./map/texture2.xpm
EA							./map/texture51.xpm
WE ./map/texture52.xpm


1111111111111111111111111111111111
1000000000000000000110000000000001
1000000000011000001110000000000001
1111111111001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111D11111
1111011111111101110000001N001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
100000000000000011010100000001
1100000111010101111101111000111110000000000
11110111 1110101 101111010001
11111111 1111111 111111111111
