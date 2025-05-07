struct noeud* create_node(struct noeud* parent) {
    struct noeud* n = malloc(sizeof(struct noeud));
    n->gche = NULL;
    n->droite = NULL;
    n->parent = parent;
    n->val = -1;

    if (parent == NULL)
        n->hauteur = 0;
    else
        n->hauteur = parent->hauteur + 1;

    return n;
}

void remplir_noeud_rec(struct noeud* courant, int prof_actuelle, int prof_cible, int symbole) {
    if (prof_actuelle == prof_cible - 1) {
        courant->gche = create_node(courant);
        courant->gche->val = symbole;
        return;
    }

    if (courant->gche == NULL) {
        courant->gche = create_node(courant);
        remplir_noeud_rec(courant->gche, prof_actuelle + 1, prof_cible, symbole);
    } else if (courant->droite == NULL) {
        courant->droite = create_node(courant);
        remplir_noeud_rec(courant->droite, prof_actuelle + 1, prof_cible, symbole);
    } else {
        // Remonter récursivement vers la racine
        if (courant->parent != NULL)
            remplir_noeud_rec(courant->parent, courant->parent->hauteur, prof_cible, symbole);
        else
            printf("Erreur : arbre saturé ou mal construit.\n");
    }
}

struct noeud* racine = create_node(NULL); // Ne pas oublier !
int j = 0;
for (int i = 1; i <= 16; i++) {
    for (int k = 0; k < Li[i - 1]; k++) {
        remplir_noeud_rec(racine, 0, i, symb[j++]);
    }
}
