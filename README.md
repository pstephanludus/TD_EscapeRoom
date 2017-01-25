# TD_EscapeRoom
Rendu du TD d'Unreal (Escape Rooms)


Enigme 1:
La première énigme consiste à déplacer des objets (ici des tables) placés devant la porte afin qu'elle s'ouvre.
Dans cette même pièce, le joueur est sensé récupérer la combinaison anti-gravité lui permettant une manipulation limitée de la gravité (l'idée de base étant de créer une énigme pour atteindre la combinaison, la porte s'ouvrant une fois celle-ci récupérée.

  Thème de l'escape room
En sortant de la pièce, le joueur découvre un grand terrain. En en faisant le tour, il découvre une fusée lui permettant de quitter l'endroit. La fusée est cependant innateignable en l'état, elle est posée sur une sphère dans les airs. Pour y arriver, le joueur doit passer de pièce en pièce. Les pièces ne sont pas reliées entre elles, et sont disposées de plus en plus haut. le joueur doit se servir de la gravité pour "tomber" (selon son axe de gravité) de pièce en pièce pour au final atteindre la sphère.
Le joueur change son axe de gravité en marchant sur un plan formant un angle inférieur à 90° avec le plan actuel (il ne peut par exemple pas monter directement sur un mur)

Enigme 2: (non implémenté)
En parcourant le terrain, le joueur découvre une structure style half-pipe sur laquelle un chemin est tracé, et indique au joueur qu'il peut changer la gravité en se déplacant sur ce genre de surfaces en arc de cercle. Le joueur doit trouver un cube où une partie est manquante, un quarter-pipe en quelque sorte. Il doit déplacer ce bloc contre un mur extérieur de la première salle, afin de pouvoir se déplacer sur le mur. Depuis ce mur, il peut se laisser tomber pour atteindre la structure sphérique qui est la première salle du chemin de salles vers la "planète" avec la fusée.

Enimge 3:
Lorsque le joueur atteint la structure cylindrique, il doit trouver un moyen d'atteindre la prochaine salle. Il ne peut pas changer directement la gravité, il ne peut pas "tomber" vers l'autre salle.
Il doit trouver une ouverture dans le cylindre, et y pénétrer, pour tomber dans un labyrinthe. Dans une version améliorée, le labyrinthe aurait été pourvu de portes ne s'ouvrant que dans un sens (indiqué par une lumière verte d'un côté, "on passe", et rouge de l'autre, "on ne passe pas"), l'idée étant de contraindre le joueur à se repérer  et à planifier sa trajectoire pour atteindre le trou par lequel il est entré.
En "tombant" dans le trou, il atterit sur la prochaine salle




Blueprints utilisés:
 - <bold>SM_Door_1st_Room_Blueprint</bold>: 
    Blueprint de la porte de la première salle, à laquelle un composant OpenDoor_1stRoom est associé. Le code C++ est presque le
    même que celui vu en cours, à la différence où cette fois, il ne faut pas placer des objets pour atteindre un seuil de 
    poids pour ouvrir la porte, mais enlever des objets "encombrant" la porte pour qu'elle s'ouvre si le poids sur le trigger
    est sous un certain seuil (le poids du joueur étant inférieur à ce seuil). En somme, outre la valeur de poids modifiée, le
    seul changement est l'inversion de l'ordre d'appel des méthodes OpenDoor et CloseDoor
 - FirstPersonCharacter_BP: 
    Blueprint du pawn du joueur. Configurations d'une vue FPS classique avec déplacements, sprint, saut et tir implémentés de
    base. Un composant Grabber est ajouté au personnage afin de lui permettre de déplacer les objets en les saisissant.
    L'idée à long terme était de remplacer le tir du fusil par un rayon permettant de déplacer les objets
    
