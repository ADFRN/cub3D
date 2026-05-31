# SPRITES

- Pendant le raycast des wall, stocker la distance perpendiculaire de chaque ligne verticale dans un tableau (ou liste chainee) 1D ZBuffer
- Calculer la distance de chaque sprite jusqu'au joueur
- Trier les sprites en fonctions de la distance de chacun. Du + loin au + proche
- Projeter le sprite en 2D sur le plan de camera: Soutraire la position du joueur de la position du sprite, puis multiplier le resultat par l'inverse de la matrice 2x2 de la camera
- Calculer la taille du sprite sur l'ecran en utilisant sa distance perpendiculaire. 
- Dessiner le sprite ligne verticale par ligne verticale. Ne pas dessiner la ligne verticale si la distance est supérieure à la taille du ZBuffer 1D des murs de la ligne actuelle. (pas compris)
- Dessiner la ligne verticale pixel par pixel. Assurez-vous qu'il y a une couleur invisible (par exemple le noir = a ignorer donc devient la couleur "transparente");


sprite_pos_relative_to_player = sprite_pos - player_pos;
