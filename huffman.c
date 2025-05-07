void remplir_noeud_rec(struct noeud* courant, int prof_actuelle, int prof_cible, int symbole) {
    if (prof_actuelle == prof_cible - 1) {
        // Placer le symbole dans le fils gauche du noeud courant
        courant->gche = create_node();
        courant->gche->val = symbole;
        courant->gche->hauteur = prof_cible;
        courant->gche->parent = courant;
        return;
    }

    if (courant->gche == NULL) {
        courant->gche = create_node();
        courant->gche->parent = courant;
        courant->gche->hauteur = prof_actuelle + 1;
        remplir_noeud_rec(courant->gche, prof_actuelle + 1, prof_cible, symbole);
    } else if (courant->droite == NULL) {
        courant->droite = create_node();
        courant->droite->parent = courant;
        courant->droite->hauteur = prof_actuelle + 1;
        remplir_noeud_rec(courant->droite, prof_actuelle + 1, prof_cible, symbole);
    } else {
        // Aller récursivement plus haut pour trouver une branche disponible
        remplir_noeud_rec(courant->parent, courant->parent->hauteur, prof_cible, symbole);
    }
}

int j = 0;
for (int i = 1; i <= 16; i++) {
    for (int k = 0; k < Li[i - 1]; k++) {
        remplir_noeud_rec(racine, 0, i, symb[j++]);
    }
}
