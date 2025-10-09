#ifndef SHOP_H
#define SHOP_H

int find_product_index(const char *id);
int already_added(FILE *file, const char *id);
int search_in_file(const char *filename, const char *fromkeyword);
void Delete();
void run();
void E2E_test();
#endif