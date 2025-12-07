# BSQ – Biggest Square

## 🎯 Objectif

Trouver le plus grand carré possible dans une carte contenant des obstacles. Le programme lit une carte depuis un fichier et affiche la carte avec le plus grand carré rempli par le caractère spécifié.

---

## ⚙️ Compilation

Compilation du projet :

```bash
make
```

Nettoyage des fichiers objets :

```bash
make clean
```

Nettoyage complet :

```bash
make fclean
```

Recompilation :

```bash
make re
```

---

## ▶️ Utilisation

Exécuter le programme :

```bash
./bsq <fichier_map>
```

Exemple :

```bash
./bsq maps/map1
```

---

## 📄 Format d’une carte valide

**Première ligne :** nombre_de_lignes + char_vide + char_obstacle + char_plein

**Exemple :**

```
9.ox
...........................
....o......................
..............o............
..o.......................o
.o....................o....
..............o............
......o....................
.....o.........o...........
...........................
```

---

## 🗺 Générer une map automatiquement

Un script `gen` permet de créer rapidement une carte de test.

Usage :

```bash
perl gen 50 100 450 > map.txt
```

* `50` → largeur de la carte (colonnes)
* `100` → hauteur de la carte (lignes)
* `450` → nombre d'obstacles générés
* `> map.txt` → redirection de la sortie dans un fichier

Tu peux ensuite tester le programme dessus :

```bash
./bsq map.txt
```

