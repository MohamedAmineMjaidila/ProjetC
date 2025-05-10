// ProjetC.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Huffman.h"

Node n1, n2, n3, n4, n5, n6, n7;

int main()
{

    std::cout << "Hello World!\n";
    // Test Huffman : 

    int table_size[] = {4,4};
    Hex huffman_lengths[] = { 0x00, 0x01, 0x01, 0x01 };
    Hex2 huffman_symbols[] = { 0x12, 0xAB, 0x20 };
    Node* root = build_huffman_tree(huffman_lengths, huffman_symbols, table_size);
    char code_char[] = "10";
    Code code = { code_char,2 };
    Hex2 symbol = get_symbole_from_code(root, &code);
    printf("Symbole");
    printf("%x",symbol);
    draw_tree_hor(root);

    // Test 
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
