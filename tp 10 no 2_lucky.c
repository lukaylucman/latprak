#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node perwira
typedef struct Officer {
    int level;
    char nama[50];
    char pangkat[50];
    char lokasi[50];
    struct Officer *left;
    struct Officer *right;
} Officer;

// Bikin node baru
Officer* createNode(int level, char* nama, char* pangkat, char* lokasi) {
    Officer* baru = (Officer*)malloc(sizeof(Officer));
    baru->level = level;
    strcpy(baru->nama, nama);
    strcpy(baru->pangkat, pangkat);
    strcpy(baru->lokasi, lokasi);
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

// Fungsi insert (dibutuhkan untuk ngebangun tree sebelum traversal)
Officer* rekrut(Officer* root, int level, char* nama, char* pangkat, char* lokasi) {
    if (root == NULL) return createNode(level, nama, pangkat, lokasi);
    
    if (level < root->level) {
        root->left = rekrut(root->left, level, nama, pangkat, lokasi);
    } else if (level > root->level) {
        root->right = rekrut(root->right, level, nama, pangkat, lokasi);
    }
    return root;
}

// 5. Pre-Order (Cetak: Root -> Kiri -> Kanan)
void inspeksiKomando(Officer* root) {
    if (root == NULL) return;
    // Format diubah menggunakan strip sesuai screenshot
    printf("%d - %s (%s)\n", root->level, root->nama, root->pangkat);
    inspeksiKomando(root->left);
    inspeksiKomando(root->right);
}

// 6. In-Order (Cetak: Kiri -> Root -> Kanan)
void laporKekuatan(Officer* root) {
    if (root == NULL) return;
    laporKekuatan(root->left);
    // Format diubah menggunakan strip sesuai screenshot
    printf("%d - %s (%s)\n", root->level, root->nama, root->pangkat);
    laporKekuatan(root->right);
}

// 7. Post-Order (Cetak: Kiri -> Kanan -> Root)
void protokolEvakuasi(Officer* root) {
    if (root == NULL) return;
    protokolEvakuasi(root->left);
    protokolEvakuasi(root->right);
    printf("%d - %s (%s)\n", root->level, root->nama, root->pangkat);
}

int main() {
    Officer* root = NULL;
    int pilihan, level;
    char nama[50], pangkat[50], lokasi[50];

    printf("--- STRATEGI PENYERANGAN MARINE (SOAL 2) ---\n");
    printf("1. Rekrut\n");
    printf("2. Cari (Fokus Soal 1)\n");
    printf("3. Hapus (Fokus Soal 1)\n");
    printf("4. Bersihkan Semua (Fokus Soal 1)\n");
    printf("5. Inspeksi Komando (Pre-Order)\n");
    printf("6. Lapor Kekuatan (In-Order)\n");
    printf("7. Protokol Evakuasi (Post-Order)\n");
    printf("8. Tree View (Fokus Soal 1)\n");
    printf("9. Keluar\n");

    do {
        printf("\nPilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan Level Kekuatan: "); scanf("%d", &level);
                printf("Nama: "); scanf(" %[^\n]", nama);
                printf("Pangkat: "); scanf(" %[^\n]", pangkat);
                printf("Lokasi Tugas: "); scanf(" %[^\n]", lokasi);
                root = rekrut(root, level, nama, pangkat, lokasi);
                break;
            case 2:
            case 3:
            case 4:
            case 8:
                printf("Fitur ini difokuskan pada Soal 1. Silakan gunakan menu 5, 6, dan 7.\n");
                break;
            case 5:
                inspeksiKomando(root);
                break;
            case 6:
                laporKekuatan(root);
                break;
            case 7:
                protokolEvakuasi(root);
                break;
            case 9:
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 9);

    return 0;
}